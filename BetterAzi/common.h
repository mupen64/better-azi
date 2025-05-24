/*
 * Copyright (c) 2025, Mupen64 maintainers, contributors, and original authors (Azimer, Bobby Smiles).
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#pragma once

#include <cstdint>
#include <core_plugin.h>

#define DEBUG_OUTPUT

enum SoundDriverType {
    SND_DRIVER_NOSOUND,
    SND_DRIVER_DS8,
    SND_DRIVER_XA2,
};

extern core_audio_info AudioInfo;

void HLEStart();
void ChangeABI(int type); /* type 0 = SafeMode */

#define AI_STATUS_FIFO_FULL 0x80000000 /* Bit 31: full */
#define AI_STATUS_DMA_BUSY 0x40000000 /* Bit 30: busy */
#define MI_INTR_AI 0x04 /* Bit 2: AI intr */
#define AI_CONTROL_DMA_ON 0x01

#define PLUGIN_VERSION "1.0.0-rc1"

#ifdef _M_X64
#define PLUGIN_ARCH " x64"
#else
#define PLUGIN_ARCH " x86"
#endif

#ifdef _DEBUG
#define PLUGIN_TARGET " Debug"
#else
#define PLUGIN_TARGET " Release"
#endif

#define PLUGIN_FULL_NAME "BetterAzi " PLUGIN_VERSION PLUGIN_ARCH PLUGIN_TARGET
