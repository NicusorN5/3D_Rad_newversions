#include "pch.h"
#include "Project.h"

void _3DRadSpaceDll::Project::Load(std::vector<IGameObject*>* list)
{
	std::fstream file(this->Name, std::ios::binary | std::ios::ate | std::ios::in);
	std::streampos fsize = file.tellg();
	file.seekg(0,std::ios::beg);

	std::vector<char> fbuff(fsize);

	size_t pos = 0;

	this->Name = fbuff.data();

	pos += strlen(fbuff.data()) + 1;
	void* buff = fbuff.data() + pos;

	memcpy_s(&this->Version, sizeof(int), buff, sizeof(int));
	

}
