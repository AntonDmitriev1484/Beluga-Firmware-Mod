/**
 * @file initiator.c
 *
 * @brief This module implements the functionality for the initiator role in a
 * UWB-based ranging system.
 *
 * The primary objective of this module is to perform the communication sequence
 * required to initiate a ranging process and compute the distance between the
 * initiator and a responder in a UWB-based system.
 *
 * The module handles:
 * - Sending a poll message to the responder.
 * - Receiving a response from the responder.
 * - Sending a final message containing timestamp data (double-sided
 * ranging only).
 * - Receiving a report message containing the time-of-flight (ToF) data, which
 * is used to calculate the distance (double-sided ranging only).
 *
 * @date 6/1/2024
 *
 * @author Decawave
 * @author Tome Schmitz
 */

#include <app_leds.h>
#include <deca_device_api.h>
#include <deca_regs.h>
#include <init_resp_common.h>
#include <initiator.h>
#include <port_platform.h>
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>

/**
 * Logger for the initiator module
 */
LOG_MODULE_REGISTER(initializer_logger, CONFIG_INITIATOR_LOG_LEVEL);

/**
 * Semaphore for suspending the initiator task
 */
K_SEM_DEFINE(k_sus_init, 0, 1);

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
static uint8 tx_poll_msg[POLL_MSG_LEN] = {0x41, 0x88, 0,   0xCA, 0xDE, 'W',
                                          'A',  'V',  'E', 0x61, 0,    0};
static uint8 rx_resp_msg[RESP_MSG_LEN] = {
    0x41, 0x88, 0, 0xCA, 0xDE, 'V', 'E', 'W', 'A', 0x50,
    0,    0,    0, 0,    0,    0,   0,   0,   0,   0};
static uint8 tx_final_msg[FINAL_MSG_LEN] = {
    0x41, 0x88, 0, 0xCA, 0xDE, 'W', 'A', 'V', 'E', 0x69, 0, 0,
    0,    0,    0, 0,    0,    0,   0,   0,   0,   0,    0, 0};
static uint8 rx_report_msg[REPORT_MSG_LEN] = {
    0x41, 0x88, 0, 0xCA, 0xDE, 'V', 'E', 'W', 'A', 0xE3, 0, 0, 0, 0, 0, 0};


// Cascaded ranging message implementation
#define NUM_USERS 3

static uint8 cc_tx_poll_msg[POLL_MSG_LEN] = {
    0x41, 0x88, //frame control
    0,   // sequence number
    0xCA, 0xDE, // PAN ID
    0, 0, //dest addr (broadcast)
    'V',  'E', //source addr
    0x61, // function code
    0,    0}; //CRC

static uint8 cc_rx_resp_msg[RESP_MSG_LEN] = {
    0x41, 0x88, // frame control
     0,   // sequence number
     0xCA, 0xDE, // PAN ID
      'V', 'E', //dest addr -> will be initiator id
       'W', 'A', //source addr -> will be responder id
        0x50, // function code
    0,    0,    0, 0,    0,    0,   0,   0,   // empty payload
    0,   0}; //CRC
static uint8 cc_rx_resp_cmp[RESP_MSG_LEN] = {
    0x41, 0x88, // frame control
     0,   // sequence number
     0xCA, 0xDE, // PAN ID
      0, 0, //dest addr (broadcast)
      0, 0, //source addr, not set here for proper comparison in cc_wait_poll_message
        0x50, // function code
    0,    0,    0, 0,    0,    0,   0,   0,   // empty payload
    0,   0}; //CRC


#define CC_FINAL_MSG_LEN (DW_FRAME_OVERHEAD + TIMESTAMP_OVERHEAD + (NUM_USERS * TIMESTAMP_OVERHEAD) + TIMESTAMP_OVERHEAD)
static uint8 cc_tx_final_msg_n3[CC_FINAL_MSG_LEN] = { // Hard coded for 3 users
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

static uint8 cc_rx_report_msg[REPORT_MSG_LEN] = {
    0x41, 0x88, // frame control
      0, // sequence number
      0xCA, 0xDE, // PAN ID
       'V', 'E', //dest addr -> will be initiator id
        'W', 'A', //source addr -> will be responder id
         0xE3, // function code
          0, 0, 0, 0, // ToF
           0, 0}; //CRC
static uint8 cc_rx_report_cmp[REPORT_MSG_LEN] = {
    0x41, 0x88, // frame control
      0, // sequence number
      0xCA, 0xDE, // PAN ID
       0, 0, //dest addr (broadcast)
       0, 0, //source addr, not set here for proper comparison in cc_wait_poll_message
         0xE3, // function code
          0, 0, 0, 0, // ToF
           0, 0}; //CRC
/**
 * @}
 */

/**
 * The maximum length of the receive buffer
 */
// #define RX_BUF_LEN MAX(RESP_MSG_LEN, REPORT_MSG_LEN)
#define RX_BUF_LEN MAX(CC_FINAL_MSG_LEN, REPORT_MSG_LEN)

/**
 * The buffer where received data is stored
 */
static uint8 rx_buffer[RX_BUF_LEN];

/**
 * Multiplication factor to convert carrier integrator value to a frequency
 * offset in Hertz.
 */
static double freq_offset_multiplier = FREQ_OFFSET_MULTIPLIER;

/**
 * Multiplication factor to convert frequency offset in Hertz to PPM crystal
 * offset.
 */
static double hertz_to_ppm_multiplier = HERTZ_TO_PPM_MULTIPLIER_CHAN_5;

/**
 * This is the delay from Frame RX timestamp to TX reply timestamp used for
 * calculating/setting the DW1000's delayed TX function.
 */
#define POLL_RX_TO_RESP_TX_DLY_UUS 2000

/**
 * This is the delay from the end of the frame transmission to the enable of the
 * receiver, as programmed for the DW1000's wait for response feature.
 */
#define POLL_TX_TO_RESP_RX_DLY_UUS 300

/**
 * @brief Sets the source IDs for the messages that the initiator sends and the
 * destination ID for the messages the initiator receives
 *
 * @param[in] id The ID of the node
 *
 * @return 0 upon success
 * @return -EBUSY if UWB is active
 */
int set_initiator_id(uint16_t id) {
    CHECK_UWB_ACTIVE();

    set_src_id(id, tx_poll_msg);
    set_dest_id(id, rx_resp_msg);
    set_src_id(id, tx_final_msg);
    set_dest_id(id, rx_report_msg);

    // Baking id into cascaded ranging messages
    set_src_id(id, cc_tx_poll_msg);
    set_dest_id(id, cc_rx_resp_msg);
    set_src_id(id, cc_tx_final_msg_n3);
    set_dest_id(id, cc_rx_report_msg);

    return 0;
}

/**
 * @brief Sets the personal area network (PAN) ID for the initiator messages
 *
 * @param[in] id
 * @return 0 upon success
 * @return -EBUSY if UWB is active
 */
int set_initiator_pan_id(uint16_t id) {
    CHECK_UWB_ACTIVE();

    set_pan_id(id, tx_poll_msg);
    set_pan_id(id, rx_resp_msg);
    set_pan_id(id, tx_final_msg);
    set_pan_id(id, rx_report_msg);

    // Baking PAN ID into cascaded ranging messages
    set_pan_id(id, cc_tx_poll_msg);
    set_pan_id(id, cc_rx_resp_msg);
    set_pan_id(id, cc_tx_final_msg_n3);
    set_pan_id(id, cc_rx_report_msg);

    return 0;
}

/**
 * @brief Sets the multiplication factor to convert carrier integrator value to
 * a frequency offset in Hertz depending on the data rate.
 *
 * @param[in] datarate_110k `true` if data rate is 110K, `false` otherwise
 */
void set_freq_offset_multiplier(bool datarate_110k) {
    if (datarate_110k) {
        freq_offset_multiplier = FREQ_OFFSET_MULTIPLIER_110KB;
    } else {
        freq_offset_multiplier = FREQ_OFFSET_MULTIPLIER;
    }
}

/**
 * @brief Sets the multiplication factor to convert frequency offset in Hertz to
 * PPM crystal offset depending on the channel.
 *
 * @param[in] channel The channel being used for UWB
 */
void set_hertz_to_ppm_multiplier(uint8_t channel) {
    switch (channel) {
    case 1:
        hertz_to_ppm_multiplier = HERTZ_TO_PPM_MULTIPLIER_CHAN_1;
        break;
    case 2:
        hertz_to_ppm_multiplier = HERTZ_TO_PPM_MULTIPLIER_CHAN_2;
        break;
    case 3:
        hertz_to_ppm_multiplier = HERTZ_TO_PPM_MULTIPLIER_CHAN_3;
        break;
    case 4:
    case 5:
    case 7:
        hertz_to_ppm_multiplier = HERTZ_TO_PPM_MULTIPLIER_CHAN_5;
        break;
    default:
        __ASSERT(false, "Invalid UWB channel (%u)", channel);
        break;
    }
}

/**
 * @brief Sets the destination address (The node being ranged to) in the
 * initiator messages.
 *
 * @param[in] id The destination address
 *
 * @note This sets the source address for the messages being received.
 */
static void set_destination(uint16_t id) {
    set_dest_id(0, tx_poll_msg);
    set_src_id(id, rx_resp_msg);
    set_dest_id(0, tx_final_msg);
    set_src_id(id, rx_report_msg);
}

#if IS_ENABLED(CONFIG_UWB_LOGIC_CLK)
/**
 * The ID associated with a ranging exchange.
 */
static uint32_t exchange_id = UINT32_C(0);

/**
 * @brief Updates each of the messages with the appropriate exchange ID.
 */
static void set_exchange_id(void) {
    SET_EXCHANGE_ID(tx_poll_msg + LOGIC_CLK_OFFSET, exchange_id);
    SET_EXCHANGE_ID(rx_resp_msg + LOGIC_CLK_OFFSET, exchange_id);
    SET_EXCHANGE_ID(tx_final_msg + LOGIC_CLK_OFFSET, exchange_id);
    SET_EXCHANGE_ID(rx_report_msg + LOGIC_CLK_OFFSET, exchange_id);

    // Cascaded ranging messages
    SET_EXCHANGE_ID(cc_tx_poll_msg + LOGIC_CLK_OFFSET, exchange_id);
    SET_EXCHANGE_ID(cc_rx_resp_msg + LOGIC_CLK_OFFSET, exchange_id);
    SET_EXCHANGE_ID(cc_tx_final_msg_n3 + LOGIC_CLK_OFFSET, exchange_id);
    SET_EXCHANGE_ID(cc_rx_report_msg + LOGIC_CLK_OFFSET, exchange_id);
}

/**
 * Saves the exchange ID in a pointer and updates the ID for the next run.
 *
 * @param[out] x The pointer to save the exchange ID in
 */
#define update_exchange(x)                                                     \
    do {                                                                       \
        if ((x) != NULL) {                                                     \
            *(x) = exchange_id;                                                \
        }                                                                      \
        exchange_id++;                                                         \
    } while (0)
#else
/**
 * Placeholder for when the logic clock is disabled.
 */
#define set_exchange_id()  (void)0

/**
 * Placeholder for when the logic clock is disabled.
 */
#define update_exchange(x) (void)0
#endif

/**
 * @brief Sends a poll message to the node being ranged to.
 *
 * @return 0 upon success
 * @return -EBADMSG if transmission failed
 */

//Note: A simple example of forming a message and sending it
static int send_poll(void) {
    dwt_write32bitreg(SYS_STATUS_ID, SYS_STATUS_TXFRS);
    dwt_writetxdata(sizeof(tx_poll_msg), tx_poll_msg, 0);
    dwt_writetxfctrl(sizeof(tx_poll_msg), 0, 1);

    int check_poll_msg =
        dwt_starttx(DWT_START_TX_IMMEDIATE | DWT_RESPONSE_EXPECTED);

    if (check_poll_msg != DWT_SUCCESS) {
        return -EBADMSG;
    }

    UWB_WAIT(dwt_read32bitreg(SYS_STATUS_ID) & SYS_STATUS_TXFRS);
    dwt_write32bitreg(SYS_STATUS_ID, SYS_STATUS_TXFRS);

    return 0;
}


/**
 * @brief Waits for a response from the node being ranged to assuming the
 * double-sided ranging scheme is being used.
 *
 * @return 0 upon success
 * @return -EBADMSG if there was an rx error, rx timeout, or the message
 * received did not match the expected message
 */
static int ds_rx_response(void) {
    uint32 status_reg, frame_len;

    // We need to wait for N such responses
    UWB_WAIT((status_reg = dwt_read32bitreg(SYS_STATUS_ID)) &
             (SYS_STATUS_RXFCG | SYS_STATUS_ALL_RX_TO | SYS_STATUS_ALL_RX_ERR));

    if (!(status_reg & SYS_STATUS_RXFCG)) {
        dwt_write32bitreg(SYS_STATUS_ID,
                          SYS_STATUS_ALL_RX_TO | SYS_STATUS_ALL_RX_ERR);
        dwt_rxreset();
        return -EBADMSG;
    }

    dwt_write32bitreg(SYS_STATUS_ID, SYS_STATUS_RXFCG);

    frame_len = dwt_read32bitreg(RX_FINFO_ID) & RX_FINFO_RXFLEN_MASK;

    if (frame_len <= RX_BUF_LEN) {
        dwt_readrxdata(rx_buffer, frame_len, 0);
    }

    rx_buffer[SEQ_CNT_OFFSET] = 0;

    // Need to perform this memcmp per response
    if (!(memcmp(rx_buffer, rx_resp_msg, DW_BASE_LEN) == 0)) {
        return -EBADMSG;
    }

    return 0;
}


/**
 * @brief Sends the final message to the node being ranged to.
 *
 * @return 0 upon success
 * @return -ETIMEDOUT if transmission failed
 */
static int send_final(void) {
    uint64 poll_tx_ts, resp_rx_ts;
    uint64 ts_replyA_end;
    uint32 resp_tx_time;
    int ret;

    poll_tx_ts = get_tx_timestamp_u64();
    resp_rx_ts = get_rx_timestamp_u64(); // Assumed that all timestamps are 40 bits long, but get returned in 64 bit integer.

    resp_tx_time =
        (resp_rx_ts + (POLL_RX_TO_RESP_TX_DLY_UUS * UUS_TO_DWT_TIME)) >> 8;
    dwt_setdelayedtrxtime(resp_tx_time);

    ts_replyA_end = (((uint64)(resp_tx_time & 0xFFFFFFFEUL)) << 8) + TX_ANT_DLY;

    msg_set_ts(&tx_final_msg[RESP_MSG_POLL_RX_TS_IDX], poll_tx_ts);
    msg_set_ts(&tx_final_msg[RESP_MSG_RESP_TX_TS_IDX], resp_rx_ts);
    msg_set_ts(&tx_final_msg[FINAL_MSG_FINAL_TX_TS_IDX], ts_replyA_end);

    dwt_writetxdata(sizeof(tx_final_msg), tx_final_msg, 0);
    dwt_writetxfctrl(sizeof(tx_final_msg), 0, 1);

    ret = dwt_starttx(DWT_START_TX_DELAYED | DWT_RESPONSE_EXPECTED);

    if (ret != DWT_SUCCESS) {
        dwt_rxreset();
        return -ETIMEDOUT;
    }

    UWB_WAIT(dwt_read32bitreg(SYS_STATUS_ID) & SYS_STATUS_TXFRS);
    dwt_write32bitreg(SYS_STATUS_ID, SYS_STATUS_TXFRS);

    return 0;
}

/**
 * @brief Waits for and receives the report message from the node being ranged
 * to. Additionally calculates the distance between the two nodes from the
 * payload in the report.
 *
 * @param[out] distance The estimated distance between the two nodes
 *
 * @return 0 upon success
 * @return -EBADMSG if there was an rx error, rx timeout, or the message
 * received did not match the expected message
 */
static int rx_report(double *distance, dwt_rxdiag_t* diag) {
    uint32 status_reg, frame_len;
    uint32_t msg_tof_dtu;
    double tof;

    UWB_WAIT((status_reg = dwt_read32bitreg(SYS_STATUS_ID)) &
             (SYS_STATUS_RXFCG | SYS_STATUS_ALL_RX_TO | SYS_STATUS_ALL_RX_ERR));

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

    if (!(memcmp(rx_buffer, rx_report_msg, DW_BASE_LEN) == 0)) {
        return -EBADMSG;
    }

    msg_get_ts(&rx_buffer[RESP_MSG_POLL_RX_TS_IDX], &msg_tof_dtu);
    tof = msg_tof_dtu * DWT_TIME_UNITS;
    *distance = tof * SPEED_OF_LIGHT;
    dwt_readdiagnostics(diag);

    return 0;
}

/**
 * @brief Initiates a double-sided two-way ranging measurement to a certain
 * node.
 *
 * @param[in] id The node to range to
 * @param[out] distance The estimated distance between the nodes
 * @param[out] logic_clock The ID associated with the successful exchange.
 *
 * @return 0 upon a successful ranging run
 * @return -EINVAL if distance parameter is NULL
 * @return negative error code otherwise
 *
 * @note logic_clock will be updated after a successful double-sided two-way
 * ranging exchange. If an error occurred, then logic_clock will not be updated
 * and thus will retain its original value. Also, if logic_clock is NULL, it is
 * assumed that the logic_clock output is not desired and the run will still be
 * initiated.
 */
int ds_init_run(uint16_t id, double *distance, dwt_rxdiag_t* diag, uint32_t *logic_clock) {
    int err;

    // Note: This is where we need to add our timer

    uint64_t start_ms = k_uptime_get();

    if (distance == NULL) {
        return -EINVAL;
    }

    id = 0;
    
    set_exchange_id();

    set_dest_id(0, tx_poll_msg);
    if ((err = send_poll()) < 0) {
        return err;
    }

    // Now need to change the logic in ds_rx_response
    // to handle multiple nodes
    if ((err = ds_rx_response()) < 0) {
        return err;
    }

    set_dest_id(0, tx_final_msg);
    if ((err = send_final()) < 0) {
        return err;
    }

    if ((err = rx_report(distance, diag)) < 0) {
        return err;
    }

    update_exchange(logic_clock);

    uint64_t end_ms = k_uptime_get();
    uint64_t elapsed_ms = end_ms-start_ms;
    LOG_ERR("Initator elapsed time %llu ms", elapsed_ms);


    return 0;
}


// Cascaded ranging methods

static int cc_send_poll(void) {
    dwt_write32bitreg(SYS_STATUS_ID, SYS_STATUS_TXFRS);
    dwt_writetxdata(sizeof(cc_tx_poll_msg), cc_tx_poll_msg, 0);
    dwt_writetxfctrl(sizeof(cc_tx_poll_msg), 0, 1);

    int check_poll_msg =
        dwt_starttx(DWT_START_TX_IMMEDIATE | DWT_RESPONSE_EXPECTED);

    if (check_poll_msg != DWT_SUCCESS) {
        return -EBADMSG;
    }

    UWB_WAIT(dwt_read32bitreg(SYS_STATUS_ID) & SYS_STATUS_TXFRS);
    dwt_write32bitreg(SYS_STATUS_ID, SYS_STATUS_TXFRS);

    LOG_ERR("Poll sent");

    return 0;
}

static int cc_ds_rx_response(uint64_t* resp_rx_ts_arr) {
    uint32 status_reg, frame_len;
    uint16_t responder_id;
    int n_responses = 0;
    // We need to wait for N such responses

    // TODO Change this
    while (n_responses < NUM_USERS-2) {
        UWB_WAIT((status_reg = dwt_read32bitreg(SYS_STATUS_ID)) &
                 (SYS_STATUS_RXFCG | SYS_STATUS_ALL_RX_TO | SYS_STATUS_ALL_RX_ERR));
        // TODO : Need to comment this back in eventually
        if (!(status_reg & SYS_STATUS_RXFCG)) {
            dwt_write32bitreg(SYS_STATUS_ID,
                              SYS_STATUS_ALL_RX_TO | SYS_STATUS_ALL_RX_ERR);
            LOG_ERR("Error in response");

            frame_len = dwt_read32bitreg(RX_FINFO_ID) & RX_FINFO_RXFLEN_MASK;
            dwt_readrxdata(rx_buffer, frame_len, 0);
            // LOG_ERR("Dumping received cc_rx_resp_msg:");
            // for (int i = 0; i < sizeof(cc_rx_resp_msg); i++) {
            //     LOG_ERR("%02X ", ((uint8_t*)rx_buffer)[i]);
            // }
            dwt_rxreset();
            return -EBADMSG;
        }

        dwt_write32bitreg(SYS_STATUS_ID, SYS_STATUS_RXFCG);

        frame_len = dwt_read32bitreg(RX_FINFO_ID) & RX_FINFO_RXFLEN_MASK;

        if (frame_len <= RX_BUF_LEN) {
            dwt_readrxdata(rx_buffer, frame_len, 0);
        }

        rx_buffer[SEQ_CNT_OFFSET] = 0;

        // Make sure to fetch source id from rx_buffer before clearing for compare
        responder_id = get_src_id(rx_buffer);
        // Save the timestamp of this response
        resp_rx_ts_arr[responder_id] = get_rx_timestamp_u64();

        // Compare received message to template, ignoring source and dest ids
        rx_buffer[SRC_OFFSET] = 0; //mask src to 0 in RX message
        rx_buffer[SRC_OFFSET + 1] = 0;
        rx_buffer[DEST_OFFSET] = 0; //mask dest to 0 in RX message
        rx_buffer[DEST_OFFSET + 1] = 0;

        if (!(memcmp(rx_buffer, cc_rx_resp_cmp, DW_BASE_LEN) == 0)) {
            return -EBADMSG; // Note, with this, a single bad range will drop all ranges in the cascade
        }

        n_responses++;
        LOG_ERR("Response received from ID %u", responder_id);
    }
    return 0;
}

int cc_ds_init_run(uint16_t id, double *distance, dwt_rxdiag_t* diag, uint32_t *logic_clock) {
    int err;
    uint64_t resp_rx_ts_arr[NUM_USERS];

    // Note: This is where we need to add our timer

    uint64_t start_ms = k_uptime_get();

    if (distance == NULL) {
        return -EINVAL;
    }

    id = 0;
    
    set_exchange_id();

    set_dest_id(0, cc_tx_poll_msg);
    if ((err = cc_send_poll()) < 0) {
        return err;
    }

    // cc_ds_rx_response records every response timestamp it gets in this array.
    if ((err = cc_ds_rx_response(&resp_rx_ts_arr)) < 0) {
        return err;
    }

    for (int i = 0; i < NUM_USERS-1; i++) {
        LOG_ERR("resp_rx_ts_arr[%d] = %llu", i, resp_rx_ts_arr[i]);
    }
    // TODO: Print out here

    /////////
    set_dest_id(0, tx_final_msg);
    if ((err = send_final()) < 0) {
        return err;
    }

    if ((err = rx_report(distance, diag)) < 0) {
        return err;
    }

    update_exchange(logic_clock);

    uint64_t end_ms = k_uptime_get();
    uint64_t elapsed_ms = end_ms-start_ms;
    LOG_ERR("Initator elapsed time %llu ms", elapsed_ms);


    return 0;
}

/**
 * @brief Waits for a response from the node being ranged to assuming the
 * single-sided two-way ranging scheme is being used. Additionally calculates
 * the estimated distance between the nodes.
 *
 * @param[out] distance The estimated distance between the nodes
 *
 * @return 0 upon success
 * @return -EBADMSG if there was an rx error, rx timeout, or the message
 * received did not match the expected message
 */
static int ss_rx_response(double *distance) {
    uint32_t status_reg, frame_len, poll_tx_ts, resp_rx_ts, poll_rx_ts,
        resp_tx_ts;
    int32_t rtd_init, rtd_resp;
    float clockOffsetRatio;
    double tof;

    UWB_WAIT((status_reg = dwt_read32bitreg(SYS_STATUS_ID)) &
             (SYS_STATUS_RXFCG | SYS_STATUS_ALL_RX_TO | SYS_STATUS_ALL_RX_ERR));

    if (!(status_reg & SYS_STATUS_RXFCG)) {
        dwt_write32bitreg(SYS_STATUS_ID,
                          SYS_STATUS_ALL_RX_TO | SYS_STATUS_ALL_RX_ERR);
        dwt_rxreset();
        return -EBADMSG;
    }

    dwt_write32bitreg(SYS_STATUS_ID, SYS_STATUS_RXFCG);

    frame_len = dwt_read32bitreg(RX_FINFO_ID) & RX_FINFO_RXFLEN_MASK;
    if (frame_len <= RX_BUF_LEN) {
        dwt_readrxdata(rx_buffer, frame_len, 0);
    }

    rx_buffer[SEQ_CNT_OFFSET] = 0;

    if (!(memcmp(rx_buffer, rx_resp_msg, DW_BASE_LEN) == 0)) {
        dwt_rxreset();
        return -EBADMSG;
    }

    poll_tx_ts = dwt_readtxtimestamplo32();
    resp_rx_ts = dwt_readrxtimestamplo32();

    clockOffsetRatio =
        (float)(dwt_readcarrierintegrator() *
                (freq_offset_multiplier * hertz_to_ppm_multiplier / 1.0e6));

    msg_get_ts(&rx_buffer[RESP_MSG_POLL_RX_TS_IDX], &poll_rx_ts);
    msg_get_ts(&rx_buffer[RESP_MSG_RESP_TX_TS_IDX], &resp_tx_ts);

    rtd_init = (int32_t)(resp_rx_ts - poll_tx_ts);
    rtd_resp = (int32_t)(resp_tx_ts - poll_rx_ts);

    tof = (double)(((float)rtd_init -
                    (float)rtd_resp * (1.0f - clockOffsetRatio)) /
                   2.0f) *
          DWT_TIME_UNITS;
    *distance = tof * SPEED_OF_LIGHT;
    return 0;
}

/**
 * @brief Initiates a single-sided two-way ranging measurement to a certain
 * node.
 *
 * @param[in] id The node to range to
 * @param[out] distance The estimated distance between the nodes
 * @param[out] logic_clock The ID associated with the successful exchange.
 *
 * @return 0 upon a successful ranging run
 * @return -EINVAL if distance parameter is NULL
 * @return negative error code otherwise
 *
 * @note logic_clock will be updated after a successful single-sided two-way
 * ranging exchange. If an error occurred, then logic_clock will not be updated
 * and thus will retain its original value. Also, if logic_clock is NULL, it is
 * assumed that the logic_clock output is not desired and the run will still be
 * initiated.
 */
int ss_init_run(uint16_t id, double *distance, uint32_t *logic_clock) {
    int err;

    if (distance == NULL) {
        return -EINVAL;
    }

    set_destination(id);
    set_exchange_id();

    if ((err = send_poll()) < 0) {
        return err;
    }

    if ((err = ss_rx_response(distance)) < 0) {
        return err;
    }

    update_exchange(logic_clock);

    return 0;
}
