/**
 * @file responder.c
 * @brief Double-sided and single-sided two-way ranging responder
 *
 * This implements the responder logic for both single-sided and
 * double-sided two-way ranging. This will wait for a poll message from
 * the initiator and respond to ranging requests appropriately,
 *
 * @note This code has been modified from its original state to be more
 * understandable and to implement a logic clock for ranging exchanges
 *
 * @author Decawave
 * @author Tom Schmitz \<tschmitz@andrew.cmu.edu\>
 * @copyright Copyright 2018 (c) Decawave Ltd, Dublin, Ireland. All rights
 * reserved.
 */

#include <app_leds.h>
#include <deca_device_api.h>
#include <deca_regs.h>
#include <init_resp_common.h>
#include <port_platform.h>
#include <responder.h>
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>

/**
 * Logger for the responder
 */
LOG_MODULE_REGISTER(responder_logger, CONFIG_RESPONDER_LOG_LEVEL);

/**
 * Semaphore for suspending the responder
 */
K_SEM_DEFINE(k_sus_resp, 0, 1);

/**
 * @brief Frames used in the ranging process
 *
 * The frames used here are Decawave specific ranging frames complying with the
 * IEEE 802.15.4 standard data frame encoding. The frames are the following:
 * - a poll message sent by the initiator to trigger the ranging exchange.
 * - a response message sent by the responder allowing the initiator to go on
 * with the process or to complete the exchange and provide all information
 * needed by the initiator to compute the time-of-flight (distance) estimate.
 * - a final message sent by the initiator to complete the exchange and provide
 * all information needed by the responder to compute the time-of-flight
 * estimate.
 * - a report message sent by the responder telling the initiator what the
 * time-of-flight estimate is.
 * .
 *
 * All messages end with a 2-byte checksum automatically set by DW1000.
 *
 * @{
 */
static uint8 rx_poll_msg[POLL_MSG_LEN] = {0x41, 0x88, 0, 0xCA, 0xDE, 'W',
                                          'A',  0,    0, 0x61, 0,    0};
static uint8 tx_resp_msg[RESP_MSG_LEN] = {
    0x41, 0x88,
     0, 
     0xCA, 0xDE, 
     'V', 'E',
      'W', 'A',
       0x50,
    0,    0,    0, 0, 0,    0,   0,   0,
           0,   0};
static uint8 rx_final_msg[FINAL_MSG_LEN] = {
    0x41, 0x88, 0, 0xCA, 0xDE, 'W', 'A', 'V', 'E', 0x69, 0, 0,
    0,    0,    0, 0,    0,    0,   0,   0,   0,   0,    0, 0};
static uint8 tx_report_msg[REPORT_MSG_LEN] = {
    0x41, 0x88, 0, 0xCA, 0xDE, 'V', 'E', 'W', 'A', 0xE3, 0, 0, 0, 0, 0, 0};

// Cascaded ranging message implementation
#define NUM_USERS 3

static uint8 cc_rx_poll_msg[POLL_MSG_LEN] = {
    0x41, 0x88, //frame control
    0,   // sequence number
    0xCA, 0xDE, // PAN ID
    0, 0, //dest addr (broadcast)
    0, 0, //source addr, not set here for proper comparison in cc_wait_poll_message
    0x61, // function code
    0,    0}; //CRC
static uint8 cc_rx_poll_cmp[POLL_MSG_LEN] = {
    0x41, 0x88, //frame control
    0,   // sequence number
    0xCA, 0xDE, // PAN ID
    0, 0, //dest addr (broadcast)
    0, 0, //source addr, not set here for proper comparison in cc_wait_poll_message
    0x61, // function code
    0,    0}; //CRC

static uint8 cc_tx_resp_msg[RESP_MSG_LEN] = {
    0x41, 0x88, // frame control
     0,   // sequence number
     0xCA, 0xDE, // PAN ID
      'V', 'E', //dest addr -> will be initiator id
       'W', 'A', //source addr -> will be responder id
        0x50, // function code
    0xAA,    0xAA,    0xAA, 0xAA,    
    0xAA,    0xAA,   0xAA,   0xAA,   // empty payload
    0,   0}; //CRC

#define CC_FINAL_MSG_LEN (DW_FRAME_OVERHEAD + TIMESTAMP_OVERHEAD + (NUM_USERS * TIMESTAMP_OVERHEAD) + TIMESTAMP_OVERHEAD)
static uint8 cc_rx_final_msg_n3[CC_FINAL_MSG_LEN] = { // Hard coded for 3 users
    0x41, 0x88, // frame control
    0,  // sequence number
    0xCA, 0xDE, // PAN ID
    0, 0, //dest addr (broadcast)
    'V', 'E', //source addr
    0x69, // function code
    0, 0, 0, 0, //poll_tx_ts
    0, 0, 0, 0,  // resp_rx_ts: 1
    0, 0, 0, 0, // resp_rx_ts: 2
    0, 0, 0, 0, // resp_tx_ts: 3
    0,   0,   0,   0,    // final_tx_ts
    0, 0}; //CRC
static uint8 cc_rx_final_cmp_n3[CC_FINAL_MSG_LEN] = { // Hard coded for 3 users
    0x41, 0x88, // frame control
    0,  // sequence number
    0xCA, 0xDE, // PAN ID
    0, 0, //dest addr (broadcast)
    0, 0, //source addr
    0x69, // function code
    0, 0, 0, 0, //poll_tx_ts
    0, 0, 0, 0,  // resp_rx_ts: 1
    0, 0, 0, 0, // resp_rx_ts: 2
    0, 0, 0, 0, // resp_tx_ts: 3
    0,   0,   0,   0,    // final_tx_ts
    0, 0}; //CRC

static uint8 cc_tx_report_msg[REPORT_MSG_LEN] = {
    0x41, 0x88, // frame control
      0, // sequence number
      0xCA, 0xDE, // PAN ID
       'V', 'E', //dest addr -> will be initiator id
        'W', 'A', //source addr -> will be responder id
         0xE3, // function code
          0, 0, 0, 0, // ToF
           0, 0}; //CRC

/**
 * @}
 */

/**
 * The maximum length of the receive buffer
 */
// #define RX_BUF_LEN MAX(POLL_MSG_LEN, FINAL_MSG_LEN)
#define RX_BUF_LEN MAX(CC_FINAL_MSG_LEN, REPORT_MSG_LEN)

/**
 * The buffer where received data is stored
 */
static uint8 rx_buffer[RX_BUF_LEN];

#if !defined(CONFIG_POLL_RX_TO_RESP_TX_DLY)
/**
 * Delay between frames, in UWB microseconds.
 */
#define POLL_RX_TO_RESP_TX_DLY_UUS 1500
#else
/**
 * Delay between frames, in UWB microseconds.
 */
#define POLL_RX_TO_RESP_TX_DLY_UUS CONFIG_POLL_RX_TO_RESP_TX_DLY
#endif

uint16_t this_id = 0;
/**
 * @brief Sets the source IDs for the messages that the responder sends and the
 * destination ID for the messages the responder receives
 *
 * @param[in] id The ID of the node
 *
 * @return 0 upon success
 * @return -EBUSY if UWB is active
 */
int set_responder_id(uint16_t id) {
    CHECK_UWB_ACTIVE();

    set_dest_id(id, rx_poll_msg);
    set_src_id(id, tx_resp_msg);
    set_dest_id(id, rx_final_msg);
    set_src_id(id, tx_report_msg);

    // Baking ID into cascaded ranging messages
    set_dest_id(id, cc_rx_poll_msg);
    set_src_id(id, cc_tx_resp_msg);
    set_dest_id(id, cc_rx_final_msg_n3);
    set_src_id(id, cc_tx_report_msg);

    this_id = id; // Initialize global this_id variable

    return 0;
}

/**
 * @brief Sets the personal area network (PAN) ID for the responder messages
 *
 * @param[in] id
 * @return 0 upon success
 * @return -EBUSY if UWB is active
 */
int set_responder_pan_id(uint16_t id) {
    CHECK_UWB_ACTIVE();

    set_pan_id(id, rx_poll_msg);
    set_pan_id(id, tx_resp_msg);
    set_pan_id(id, rx_final_msg);
    set_pan_id(id, tx_report_msg);

    set_pan_id(id, cc_rx_poll_msg);
    set_pan_id(id, cc_tx_resp_msg);
    set_pan_id(id, cc_rx_final_msg_n3);
    set_pan_id(id, cc_tx_report_msg);
    return 0;
}

/**
 * @brief Waits for and attempts to receive a poll message from the initiator
 *
 * @param[out] src_id The ID of the initiator node that sent the poll message
 * @param[out] logic_clk The exchange ID of the polling message
 *
 * @return 0 upon success
 * @return -EBUSY if responder gets suspended
 * @return -EBADMSG if there was a reception error
 */
static int wait_poll_message(uint16_t *src_id, uint32_t *logic_clk) {
    uint32 status_reg, frame_len;

    dwt_rxenable(DWT_START_RX_IMMEDIATE);

    UWB_WAIT(
        (status_reg = dwt_read32bitreg(SYS_STATUS_ID)) &
        (SYS_STATUS_RXFCG | SYS_STATUS_ALL_RX_TO | SYS_STATUS_ALL_RX_ERR)) {

        if (k_sem_count_get(&k_sus_resp) == 0) {
            dwt_write32bitreg(SYS_STATUS_ID, SYS_STATUS_ALL_RX_ERR);
            dwt_rxreset();
            LOG_INF("Responder suspended");
            return -EBUSY;
        }
    }

    if (!(status_reg & SYS_STATUS_RXFCG)) {
        dwt_write32bitreg(SYS_STATUS_ID,
                          SYS_STATUS_ALL_RX_TO | SYS_STATUS_ALL_RX_ERR);
        dwt_rxreset();
        return -EBADMSG;
    }

    dwt_write32bitreg(SYS_STATUS_ID, SYS_STATUS_RXFCG);

    frame_len = dwt_read32bitreg(RX_FINFO_ID) & RX_FINFO_RXFL_MASK_1023;
    if (frame_len <= RX_BUFFER_LEN) {
        dwt_readrxdata(rx_buffer, frame_len, 0);
    }

    rx_buffer[SEQ_CNT_OFFSET] = 0;
    *src_id = get_src_id(rx_buffer);
    rx_buffer[SRC_OFFSET] = 0;
    rx_buffer[SRC_OFFSET + 1] = 0;
    GET_EXCHANGE_ID(rx_buffer + LOGIC_CLK_OFFSET, *logic_clk);
    SET_EXCHANGE_ID(rx_buffer + LOGIC_CLK_OFFSET, 0);
    if (!(memcmp(rx_buffer, rx_poll_msg, DW_BASE_LEN) == 0)) {
        return -EBADMSG;
    }

    return 0;
}


/**
 * @brief Sends a response to the initiator assuming double-sided TWR is being
 * used.
 *
 * @param[out] poll_rx_ts The timestamp of when the poll message arrived
 *
 * @return 0 upon success
 * @return -EBADMSG if unable to send response message
 */

static int ds_respond(uint64_t *poll_rx_ts) {
    uint32 resp_tx_time;
    int ret;

    *poll_rx_ts = get_rx_timestamp_u64();

    // compute TX timestamp from the delay from when the initial poll frame was RX
    resp_tx_time =
        (*poll_rx_ts + (POLL_RX_TO_RESP_TX_DLY_UUS * UUS_TO_DWT_TIME)) >> 8;

    dwt_setdelayedtrxtime(resp_tx_time); 

    dwt_writetxdata(sizeof(tx_resp_msg), tx_resp_msg, 0);
    dwt_writetxfctrl(sizeof(tx_resp_msg), 0, 1);

    ret = dwt_starttx(DWT_START_TX_DELAYED | DWT_RESPONSE_EXPECTED);

    if (ret != DWT_SUCCESS) {
        dwt_rxreset();
        return -EBADMSG;
    }

    UWB_WAIT(dwt_read32bitreg(SYS_STATUS_ID) & SYS_STATUS_TXFRS);
    dwt_write32bitreg(SYS_STATUS_ID, SYS_STATUS_TXFRS);

    return 0;
}

/**
 * @brief Waits for the final message from the initiator and starts the
 * calculation of the time of flight
 *
 * @param[out] tof_dtu The time-of-flight factor
 * @param[in] poll_rx_ts The timestamp of when the poll message arrived
 * @return 0 upon success
 * @return -EBUSY if the responder gets suspended
 * @return -EBADMSG if there was a reception error
 * @return -EINVAL if calculation came out to be invalid
 */
static int wait_final(uint64 *tof_dtu, const uint64_t *poll_rx_ts) {
    uint32 status_reg, frame_len, poll_rx_ts_32, resp_tx_ts_32, final_rx_ts_32;
    uint32_t resp_rx_ts, poll_tx_ts, final_tx_ts;
    uint64_t final_rx_ts, resp_tx_ts;
    double roundA, replyA, roundB, replyB;

    UWB_WAIT(
        (status_reg = dwt_read32bitreg(SYS_STATUS_ID)) &
        (SYS_STATUS_RXFCG | SYS_STATUS_ALL_RX_TO | SYS_STATUS_ALL_RX_ERR)) {
        if (k_sem_count_get(&k_sus_resp) == 0) {
            dwt_write32bitreg(SYS_STATUS_ID, SYS_STATUS_ALL_RX_ERR);
            dwt_rxreset();
            LOG_INF("Responder got suspended");
            return -EBUSY;
        }
    }

    if (!(status_reg & SYS_STATUS_RXFCG)) {
        dwt_write32bitreg(SYS_STATUS_ID,
                          SYS_STATUS_ALL_RX_TO | SYS_STATUS_ALL_RX_ERR);
        dwt_rxreset();
        return -EBADMSG;
    }

    dwt_write32bitreg(SYS_STATUS_ID, SYS_STATUS_RXFCG);

    frame_len = dwt_read32bitreg(RX_FINFO_ID) & RX_FINFO_RXFL_MASK_1023;
    if (frame_len <= RX_BUFFER_LEN) {
        dwt_readrxdata(rx_buffer, frame_len, 0);
    }

    rx_buffer[SEQ_CNT_OFFSET] = 0;

    if (!(memcmp(rx_buffer, rx_final_msg, DW_BASE_LEN) == 0)) {
        return -EBADMSG;
    }

    final_rx_ts = get_rx_timestamp_u64();
    resp_tx_ts = get_tx_timestamp_u64();

    msg_get_ts(&rx_buffer[RESP_MSG_POLL_RX_TS_IDX], &poll_tx_ts);
    msg_get_ts(&rx_buffer[RESP_MSG_RESP_TX_TS_IDX], &resp_rx_ts);
    msg_get_ts(&rx_buffer[FINAL_MSG_FINAL_TX_TS_IDX], &final_tx_ts);

    // uint32 is unsigned long on decawave
    poll_rx_ts_32 = (uint32)(*poll_rx_ts);
    resp_tx_ts_32 = (uint32)resp_tx_ts;
    final_rx_ts_32 = (uint32)final_rx_ts;

    // LOG_ERR("Hello message %lu , %lu, %lu", poll_tx_ts, resp_rx_ts, final_tx_ts);

    roundB = (double)(final_rx_ts_32 - resp_tx_ts_32);
    replyB = (double)(resp_tx_ts_32 - poll_rx_ts_32);
    roundA = (double)(resp_rx_ts - poll_tx_ts);
    replyA = (double)(final_tx_ts - resp_rx_ts);

    if ((roundA * roundB - replyA * replyB) <= 0) {
        LOG_INF("Bad TOF response");
        return -EINVAL;
    }

    *tof_dtu = (uint64)((roundA * roundB - replyA * replyB) /
                        (roundA + roundB + replyA + replyB));

    return 0;
}

/**
 * @brief Sends a report message to the initiator node detailing the time of
 * flight between the two nodes
 * @param[in] tof_dtu The time of flight scale factor
 * @return 0 upon success
 * @return -EBADMSG if unable to send
 */
static int send_report(uint64 tof_dtu) {
    int ret;

    msg_set_ts(&tx_report_msg[RESP_MSG_POLL_RX_TS_IDX], tof_dtu);

    dwt_writetxdata(sizeof(tx_report_msg), tx_report_msg, 0);
    dwt_writetxfctrl(sizeof(tx_report_msg), 0, 1);
    ret = dwt_starttx(DWT_START_TX_IMMEDIATE);

    if (ret != DWT_SUCCESS) {
        dwt_rxreset();
        LOG_INF("Failed to transmit");
        return -EBADMSG;
    }

    UWB_WAIT(dwt_read32bitreg(SYS_STATUS_ID) & SYS_STATUS_TXFRS);
    dwt_write32bitreg(SYS_STATUS_ID, SYS_STATUS_TXFRS);

    return 0;
}

/**
 * @brief Responds to double-sided two-way ranging requests
 *
 * @param[out] id The node that got responded to.
 * @param[out] logic_clk The exchange ID of the ranging transaction
 *
 * @return 0 upon success
 * @return -EBUSY if the responder gets suspended
 * @return negative error code otherwise
 */
int ds_resp_run(uint16_t *id, uint32_t *logic_clk) {
    int err;
    uint16_t src_id = 0;
    uint64 tof_dtu;
    uint64_t poll_rx_ts;
    uint32_t _logic_clk = 0;

    if (k_sem_count_get(&k_sus_resp) == 0) {
        return -EBUSY;
    }

    if ((err = wait_poll_message(&src_id, &_logic_clk)) < 0) {
        return err;
    }

    set_dest_id(src_id, tx_resp_msg);
    SET_EXCHANGE_ID(tx_resp_msg + LOGIC_CLK_OFFSET, _logic_clk);

    if ((err = ds_respond(&poll_rx_ts)) < 0) {
        return err;
    }

    set_src_id(src_id, rx_final_msg);
    SET_EXCHANGE_ID(rx_final_msg + LOGIC_CLK_OFFSET, _logic_clk);

    if ((err = wait_final(&tof_dtu, &poll_rx_ts)) < 0) {
        return err;
    }

    set_dest_id(src_id, tx_report_msg);
    SET_EXCHANGE_ID(tx_report_msg + LOGIC_CLK_OFFSET, _logic_clk);

    if ((err = send_report(tof_dtu)) < 0) {
        return err;
    }

    if (logic_clk != NULL) {
        *logic_clk = _logic_clk;
    }

    if (id != NULL) {
        *id = src_id;
    }

    return 0;
}

// Cascaded ranging functions


static int cc_wait_poll_message(uint16_t *src_id, uint32_t *logic_clk) {
    uint32 status_reg, frame_len;

    dwt_rxenable(DWT_START_RX_IMMEDIATE);

    UWB_WAIT(
        (status_reg = dwt_read32bitreg(SYS_STATUS_ID)) &
        (SYS_STATUS_RXFCG | SYS_STATUS_ALL_RX_TO | SYS_STATUS_ALL_RX_ERR)) {

        if (k_sem_count_get(&k_sus_resp) == 0) {
            dwt_write32bitreg(SYS_STATUS_ID, SYS_STATUS_ALL_RX_ERR);
            dwt_rxreset();
            LOG_INF("Responder suspended");
            return -EBUSY;
        }
    }

    if (!(status_reg & SYS_STATUS_RXFCG)) {
        dwt_write32bitreg(SYS_STATUS_ID,
                          SYS_STATUS_ALL_RX_TO | SYS_STATUS_ALL_RX_ERR);
        dwt_rxreset();
        return -EBADMSG;
    }

    dwt_write32bitreg(SYS_STATUS_ID, SYS_STATUS_RXFCG);

    frame_len = dwt_read32bitreg(RX_FINFO_ID) & RX_FINFO_RXFL_MASK_1023;
    if (frame_len <= RX_BUFFER_LEN) {
        dwt_readrxdata(rx_buffer, frame_len, 0);
    }

    rx_buffer[SEQ_CNT_OFFSET] = 0;
    *src_id = get_src_id(rx_buffer);

    // Compare received message to template, ignoring source and dest ids
    rx_buffer[SRC_OFFSET] = 0; //mask src to 0 in RX message
    rx_buffer[SRC_OFFSET + 1] = 0;
    // rx_buffer[DEST_OFFSET] = 0; //mask dest to 0 in RX message
    // rx_buffer[DEST_OFFSET + 1] = 0;
    GET_EXCHANGE_ID(rx_buffer + LOGIC_CLK_OFFSET, *logic_clk);
    SET_EXCHANGE_ID(rx_buffer + LOGIC_CLK_OFFSET, 0);
    if (!(memcmp(rx_buffer, cc_rx_poll_cmp, DW_BASE_LEN) == 0)) {
        LOG_ERR("MEMCMP failed in  cc_wait_poll_message");
        return -EBADMSG;
    }
    return 0;
}

static int cc_ds_respond(uint64_t *poll_rx_ts, uint16_t initiator_id, uint16_t this_id) {
    uint32 resp_tx_time, node_delay_uus;
    int ret;

    // Initiator id should already be baked into the message

    *poll_rx_ts = get_rx_timestamp_u64();
    node_delay_uus = this_id * (int)(NUM_USERS / 1000.0); // delay in microseconds based on node ID

    uint32 delay = (POLL_RX_TO_RESP_TX_DLY_UUS + node_delay_uus);
    // uint32 delay = 0;
    // compute TX timestamp from the delay from when the initial poll frame was RX
    resp_tx_time =
        (*poll_rx_ts + (delay * UUS_TO_DWT_TIME)) >> 8;

    dwt_setdelayedtrxtime(resp_tx_time); 

    dwt_writetxdata(sizeof(cc_tx_resp_msg), cc_tx_resp_msg, 0);
    dwt_writetxfctrl(sizeof(cc_tx_resp_msg), 0, 1); 

    ret = dwt_starttx(DWT_START_TX_DELAYED | DWT_RESPONSE_EXPECTED);

    // SO its failing on the start of the transmission
    // throwing an error, which explains why the receiver gets nonsense
    if (ret != DWT_SUCCESS) {
        dwt_rxreset();
        return -EBADMSG;
    }

    UWB_WAIT(dwt_read32bitreg(SYS_STATUS_ID) & SYS_STATUS_TXFRS);
    dwt_write32bitreg(SYS_STATUS_ID, SYS_STATUS_TXFRS);

    LOG_ERR("Response sent from %u to ID %u", this_id, initiator_id);

    return 0;
}

int cc_ds_resp_run(uint16_t *id, uint32_t *logic_clk) {
    int err;
    uint16_t initiator_id = 0;
    uint64 tof_dtu;
    uint64_t poll_rx_ts;
    uint32_t _logic_clk = 0;

    if (k_sem_count_get(&k_sus_resp) == 0) {
        return -EBUSY;
    }

    // if ((err = wait_poll_message(&initiator_id, &_logic_clk)) < 0) {
    //     return err;
    // }
    if ((err = cc_wait_poll_message(&initiator_id, &_logic_clk)) < 0) {
        return err;
    }
    // ID reception is correct

    set_dest_id(initiator_id, cc_tx_resp_msg);
    SET_EXCHANGE_ID(cc_tx_resp_msg + LOGIC_CLK_OFFSET, _logic_clk);

    if ((err = cc_ds_respond(&poll_rx_ts, initiator_id, this_id)) < 0) {
        LOG_ERR("Error in cc_ds_respond");
        return err;
    }

    // set_dest_id(initiator_id, tx_resp_msg);
    // SET_EXCHANGE_ID(tx_resp_msg + LOGIC_CLK_OFFSET, _logic_clk);

    // if ((err = ds_respond(&poll_rx_ts)) < 0) {
    //     LOG_ERR("Error in ds_respond");
    //     return err;
    // }

    ////////
    set_src_id(initiator_id, rx_final_msg);
    SET_EXCHANGE_ID(rx_final_msg + LOGIC_CLK_OFFSET, _logic_clk);

    if ((err = wait_final(&tof_dtu, &poll_rx_ts)) < 0) {
        return err;
    }

    set_dest_id(initiator_id, tx_report_msg);
    SET_EXCHANGE_ID(tx_report_msg + LOGIC_CLK_OFFSET, _logic_clk);

    if ((err = send_report(tof_dtu)) < 0) {
        return err;
    }

    if (logic_clk != NULL) {
        *logic_clk = _logic_clk;
    }

    if (id != NULL) {
        *id = initiator_id;
    }

    return 0;
}
/**
 * @brief Sends a response to the initiator assuming single-sided TWR is being
 * used.
 *
 * @return 0 upon success
 * @return -EBADMSG if unable to send response message
 * @return -EBUSY if the responder gets suspended
 */
static int ss_respond(void) {
    uint32 resp_tx_time;
    int ret;
    uint64_t poll_rx_ts, resp_tx_ts;

    poll_rx_ts = get_rx_timestamp_u64();

    resp_tx_time =
        (poll_rx_ts + (POLL_RX_TO_RESP_TX_DLY_UUS * UUS_TO_DWT_TIME)) >> 8;
    dwt_setdelayedtrxtime(resp_tx_time);

    resp_tx_ts = (((uint64)(resp_tx_time & 0xFFFFFFFEUL)) << 8) + TX_ANT_DLY;

    // note: you do write poll_rx_ts and resp_tx_ts directly to resp msg
    // when you SS range?
    msg_set_ts(&tx_resp_msg[RESP_MSG_POLL_RX_TS_IDX], poll_rx_ts);
    msg_set_ts(&tx_resp_msg[RESP_MSG_RESP_TX_TS_IDX], resp_tx_ts);

    dwt_writetxdata(sizeof(tx_resp_msg), tx_resp_msg, 0);
    dwt_writetxfctrl(sizeof(tx_resp_msg), 0, 1);

    ret = dwt_starttx(DWT_START_TX_DELAYED);

    if (ret != DWT_SUCCESS) {
        dwt_rxreset();
        return -EBADMSG;
    }

    UWB_WAIT(dwt_read32bitreg(SYS_STATUS_ID) & SYS_STATUS_TXFRS) {
        if (0 == k_sem_count_get(&k_sus_resp)) {
            dwt_forcetrxoff();
            return -EBUSY;
        }
    }

    dwt_write32bitreg(SYS_STATUS_ID, SYS_STATUS_TXFRS);

    return 0;
}

/**
 * @brief Responds to single-sided two-way ranging requests
 *
 * @param[out] id The node that got responded to.
 * @param[out] logic_clk The exchange ID of the ranging transaction
 *
 * @return 0 upon success
 * @return -EBUSY if the responder gets suspended
 * @return negative error code otherwise
 */
int ss_resp_run(uint16_t *id, uint32_t *logic_clk) {
    int err;
    uint16_t src_id = 0;
    uint32_t _logic_clk = 0;

    if (k_sem_count_get(&k_sus_resp) == 0) {
        return -EBUSY;
    }

    if ((err = wait_poll_message(&src_id, &_logic_clk)) < 0) {
        dwt_rxreset();
        return err;
    }

    set_dest_id(src_id, tx_resp_msg);
    SET_EXCHANGE_ID(tx_resp_msg + LOGIC_CLK_OFFSET, _logic_clk);

    if ((err = ss_respond()) < 0) {
        return err;
    }

    if (id != NULL) {
        *id = src_id;
    }

    if (logic_clk != NULL) {
        *logic_clk = _logic_clk;
    }

    return 0;
}
