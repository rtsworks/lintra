/* Copyright (c) 2025 Daniel Rossinsky (https://github.com/rtsworks) */
/* SPDX-License-Identifier: MIT                                      */

/*******************************************************************************
 * @file
 * @brief Mockable GPIO HAL.
 ******************************************************************************/

#ifndef HAL_GPIO_H
#define HAL_GPIO_H

/** @brief HAL GPIO pin number enumeration. */
typedef enum hal_gpio_pin_e
{
    GPIO_PIN_0,    /**< GPIO pin number 0 */
    GPIO_PIN_1,    /**< GPIO pin number 1 */
    /* As much as needed... */
    GPIO_PIN_COUNT /**< GPIO pin count    */ 
} hal_gpio_pin_e;

/** @brief HAL GPIO pin direction enumeration. */
typedef enum hal_gpio_dir_e
{
    GPIO_PIN_IN, /**< GPIO pin input  */
    GPIO_PIN_OUT /**< GPIO pin output */
} hal_gpio_dir_e;

/** @brief HAL GPIO pin value enumeration. */
typedef enum hal_gpio_value_e
{
    GPIO_PIN_LOW, /**< GPIO value low  */
    GPIO_PIN_HIGH /**< GPIO value high */
} hal_gpio_value_e;

/**
 * @brief Initialize the specified GPIO pin as input/output.
 * @param pin pin number from @ref hal_gpio_pin_e
 * @param dir direction from @ref hal_gpio_dir_e
 */
void hal_gpio_pin_init(hal_gpio_pin_e pin, hal_gpio_dir_e dir);

/**
 * @brief Write a value to the selected gpio pin.
 * @param pin   pin number from @ref hal_gpio_pin_e
 * @param value value from @ref hal_gpio_value_e
 */
void hal_gpio_pin_write(hal_gpio_pin_e pin, hal_gpio_value_e value);

/**
 * @brief Read the value of a GPIO pin.
 * @param pin pin number from @ref hal_gpio_pin_e.
 * @return Value from @ref hal_gpio_value_e.
 * @retval GPIO_PIN_LOW  pin value is logic low
 * @retval GPIO_PIN_HIGH pin value is logic high
 */
hal_gpio_value_e hal_gpio_pin_read(hal_gpio_pin_e pin);

#endif /* HAL_GPIO_H */