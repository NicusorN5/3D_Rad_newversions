#include "pch.h"
#include "Main.h"

void _3DRadSpaceDll::Main::AddObject(GameObject* object)
{
    _objects.push_back(object);
}

void _3DRadSpaceDll::Main::RemoveObject(size_t index)
{
    _objects.erase(_objects.begin() - (index-1));
}

_3DRadSpaceDll::GameObject* _3DRadSpaceDll::Main::FindObject(size_t index)
{
    return _objects[index];
}

BOOL WINAPI DllMain(
    HINSTANCE hinstDLL,  // handle to DLL module
    DWORD fdwReason,     // reason for calling function
    LPVOID lpReserved)  // reserved
{
    // Perform actions based on the reason for calling.
    switch (fdwReason)
    {
    case DLL_PROCESS_ATTACH:
        // Initialize once for each new process.
        // Return FALSE to fail DLL load.
        break;

    case DLL_THREAD_ATTACH:
        // Do thread-specific initialization.
        break;

    case DLL_THREAD_DETACH:
        // Do thread-specific cleanup.
        break;

    case DLL_PROCESS_DETACH:
        // Perform any necessary cleanup.
        break;
    }
    return TRUE;  // Successful DLL_PROCESS_ATTACH.
}