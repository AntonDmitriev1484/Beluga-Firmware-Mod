#ifndef CIR_BUFFER_H
#define CIR_BUFFER_H

// 1. System Headers
#include <stdint.h>
#include <stdbool.h>

// 2. Project Headers (use angle brackets for system-like paths)
#include <deca_device_api.h>

// 3. Custom Type Definitions
// Defines a complex number for the CIR data.
typedef struct {
    int16_t real;
    int16_t imag;
} dwt_complex_t;

// 4. Defines
// The number of CIR data sets the buffer can hold. Set to 1 to conserve RAM.
#define CIR_BUFFER_SIZE 1
// The number of CIR samples to capture. Reduced from 1016 to fit in RAM.
#define CIR_SAMPLES_TO_READ 128

// 5. Shared Structure Definition
// This defines the structure of our circular buffer.
typedef struct {
    dwt_complex_t data[CIR_BUFFER_SIZE][CIR_SAMPLES_TO_READ];
    volatile uint8_t head; // Written to by the ISR
    volatile uint8_t tail; // Read from by the application thread
} cir_ring_buffer_t;

// 6. External Variable Declaration
// Announces the global buffer variable exists and will be created elsewhere.
extern cir_ring_buffer_t cir_buffer;

#endif // CIR_BUFFER_H