#pragma once
#include <string>

/*Helper class build for binary IO support*/

class ByteStream
{
	size_t _pos;
	char* _buff;
	size_t _size;
public:
	ByteStream(size_t size) : _pos(0), _buff(new char[size]), _size(size) {};
	ByteStream(char* buff, size_t size) : _pos(0), _buff(buff), _size(size) {};
	ByteStream() : _buff(nullptr), _pos(0), _size(0) {};
	
	void SetPos(size_t pos);
	void ShiftPos(size_t add_pos);

	template<class T>
	T Get();

	template <class T>
	void Set(T val);
};