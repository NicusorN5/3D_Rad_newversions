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
}

