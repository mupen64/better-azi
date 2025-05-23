/*
 * Copyright (c) 2025, Mupen64 maintainers, contributors, and original authors (Azimer, Bobby Smiles).
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#ifndef COMMON_H
#define COMMON_H

#include "../my_types.h"

/* macro for unused variable warning suppression */
#ifdef __GNUC__
#define UNUSED(x) UNUSED_##x __attribute__((__unused__))
#else
#define UNUSED(x) UNUSED_##x
#endif

/* macro for inline keyword */
#ifdef _MSC_VER
#define inline __inline
#elif defined(__GNUC_GNU_INLINE__)
#define inline
#endif

#endif
