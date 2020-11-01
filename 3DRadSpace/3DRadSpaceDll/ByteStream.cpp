#include "pch.h"
#include "ByteStream.h"

void ByteStream::SetPos(size_t pos)
{
	_pos = pos;
}

void ByteStream::ShiftPos(size_t add_pos)
{
	_pos += add_pos;
}

template<class T>
inline T ByteStream::Get()
{
	T* ret = static_cast<T*>(_buff[_pos]);
	_pos += sizeof(T);
	return *ret;
}

template<class T>
inline void ByteStream::Set(T val)
{
	memcpy_s(_buff + _pos, sizeof(T), &val, sizeof(val));
	_pos += sizeof(T);
}
