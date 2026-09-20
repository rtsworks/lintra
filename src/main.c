/* Copyright (c) 2025 Daniel Rossinsky (https://github.com/rtsworks) */
/* SPDX-License-Identifier: MIT                                      */

/* --------------------------- STANDARD INCLUDES ---------------------------- */

#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

/* ----------------------------- USER INCLUDES ------------------------------ */

#include "led/led.h"
#include "util/calc.h"

/* ---------------------------- PUBLIC FUNCTIONS ---------------------------- */

int main(void)
{
    int32_t add = util_calc_add(10, 10);
    int32_t sub = util_calc_sub(10, -5);
    int32_t mul = util_calc_mul(2, 5);

    led_init();
    led_on();
    led_off();
    int state = led_state();

    /* cppcheck-suppress misra-c2012-21.6 */
    /* The demo program prints its results to stdout. */
    (void)printf("add: %" PRIu32 "\n", add);
    /* cppcheck-suppress misra-c2012-21.6 */
    /* The demo program prints its results to stdout. */
    (void)printf("sub: %" PRIu32 "\n", sub);
    /* cppcheck-suppress misra-c2012-21.6 */
    /* The demo program prints its results to stdout. */
    (void)printf("mul: %" PRIu32 "\n", mul);
    /* cppcheck-suppress misra-c2012-21.6 */
    /* The demo program prints its results to stdout. */
    (void)printf("state: %d\n", state);

    return 0;
}