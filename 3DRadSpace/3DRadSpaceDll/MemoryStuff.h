#pragma once

template<class T>
T** _newdp(size_t size)
{
	T** ret = new T * [size];
	for (size_t i = 0; i < size; i++) ret[i] = new T;
	return ret;
}