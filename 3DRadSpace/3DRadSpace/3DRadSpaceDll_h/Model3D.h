#pragma once
#include "assimp/mesh.h"
#include "assimp/anim.h"
#include "assimp/Importer.hpp"
#include "assimp/ai_assert.h"
#include "assimp/postprocess.h"
#include "assimp/scene.h"
#include "assimp/mesh.h"
#include "assimp/types.h"
#include "Mesh.h"
#include "MeshPart.h"
#include "MemoryStuff.h"

namespace _3DRadSpaceDll
{
	class Model3D
	{
	public:
		Mesh** Meshes;
		size_t NumMeshes;
		Model3D(): Meshes(nullptr),NumMeshes(0) {};
		/*
		Loads a 3D model without supporting 3D animations.
		*/
		bool InitializeFromFileBasic(char* file);
	};
}

