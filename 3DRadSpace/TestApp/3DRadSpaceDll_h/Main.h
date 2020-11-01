#pragma once
#include <vector>
#include "Camera.h"
#include <d3d11.h>

namespace _3DRadSpaceDll
{
	class __declspec(dllexport) ObjectManager
	{
	public:
		static void InitializeObjects(std::vector<GameObject*>* arr, ID3D11Device* dev, ID3D11DeviceContext* context);
		static void DrawObjects(std::vector<GameObject*>* arr);
		static void UpdateObjects(std::vector<GameObject*>* arr,float dt);
	};
}

