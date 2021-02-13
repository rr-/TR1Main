#ifndef TR1MAIN_GAME_EFFECTS_H
#define TR1MAIN_GAME_EFFECTS_H

#include <stdint.h>
#include "game/types.h"

// clang-format off
#define SoundEffect             ((int32_t       __cdecl(*)(int32_t sfx_num, PHD_3DPOS *pos, uint32_t flags))0x0042AA30)
#define SoundEffects            ((void          __cdecl(*)())0x0041A2A0)
// clang-format on

#endif