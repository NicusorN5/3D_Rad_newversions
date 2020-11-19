#pragma once
#include <vector>
#include "IGameObject.h"
#include <fstream>

namespace _3DRadSpaceDll
{
	class __declspec(dllexport) Project
	{
		void* _pBuffer;
		size_t _nBuffer;
	public:
		char* Path;
		char* Name;
		int Version;
		Project(char* path) : Path(path), _pBuffer(nullptr), _nBuffer(0),Name(nullptr),Version(0) {};
		void Load(std::vector<IGameObject*>* list);
	};
}

