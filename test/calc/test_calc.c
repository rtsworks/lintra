/* Copyright (c) 2025 Daniel Rossinsky (https://github.com/rtsworks) */
/* SPDX-License-Identifier: MIT                                      */

#ifdef TEST

/* Third party includes */
#include "unity.h"

/* User code includes */
#include "util/calc.h"

/* Tell Ceedling to inject the following sources */
TEST_SOURCE_FILE("util/calc.c")
TEST_SOURCE_FILE("util/mul.c")

void setUp(void)
{
    /* No setup needed */
}

void tearDown(void) 
{
    /* No teardown needed */
}

void test_add_two_i32_numbers(void)
{
    TEST_ASSERT_EQUAL_INT32(21, util_calc_add(20, 1));
}

void test_sub_two_i32_numbers(void)
{
    TEST_ASSERT_EQUAL_INT32(2, util_calc_sub(6, 4));
}

void test_mul_two_i32_numbers(void)
{
    TEST_ASSERT_EQUAL_INT32(10, util_calc_mul(2, 5));
}

#endif