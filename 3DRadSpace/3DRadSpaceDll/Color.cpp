#include "pch.h"
#include "Color.h"

_3DRadSpaceDll::Color _3DRadSpaceDll::Color::FromRGB(const uint8_t& r, const uint8_t& g, const uint8_t& b)
{
    return Color(1.0f / r,1.0f / g, 1.0f / b);
}
