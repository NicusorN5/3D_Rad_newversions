#pragma once
#include "MeshPart.h"
namespace _3DRadSpaceDll
{
	class Mesh
	{
	public:
		MeshPart** Parts;
		size_t PartsNum;
		Mesh() : Parts(nullptr),PartsNum(0) {};
		Mesh(MeshPart* submeshes, size_t s) : Parts(&submeshes), PartsNum(s) {};
		Mesh(MeshPart** submeshes, size_t s) : Parts(submeshes), PartsNum(s) {};
	};
}

