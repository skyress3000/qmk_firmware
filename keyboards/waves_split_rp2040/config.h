// Copyright 2023 Ray Wendt (@skyress3000)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT

#define SERIAL_DEBUG

#define I2C_DRIVER I2CD0
#define I2C1_SCL_PIN GP29
#define I2C1_SDA_PIN GP28

#define I2C1_CLOCK_SPEED 100000L

#define LED_DRIVER_ADDR_1 0b1110100

#define LED_DRIVER_COUNT 1
#define LED_MATRIX_LED_COUNT 61
#define LED_MATRIX_SPLIT { 30, 31 }

#define ENABLE_LED_MATRIX_BREATHING // BREATHING
#define LED_MATRIX_DEFAULT_SPD 32
#define LED_MATRIX_DEFAULT_MODE LED_MATRIX_BREATHING // LED_MATRIX_BREATHING

// split configuration

#define SPLIT_HAND_PIN GP7          // GP7 low = right half

#define SERIAL_USART_FULL_DUPLEX    // Enable full duplex operation mode.
#define SERIAL_USART_TX_PIN GP1     // USART TX pin
#define SERIAL_USART_RX_PIN GP0     // USART RX pin

#define SPLIT_LAYER_STATE_ENABLE