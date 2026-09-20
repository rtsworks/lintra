/* Copyright (c) 2025 Daniel Rossinsky (https://github.com/rtsworks) */
/* SPDX-License-Identifier: MIT                                      */

/*******************************************************************************
 * @file
 * @ingroup util_calc
 * @brief Calculator library.
 ******************************************************************************/

#ifndef UTIL_CALC_H
#define UTIL_CALC_H

/* --------------------------- STANDARD INCLUDES ---------------------------- */

#include <stdint.h>

/* ----------------------------- USER INCLUDES ------------------------------ */

/**
 * @brief Basic integer arithmetic.
 * @defgroup util_calc Calculator
 * @ingroup util
 * @since 1.0.0
 * @version 1.0.0
 *
 * @par Example
 * @code
 * int32_t sum  = util_calc_add(10, 10);
 * int32_t diff = util_calc_sub(10, -5);
 * int32_t prod = util_calc_mul(2, 5);
 * @endcode
 * @{
 */

/* --------------------------------- MACROS --------------------------------- */

/* --------------------------------- ENUMS ---------------------------------- */

/* --------------------------------- TYPES ---------------------------------- */

/* ------------------------- FUNCTION DECLARATIONS -------------------------- */

/**
 * @brief Add one value to another.
 * @param[in] lhs left hand side value
 * @param[in] rhs right hand side value
 * @return The result of lhs + rhs.
 */
int32_t util_calc_add(int32_t lhs, int32_t rhs);

/**
 * @brief Subtract one value from another.
 * @param[in] lhs left hand side value
 * @param[in] rhs right hand side value
 * @return The result of lhs - rhs.
 */
int32_t util_calc_sub(int32_t lhs, int32_t rhs);

/**
 * @brief Multiply one value with another.
 * @details Delegates to @ref util_mul.
 * @param[in] lhs left hand side value
 * @param[in] rhs right hand side value
 * @return The result of lhs * rhs.
 */
int32_t util_calc_mul(int32_t lhs, int32_t rhs);

/** @} */

#endif /* UTIL_CALC_H */
