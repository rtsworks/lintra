/* Copyright (c) 2025 Daniel Rossinsky (https://github.com/rtsworks) */
/* SPDX-License-Identifier: MIT                                      */

/* Standard library includes */
#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>

/* User code includes */
#include "util/calc.h"
#include "led/led.h"

int main(void)
{
    int32_t add = util_calc_add(10, 10);
    int32_t sub = util_calc_sub(10, -5);
    int32_t mul = util_calc_mul(2, 5);

    led_init();
    led_on();
    led_off();
    int state = led_state();
    
    (void)printf("add: %" PRIu32 "\n", add);
    (void)printf("sub: %" PRIu32 "\n", sub);
    (void)printf("mul: %" PRIu32 "\n", mul);
    (void)printf("state: %d\n", state);

    return 0;
}