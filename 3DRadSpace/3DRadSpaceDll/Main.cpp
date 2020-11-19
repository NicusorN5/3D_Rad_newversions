#include "pch.h"
#include "Main.h"

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

void _3DRadSpaceDll::ObjectManager::InitializeObjects(std::vector<IGameObject*>* arr, ID3D11Device* dev, ID3D11DeviceContext* context)
{
    for (unsigned i = 0; i < arr->size(); i++)
    {
        arr->operator[](i)->Initialize(dev, context);
    }
}

void _3DRadSpaceDll::ObjectManager::DrawObjects(std::vector<IGameObject*>* arr)
{
    for (unsigned i = 0; i < arr->size(); i++)
    {
        arr->operator[](i)->Draw();
    }
}

void _3DRadSpaceDll::ObjectManager::UpdateObjects(std::vector<IGameObject*>* arr, float dt)
{
    for (unsigned i = 0; i < arr->size(); i++)
    {
        arr->operator[](i)->Update(dt);
    }
}
