/*
 * Copyright (c) 2025, Mupen64 maintainers, contributors, and original authors (Azimer, Bobby Smiles).
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

//************ Configuration Section ************** (to be moved to compile time defines)

// Configure the plugin to have a console window for informational output -- should be used for debugging only
// #define USE_PRINTF

#ifdef _WIN32
#define ENABLE_BACKEND_DIRECTSOUND8
#define ENABLE_BACKEND_XAUDIO2
#define ENABLE_BACKEND_COMMON
#endif
// #define ENABLE_BACKEND_PORTAUDIO // NYI

#ifndef _COMMON_DOT_H_
#define _COMMON_DOT_H_

#include <stddef.h>
#include <windows.h>
#include <commctrl.h>
extern OSVERSIONINFOEX OSInfo;

#if defined(_MSC_VER)
#define SEH_SUPPORTED
#endif

#ifdef USE_PRINTF
#define DEBUG_OUTPUT printf
#else
#define DEBUG_OUTPUT //
#endif


#include "my_types.h"

enum SoundDriverType {
    SND_DRIVER_NOSOUND,
    SND_DRIVER_DS8,
    SND_DRIVER_XA2,
};

typedef struct {
    u16 Version;
    u32 BufferSize;
    Boolean doAIHACK;
    Boolean syncAudio;
    Boolean fillAudio;
    Boolean oldStyle;
    Boolean Reserved2;
    Boolean Reserved3;
    u32 Reserved4;
    u32 Reserved5;
    u32 Reserved6;
} rSettings;
extern rSettings RegSettings;
#endif

#define AUDIOCODE 0
#define HLECODE 1
#define CPUCODE 2

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


#ifdef ENABLEPROFILING

extern u64 ProfileStartTimes[30];
extern u64 ProfileTimes[30];

inline void StartProfile(int profile)
{
    u64 start;
    __asm {
			rdtsc;
			mov dword ptr [start+0], eax;
			mov dword ptr [start+4], edx;
    }
    ProfileStartTimes[profile] = start;
}

inline void EndProfile(int profile)
{
    u64 end;
    __asm {
			rdtsc;
			mov dword ptr [end+0], eax;
			mov dword ptr [end+4], edx;
    }
    ProfileTimes[profile] = ProfileTimes[profile] + (end - ProfileStartTimes[profile]);
}
inline void PrintProfiles()
{
    FILE* dfile = fopen("d:\\profile.txt", "wt");
    u64 totalTimes = 0;
    for (int x = 0; x < 30; x++)
    {
        if (ProfileTimes[x] != 0)
        {
            fprintf(dfile, "Times for %i is: %08X %08X\n", x, (u32)(ProfileTimes[x] >> 32), (u32)ProfileTimes[x]);
            totalTimes += ProfileTimes[x];
        }
    }
    for (x = 0; x < 30; x++)
    {
        if (ProfileTimes[x] != 0)
        {
            fprintf(dfile, "Percent Time for %i is: %i%%\n", x, (u32)((ProfileTimes[x] * 100) / totalTimes));
        }
    }
    fclose(dfile);
}
inline void ClearProfiles()
{
    for (int x = 0; x < 30; x++)
    {
        ProfileTimes[x] = 0;
    }
}
#else
#define StartProfile(profile) //
#define EndProfile(profile) //
#define PrintProfiles() //
#define ClearProfiles() //
#endif

/*
 * `strcpy` with bounds checking
 * This basically is a portable variation of Microsoft's `strcpy_s`.
 */
extern int safe_strcpy(char* dst, size_t limit, const char* src);
