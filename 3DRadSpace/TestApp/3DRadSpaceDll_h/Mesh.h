#pragma once
#include "MeshPart.h"
namespace _3DRadSpaceDll
{
	template <class T>
	class _declspec(dllexport) Mesh
	{
	public:
		MeshPart<T>** Parts;
		size_t PartsNum;
		Mesh() : Parts(nullptr),PartsNum(0) {};
		Mesh(MeshPart<T>* submeshes, size_t s) : Parts(&submeshes), PartsNum(s) {};
		Mesh(MeshPart<T>** submeshes, size_t s) : Parts(submeshes), PartsNum(s) {};
	};
}

