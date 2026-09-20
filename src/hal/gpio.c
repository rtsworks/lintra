/* Copyright (c) 2025 Daniel Rossinsky (https://github.com/rtsworks) */
/* SPDX-License-Identifier: MIT                                      */

#include "hal/gpio.h"

/* --------------------------- STANDARD INCLUDES ---------------------------- */

/* ----------------------------- USER INCLUDES ------------------------------ */

/* --------------------------------- MACROS --------------------------------- */

/* --------------------------------- ENUMS ---------------------------------- */

/* --------------------------------- TYPES ---------------------------------- */

/* ------------------------- FILE-STATIC VARIABLES -------------------------- */

/* --------------------------- PRIVATE FUNCTIONS ---------------------------- */

/* ---------------------------- PUBLIC FUNCTIONS ---------------------------- */

void hal_gpio_pin_init(hal_gpio_pin_e pin, hal_gpio_dir_e dir)
{
    /* Do nothing, this file will be mocked */
    (void)pin;
    (void)dir;
}

void hal_gpio_pin_write(hal_gpio_pin_e pin, hal_gpio_value_e value)
{
    /* Do nothing, this file will be mocked */
    (void)pin;
    (void)value;
}

hal_gpio_value_e hal_gpio_pin_read(hal_gpio_pin_e pin)
{
    /* Do nothing, this file will be mocked */
    (void)pin;
    return GPIO_PIN_LOW;
}
