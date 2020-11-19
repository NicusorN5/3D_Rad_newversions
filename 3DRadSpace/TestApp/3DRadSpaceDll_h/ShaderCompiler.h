#pragma once
#include <d3d11.h>
#include <d3d11shader.h>

namespace _3DRadSpaceDll
{
	class __declspec(dllexport) ShaderCompiler
	{
			static void LoadShader(wchar_t* shader_file,ID3D11VertexShader **vs,ID3D11PixelShader **ps);
	};
}

