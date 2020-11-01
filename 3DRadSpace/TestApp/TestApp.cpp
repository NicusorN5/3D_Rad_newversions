#include <iostream>
#include "3DRadSpaceDll_h/Math.h"
#include "3DRadSpaceDll_h/Camera.h"

using namespace _3DRadSpaceDll;

void show_bytes(void* obj, size_t size)
{
	const char* bytes = static_cast<const char*>(obj);
	printf("%02x [",obj);
	for (int i = 0; i < size; i++) printf("%02x ", bytes[i]);
	printf("] \r\n");
}

std::ostream& operator <<(std::ostream& out, Matrix m)
{
	out << m.M11 << ' ' << m.M12 << ' ' << m.M13 << ' ' << m.M14 << "\r\n"
		<< m.M21 << ' ' << m.M22 << ' ' << m.M23 << ' ' << m.M24 << "\r\n"
		<< m.M31 << ' ' << m.M32 << ' ' << m.M33 << ' ' << m.M34 << "\r\n"
		<< m.M41 << ' ' << m.M42 << ' ' << m.M43 << ' ' << m.M44;
	return out;
}

int main()
{
	float a;
	std::cin >> a;
	std::cout << _3DRadSpaceDll::Math::ToRadians(a);
}