#pragma once
#include "Vector3.h"
#include "Vector2.h"
#include "Color.h"
#include <d3d11.h>
namespace _3DRadSpaceDll
{
	struct VertexPositionDecl
	{
		Vector3 Pos;
	};
	struct VertexPositionColorDecl
	{
		Vector3 Pos;
		Color Color;
	};
	struct VertexPositionTextureDecl
	{
		Vector3 Pos;
		Vector2 UV;
	};
	struct VertexPositionNormalTextureDecl
	{
		Vector3 Pos;
		Vector3 Normal;
		Vector2 UV;
	};
	class _declspec(dllexport) MeshPart
	{
		ID3D11Buffer *_buffer;
		ID3D11Buffer* _vertexbuffer;
		public:
			void* Buffer;
			int* Indicies;
			size_t Size;
			/*Creates a MeshPart containing a vertex buffer.*/
			MeshPart(void* membuffer, int* ind, size_t s) : Buffer(membuffer), Indicies(ind), Size(s), _buffer(nullptr), _vertexbuffer(nullptr) {};
			MeshPart() : Buffer(nullptr), Indicies(nullptr), Size(0), _buffer(nullptr), _vertexbuffer(nullptr) {};
			
			void CreateBuffers(ID3D11Device *gd);

			void Draw(Matrix world,Matrix view,Matrix projection,ID3D11DeviceContext *context);

			~MeshPart();
	};
	
}

