#pragma once
#include <vector>
#include "GameObject.h"

namespace _3DRadSpaceDll
{
	enum GameObjectType : size_t
	{
		Unknown,
		Baseclass_Gameobject,
		Camera,
		Script_CS,
		Script_LUA,
		Skinmesh,
	};

	class __declspec(dllexport) Main
	{
	private:
		std::vector<GameObject*> _objects;
	public:
		void AddObject(GameObject* object);
		void RemoveObject(size_t index);
		GameObject* FindObject(size_t index);
	};
}

