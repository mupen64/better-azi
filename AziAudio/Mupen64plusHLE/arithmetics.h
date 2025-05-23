/*
 * Copyright (c) 2025, Mupen64 maintainers, contributors, and original authors (Azimer, Bobby Smiles).
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#ifndef ARITHMETICS_H
#define ARITHMETICS_H

#include "common.h"

/*
 * 2015.05.05 modified by cxd4
 * The <stdint.h> `INT16_MIN' macro is a dependency of this RSP HLE code.
 * In practice, there are two problems with this:
 *     1.  <stdint.h> can (rather, must) define `INT16_MIN' as -32767 instead
 *         of the necessary -32768, as <stdint.h> is irrelevant to RSP
 *         hardware limitations and is really more about the host's CPU.
 *         http://www.open-std.org/jtc1/sc22/wg14/www/docs/n761.htm
 *     2.  Not everybody has a working <stdint.h>, nor should they need to,
 *         as its existence is based on the opinion that the C language
 *         itself should arbitrate traditional-size types for the programmer.
 *         As none of the <stdint.h> types are scientifically essential to
 *         valid CPU hardware, such C impl. requirements are for laziness.
 */
#if !defined(INT16_MIN) && !defined(INT16_MAX)
#define INT16_MIN -32768
#define INT16_MAX +32767
#endif

static inline int16_t clamp_s16(int32_t x)
{
    x = (x < INT16_MIN) ? INT16_MIN : x;
    x = (x > INT16_MAX) ? INT16_MAX : x;

    return (int16_t)x;
}

#endif
