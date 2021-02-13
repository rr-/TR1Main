#ifndef TR1M_GAME_SHELL_H
#define TR1M_GAME_SHELL_H

#include "util.h"

// clang-format off
#define game_malloc             ((void          __cdecl*(*)(uint32_t length, int type))0x0041E2F0)
#define _fread                  ((size_t        __cdecl(*)(void *, size_t, size_t, FILE *))0x00442C20)
#define LoadLevel               ((int           __cdecl(*)(const char *path, int level_id))0x0041AFB0)
#define S_ExitSystem            ((void          __cdecl(*)(const char *message))0x0041E260)
#define S_DumpScreen            ((void          __cdecl(*)())0x0042FC70)
#define S_InitialisePolyList    ((void          __cdecl(*)())0x0042FC60)
#define S_UpdateInput           ((void          __cdecl(*)())0x0041E550)
#define S_CopyBufferToScreen    ((void          __cdecl(*)())0x00416A60)
#define S_OutputPolyList        ((void          __cdecl(*)())0x0042FD10)
#define S_FadeToBlack           ((void          __cdecl(*)())0x0041CD10)
#define S_DrawUISprite          ((void          __cdecl(*)(int32_t x, int32_t y, int32_t scale, int16_t sprnum, int16_t brightness))0x00435D80)
#define S_SaveGame              ((void          __cdecl(*)())0x0041DB70)
#define S_CDLoop                ((void          __cdecl(*)())0x004380B0)
#define TempVideoRemove         ((void          __cdecl(*)())0x004167D0)
#define TempVideoAdjust         ((void          __cdecl(*)(int hires, double sizer))0x00416550)
#define ShowFatalError          ((void          __cdecl(*)(const char *message))0x0043D770)
#define WriteTombAtiSettings    ((void          __cdecl(*)())0x0045A084)
#define Insert2DLine            ((void          __cdecl(*)(int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t z, uint8_t color))0x00402710)
// clang-format on

void __cdecl init_game_malloc();
void __cdecl game_free(int free_size);
const char* __cdecl GetFullPath(const char* filename);
int __cdecl FindCdDrive();
int __cdecl LoadRooms(FILE* fp);
int __cdecl LoadItems(FILE* handle);
void __cdecl DB_Log(char* a1, ...);
int __cdecl S_LoadLevel(int level_id);
void __cdecl S_DrawHealthBar(int percent);
void __cdecl S_DrawAirBar(int percent);

void TR1MInjectShell();

#endif