/*
 * Copyright (c) 2025, Mupen64 maintainers, contributors, and original authors (Azimer, Bobby Smiles).
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include "audiohle.h"

void UNKNOWN()
{
}

p_func ABI2[NUM_ABI_COMMANDS] = {
SPNOOP,
ADPCM2,
CLEARBUFF2,
UNKNOWN,
ADDMIXER,
RESAMPLE2,
UNKNOWN,
SEGMENT2,
SETBUFF2,
DUPLICATE2,
DMEMMOVE2,
LOADADPCM2,
MIXER2,
INTERLEAVE2,
HILOGAIN,
SETLOOP2,
SPNOOP,
INTERL2,
ENVSETUP1,
ENVMIXER2,
LOADBUFF2,
SAVEBUFF2,
ENVSETUP2,
SPNOOP,
HILOGAIN,
SPNOOP,
DUPLICATE2,
UNKNOWN,
SPNOOP,
SPNOOP,
SPNOOP,
SPNOOP,
};
