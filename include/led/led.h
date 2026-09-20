/* Copyright (c) 2025 Daniel Rossinsky (https://github.com/rtsworks) */
/* SPDX-License-Identifier: MIT                                      */

/*******************************************************************************
 * @file
 * @ingroup led
 * @brief LED library.
 ******************************************************************************/

#ifndef LED_H
#define LED_H

/* --------------------------- STANDARD INCLUDES ---------------------------- */

/* ----------------------------- USER INCLUDES ------------------------------ */

/**
 * @brief LED driver built on top of @ref hal_gpio.
 * @defgroup led LED
 * @since 1.0.0
 * @version 1.0.0
 * @details Call @ref led_init once before using any other function of this
 *          module.
 *
 * @par Example
 * @code
 * led_init();
 * led_on();
 *
 * if (led_state() == 1) {
 *     led_off();
 * }
 * @endcode
 * @{
 */

/* --------------------------------- MACROS --------------------------------- */

/* --------------------------------- ENUMS ---------------------------------- */

/* --------------------------------- TYPES ---------------------------------- */

/* ------------------------- FUNCTION DECLARATIONS -------------------------- */

/**
 * @brief Initialize the led.
 * @details Configures the underlying GPIO pin as an output.
 */
void led_init(void);

/** @brief Turn the led on. */
void led_on(void);

/** @brief Turn the led off. */
void led_off(void);

/**
 * @brief Get the current state of the led.
 * @return The current led state.
 * @retval 1 led is on
 * @retval 0 led is off
 */
int led_state(void);

/** @} */

#endif /* LED_H */
