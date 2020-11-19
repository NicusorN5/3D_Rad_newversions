#pragma once
#include <vector>
#include "Camera.h"
#include <d3d11.h>

namespace _3DRadSpaceDll
{
	class __declspec(dllexport) ObjectManager
	{
	public:
		static void InitializeObjects(std::vector<IGameObject*>* arr, ID3D11Device* dev, ID3D11DeviceContext* context);
		static void DrawObjects(std::vector<IGameObject*>* arr);
		static void UpdateObjects(std::vector<IGameObject*>* arr,float dt);
	};
}