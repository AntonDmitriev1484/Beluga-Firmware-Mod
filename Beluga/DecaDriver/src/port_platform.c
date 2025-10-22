/*! ----------------------------------------------------------------------------
 * @file    port_platform.c
 * @brief   HW specific definitions and functions for portability
 *
 * @attention
 *
 * Copyright 2016 (c) DecaWave Ltd, Dublin, Ireland.
 *
 * All rights reserved.
 *
 * @author DecaWave
 */

#include "port_platform.h"
#include "deca_device_api.h"
#include <spi.h>
#include <stdbool.h>
#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(dw1000_irq_handler, LOG_LEVEL_DBG);

#if defined(CONFIG_ENABLE_BELUGA_UWB)

#define DW1000_MAXBUF 128

/****************************************************************************
 *
 *                              APP global variables
 *
 ****************************************************************************/

/****************************************************************************
 *
 *                  Port private variables and function prototypes
 *
 ****************************************************************************/

#if DT_NODE_HAS_PROP(DT_NODELABEL(dw1000_spi), reset_gpios)
static const struct gpio_dt_spec dw1000_reset_pin =
    GPIO_DT_SPEC_GET(DT_NODELABEL(dw1000_spi), reset_gpios);
#else
#error "Unable to get DW1000 reset GPIO"
#endif

#if DT_NODE_HAS_PROP(DT_NODELABEL(dw1000_spi), int_gpios)
static const struct gpio_dt_spec dw1000_irq_pin =
    GPIO_DT_SPEC_GET(DT_NODELABEL(dw1000_spi), int_gpios);
#else
#error "Unable to get DW1000 IRQ GPIO"
#endif

static volatile bool dw1000_irq_pending = false;

static struct k_work dw1000_irq_work;
static struct gpio_callback dw1000_irq_cb_data;
static void dw1000_irq_handler(const struct device *dev, 
                                struct gpio_callback *cb, 
                                uint32_t pins);


/****************************************************************************
 *
 *                              Time section
 *
 ****************************************************************************/

/****************************************************************************
 *
 *                              END OF Time section
 *
 ****************************************************************************/

/****************************************************************************
 *
 *                              Configuration section
 *
 ****************************************************************************/

/****************************************************************************
 *
 *                          End of configuration section
 *
 ****************************************************************************/

/****************************************************************************
 *
 *                          DW1000 port section
 *
 ****************************************************************************/
// YB : STM HAL based function have to be updated using NRF drivers

/**
 * @fn      setup_DW1000RSTnIRQ
 * @brief   setup the DW_RESET pin mode
 *          0 - output Open collector mode
 *          !0 - input mode with connected EXTI0 IRQ
 * */
/*
void setup_DW1000RSTnIRQ(int enable) {
    ARG_UNUSED(enable);

    gpio_pin_configure_dt(&dw1000_irq_pin, GPIO_DISCONNECTED);
}
*/
void setup_DW1000RSTnIRQ(int enable) {
    int ret;
    
    if (enable) {
        // Configure as input
        ret = gpio_pin_configure_dt(&dw1000_irq_pin, GPIO_INPUT);
        if (ret < 0) {
            printk("Failed to configure DW1000 IRQ pin: %d\n", ret);
            return;
        }
        
        // Setup callback
        gpio_init_callback(&dw1000_irq_cb_data, dw1000_irq_handler, 
                           BIT(dw1000_irq_pin.pin));
        
        // Add callback
        ret = gpio_add_callback(dw1000_irq_pin.port, &dw1000_irq_cb_data);
        if (ret < 0) {
            printk("Failed to add DW1000 IRQ callback: %d\n", ret);
            return;
        }
        
        // Enable interrupt (rising edge)
        ret = gpio_pin_interrupt_configure_dt(&dw1000_irq_pin, 
                                               GPIO_INT_EDGE_RISING);
        if (ret < 0) {
            printk("Failed to enable DW1000 IRQ interrupt: %d\n", ret);
            return;
        }
        
        printk("DW1000 interrupt enabled\n");
    } else {
        // Disable interrupt
        gpio_pin_interrupt_configure_dt(&dw1000_irq_pin, GPIO_INT_DISABLE);
        gpio_pin_configure_dt(&dw1000_irq_pin, GPIO_DISCONNECTED);
        printk("DW1000 interrupt disabled\n");
    }
}

/**
 * @fn      port_wakeup_dw1000
 * @brief   "slow" waking up of DW1000 using DW_CS only
 */
void port_wakeup_dw1000(void) {}

/**
 * @fn      port_wakeup_dw1000_fast
 * @brief   waking up of DW1000 using DW_CS and DW_RESET pins.
 *          The DW_RESET signalling that the DW1000 is in the INIT state.
 *          the total fast wakeup takes ~2.2ms and depends on crystal startup
 * time
 */
void port_wakeup_dw1000_fast(void) {}

/*!
 * ------------------------------------------------------------------------------------------------------------------
 * Function: readfromspi()
 *
 * Low level abstract function to read from the SPI
 * Takes two separate byte buffers for write header and read data
 * returns the offset into read buffer where first byte of read data may be
 * found, or returns 0
 */
int readfromspi(uint16 headerLength, const uint8 *headerBuffer,
                uint32 readlength, uint8 *readBuffer) {

    uint8 txBuf[DW1000_MAXBUF];
    uint8 rxBuf[DW1000_MAXBUF];

    if ((headerLength + readlength) > DW1000_MAXBUF) {
        return -1;
    }

    memset(txBuf, 0, headerLength + readlength);
    memcpy(txBuf, headerBuffer, headerLength);

    decaIrqStatus_t stat = decamutexon();  // Lock interrupts
    int err = read_spi(txBuf, rxBuf, readlength + headerLength);
    decamutexoff(stat);  // Unlock interrupts

    if (err != 0) {
        printk("SPI read returned an error (err: %d)\n", err);
        return 1;
    }

    memcpy(readBuffer, rxBuf + headerLength, readlength);

    return 0;
}

int writetospi(uint16 headerLength, const uint8 *headerBuffer,
               uint32 bodylength, const uint8 *bodyBuffer) {

    uint8 txBuf[DW1000_MAXBUF];

    if ((headerLength + bodylength) > DW1000_MAXBUF) {
        return -1;
    }

    memcpy(txBuf, headerBuffer, headerLength);
    memcpy(txBuf + headerLength, bodyBuffer, bodylength);

    decaIrqStatus_t stat = decamutexon();  // Lock interrupts
    int err = write_spi(txBuf, headerLength + bodylength);
    decamutexoff(stat);  // Unlock interrupts

    if (err != 0) {
        printk("SPI write returned an error (err: %d)\n", err);
        return 1;
    }

    return 0;
}

//------------------------------other---------------------------

/**
 * @fn      reset_DW1000
 * @brief   DW_RESET pin on DW1000 has 2 functions
 *          In general it is output, but it also can be used to reset the
 * digital part of DW1000 by driving this pin low. Note, the DW_RESET pin should
 * not be driven high externally.
 */
void reset_DW1000(void) {

    gpio_pin_configure_dt(&dw1000_reset_pin, GPIO_OUTPUT);
    gpio_pin_set_dt(&dw1000_reset_pin, 0);
    k_msleep(2);
    gpio_pin_configure_dt(&dw1000_reset_pin, GPIO_DISCONNECTED);
    k_msleep(2);
}

/**
 * @fn      port_set_dw1000_slowrate
 * @brief   set 2MHz
 *          n
 */
void port_set_dw1000_slowrate(void) {
    set_spi_slow();
    k_msleep(2);
}

/**
 * @fn      port_set_dw1000_fastrate
 * @brief   set 8MHz
 *
 */
void port_set_dw1000_fastrate(void) {
    set_spi_fast();
    k_msleep(2);
}

void deca_sleep(unsigned int time_ms) { k_msleep(time_ms); }

// currently do nothing
decaIrqStatus_t decamutexon(void) {
    return (decaIrqStatus_t)irq_lock();
}

void decamutexoff(decaIrqStatus_t s) {
    irq_unlock((unsigned int)s);
}

/****************************************************************************
 *
 *                          End APP port section
 *
 ****************************************************************************/

/****************************************************************************
 *
 *                              IRQ section
 *
 ****************************************************************************/
static struct gpio_callback dw1000_irq_cb_data;

// IRQ handler that calls dwt_isr
static void dw1000_irq_handler(const struct device *dev, 
                                struct gpio_callback *cb, 
                                uint32_t pins)
{
    dw1000_irq_pending = true;  // Just set flag, don't call dwt_isr
}

// Add this function to be called from main loop
void dw1000_process_irq(void) {
    if (dw1000_irq_pending) {
        dw1000_irq_pending = false;
        dwt_isr();  // Safe to call from thread context
    }
}
/****************************************************************************
 *
 *                              END OF IRQ section
 *
 ****************************************************************************/

/****************************************************************************
 *
 ****************************************************************************/

#endif // defined(CONFIG_ENABLE_BELUGA_UWB)
