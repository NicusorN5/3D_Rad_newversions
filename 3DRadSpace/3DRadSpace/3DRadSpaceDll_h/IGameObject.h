#pragma once
namespace _3DRadSpaceDll
{
	class __declspec(dllexport) IGameObject
	{
	public:
		virtual char* Save() = 0;
		virtual void* Load(char* buffer, size_t req_size) = 0;
		virtual void Draw() = 0;
		virtual void Update(float dt) = 0;
		virtual ~IGameObject() {};
	};
}

