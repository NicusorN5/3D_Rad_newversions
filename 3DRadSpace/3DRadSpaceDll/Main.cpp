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

void _3DRadSpaceDll::ObjectManager::InitializeObjects(std::vector<GameObject*>* arr, ID3D11Device* dev, ID3D11DeviceContext* context)
{
    for (int i = 0; i < arr->size(); i++)
    {
       std::string type = typeid(*arr->operator[](i)).name();
       if (type.compare("class _3DRadSpaceDll::Camera*") == 0)
       {
           Camera* cam = dynamic_cast<Camera*>(arr->operator[](i));
           cam->Initialize(dev, context);
           continue;
       }
    }
}

void _3DRadSpaceDll::ObjectManager::DrawObjects(std::vector<GameObject*>* arr)
{
    for (int i = 0; i < arr->size(); i++)
    {
        std::string type = typeid(*arr->operator[](i)).name();
        if (type.compare("class _3DRadSpaceDll::Camera*") == 0)
        {
            Camera* cam = dynamic_cast<Camera*>(arr->operator[](i));
            cam->Draw();
            continue;
        }
    }
}

void _3DRadSpaceDll::ObjectManager::UpdateObjects(std::vector<GameObject*>* arr, float dt)
{
    for (int i = 0; i < arr->size(); i++)
    {
        std::string type = typeid(*arr->operator[](i)).name();
        if (type.compare("class _3DRadSpaceDll::Camera*") == 0)
        {
            Camera* cam = dynamic_cast<Camera*>(arr->operator[](i));
            cam->Update(dt);
            continue;
        }
    }
}
