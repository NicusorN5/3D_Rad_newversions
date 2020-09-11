// TestApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "3DRadSpaceDll_h/Vector3.h"

using namespace _3DRadSpaceDll;

int main()
{
    float x, y, z;
    std::cin >> x >> y >> z;
    Vector3 v(x, y, z);
    std::cout << "Length "<< v.Length()<< "\r\n";
    v.Normalize();
    std::cout << " Vn = "<< v.X << ' ' << v.Y << ' ' << v.Z;
}