/* Copyright (c) 2025 Daniel Rossinsky (https://github.com/rtsworks) */
/* SPDX-License-Identifier: MIT                                      */

/*******************************************************************************
 * @file
 * @brief LED library.
 ******************************************************************************/

#ifndef LED_H
#define LED_H

/** @brief Initialize the led. */
void led_init(void);

/** @brief Turn the led on. */
void led_on(void);

/** @brief Turn the led off. */
void led_off(void);

/**
 * @brief Get the current state of the led.
 * @return 1 if led is on, otherwise 0. 
 */
int led_state(void);

#endif /* LED_H */