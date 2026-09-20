/* Copyright (c) 2025 Daniel Rossinsky (https://github.com/rtsworks) */
/* SPDX-License-Identifier: MIT                                      */

#include "util/calc.h"

/* --------------------------- STANDARD INCLUDES ---------------------------- */

/* ----------------------------- USER INCLUDES ------------------------------ */

#include "util/mul.h"

/* --------------------------------- MACROS --------------------------------- */

/* --------------------------------- ENUMS ---------------------------------- */

/* --------------------------------- TYPES ---------------------------------- */

/* ------------------------- FILE-STATIC VARIABLES -------------------------- */

/* --------------------------- PRIVATE FUNCTIONS ---------------------------- */

/* ---------------------------- PUBLIC FUNCTIONS ---------------------------- */

int32_t util_calc_add(int32_t lhs, int32_t rhs)
{
    return lhs + rhs;
}

int32_t util_calc_sub(int32_t lhs, int32_t rhs)
{
    return lhs - rhs;
}

int32_t util_calc_mul(int32_t lhs, int32_t rhs)
{
    return util_mul(lhs, rhs);
}
