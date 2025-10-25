/* Copyright (c) 2025 Daniel Rossinsky (https://github.com/rtsworks) */
/* SPDX-License-Identifier: MIT                                      */

/*******************************************************************************
 * @file
 * @brief Multiplier library.
 ******************************************************************************/

#ifndef UTIL_MUL_H
#define UTIL_MUL_H

/* Standard library includes */
#include <stdint.h>

/**
 * @brief multiply one value with another
 * @param lhs left hand side value
 * @param rhs right hand side value
 * @return The result of lhs * rhs.
 */
int32_t util_mul(int32_t lhs, int32_t rhs);

#endif /* UTIL_MUL_H */