/* Copyright (c) 2025 Daniel Rossinsky (https://github.com/rtsworks) */
/* SPDX-License-Identifier: MIT                                      */

#include "led/led.h"

/* User code includes */
#include "hal/gpio.h"

void led_init(void)
{
    hal_gpio_pin_init(GPIO_PIN_0, GPIO_PIN_OUT);
}

void led_on(void)
{
    hal_gpio_pin_write(GPIO_PIN_0, GPIO_PIN_HIGH);
}

void led_off(void)
{
    hal_gpio_pin_write(GPIO_PIN_0, GPIO_PIN_LOW);
}

int led_state(void)
{
    return hal_gpio_pin_read(GPIO_PIN_0);
}