#pragma once

template<class T>
T** _newdp(size_t size)
{
	T** ret = new T * [size];
	for (size_t i = 0; i < size; i++) ret[i] = new T;
	return ret;
}

template<class T>
void _deletedp(T** p, size_t size)
{
	for (size_t i = 0; i < size; i++) delete p[i];
	delete[] p;
}

template<class T>
void MemCopyT(T* dst,T* source)
{
	memcpy_s(dst, sizeof(T), source, sizeof(T));
}

