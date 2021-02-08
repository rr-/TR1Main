#include <windows.h>
#include <stdio.h>

#include "struct.h"
#include "util.h"
#include "func.h"

HINSTANCE hInstance = NULL;

static void Inject() {
    INJECT(0x0042A2C0, DB_Log);
    INJECT(0x0041C020, FindCdDrive);
    INJECT(0x0041BFC0, GetFullPath);
    INJECT(0x0041B3F0, LoadRooms);
    INJECT(0x0041E2C0, init_game_malloc);
    INJECT(0x0041E3B0, game_free);

    INJECT(0x0041BC60, LoadItems);
    INJECT(0x00428020, InitialiseLara);
    INJECT(0x0041AF90, LoadLevelByID);
    INJECT(0x0041D5A0, LevelStats);

    //INJECT(0x00402710, my_ins_line);

    //INJECT(0x004302D0, S_DrawHealthBar);
    //INJECT(0x00430450, S_DrawAirBar);
}

BOOL APIENTRY DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved) {
    switch (fdwReason) {
        case DLL_PROCESS_ATTACH:
            freopen("./TR1Main.log", "w", stdout);
            TRACE("Attached");
            hInstance = hinstDLL;
            Inject();
            break;

        case DLL_PROCESS_DETACH:
            TRACE("Detached");
            break;

        case DLL_THREAD_ATTACH:
            break;

        case DLL_THREAD_DETACH:
            break;
    }

    return TRUE;
}
