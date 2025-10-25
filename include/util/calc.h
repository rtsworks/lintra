/* Copyright (c) 2025 Daniel Rossinsky (https://github.com/rtsworks) */
/* SPDX-License-Identifier: MIT                                      */

/*******************************************************************************
 * @file
 * @brief Calculator library.
 ******************************************************************************/

#ifndef UTIL_CALC_H
#define UTIL_CALC_H

/* Standard library includes */
#include <stdint.h>

/**
 * @brief Add one value with another
 * @param lhs left hand side value
 * @param rhs right hand side value
 * @return The result of lhs + rhs. 
 */
int32_t util_calc_add(int32_t lhs, int32_t rhs);

/**
 * @brief Subtract one value from another.
 * @param lhs left hand side value
 * @param rhs right hand side value
 * @return The result of lhs - rhs. 
 */
int32_t util_calc_sub(int32_t lhs, int32_t rhs);

/**
 * @brief multiply one value with another
 * @param lhs left hand side value
 * @param rhs right hand side value
 * @return The result of lhs * rhs.
 */
int32_t util_calc_mul(int32_t lhs, int32_t rhs);

#endif /* UTIL_CALC_H */