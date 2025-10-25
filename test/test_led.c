/* Copyright (c) 2025 Daniel Rossinsky (https://github.com/rtsworks) */
/* SPDX-License-Identifier: MIT                                      */

#ifdef TEST

/* Third party includes */
#include "unity.h"

/* Generate mocks for the following */
#include "mock_gpio.h" /* Mock include/hal/gpio.h */

/* User code includes */
#include "led/led.h"

/* Tell Ceedling to inject the following sources */
TEST_SOURCE_FILE("led/led.c")

void setUp(void)
{
    /* No setup needed */
}

void tearDown(void) 
{
    /* No teardown needed */
}

void test_led_init(void)
{
    /* Make sure the mock_gpio expects a gpio_pin_init */
    hal_gpio_pin_init_Expect(GPIO_PIN_0, GPIO_PIN_OUT);
    /* Test if it is called */
    led_init();
}

void test_led_on(void)
{
    /* Make sure the mock_gpio expects a gpio_pin_write */
    hal_gpio_pin_write_Expect(GPIO_PIN_0, GPIO_PIN_HIGH);
    /* Test if it is called */
    led_on();
}

void test_led_off(void)
{
    /* Make sure the mock_gpio expects a gpio_pin_write */
    hal_gpio_pin_write_Expect(GPIO_PIN_0, GPIO_PIN_LOW);
    /* Test if it is called */
    led_off();
}

void test_led_state(void)
{
    /* Make sure the mock_gpio expects a gpio_pin_read with a return */
    hal_gpio_pin_read_ExpectAndReturn(GPIO_PIN_0, GPIO_PIN_LOW);
    /* Test if it is called */
    int state = led_state();
    /* The expected value was returned ? */
    TEST_ASSERT_EQUAL(GPIO_PIN_LOW, state);
}

#endif