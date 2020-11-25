#include "pch.h"
#include "MeshPart.h"

void _3DRadSpaceDll::MeshPart::CreateBuffers(ID3D11Device* gd)
{
	D3D11_BUFFER_DESC bufferDesc;
	bufferDesc.Usage = D3D11_USAGE_DEFAULT;
	bufferDesc.ByteWidth = sizeof(unsigned int) * 3;
	bufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
	bufferDesc.CPUAccessFlags = 0;
	bufferDesc.MiscFlags = 0;

	D3D11_SUBRESOURCE_DATA InitData;
	InitData.pSysMem = this->Indicies;
	InitData.SysMemPitch = 0;
	InitData.SysMemSlicePitch = 0;

	gd->CreateBuffer(&bufferDesc,&InitData,&_buffer);

	D3D11_BUFFER_DESC bufferDesc2;
	bufferDesc2.Usage = D3D11_USAGE_DEFAULT;
	bufferDesc2.ByteWidth = sizeof(VertexPositionDecl) * this->BuffSize;
	bufferDesc2.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	bufferDesc2.CPUAccessFlags = 0;
	bufferDesc2.MiscFlags = 0;

	D3D11_SUBRESOURCE_DATA InitData2;
	InitData2.pSysMem = this->Buffer;
	InitData2.SysMemPitch = 0;
	InitData2.SysMemSlicePitch = 0;

	gd->CreateBuffer(&bufferDesc2, &InitData2, &this->_vertexbuffer);

	this->_stride = new size_t[this->BuffSize];
	memset(_stride, sizeof(VertexPositionDecl), this->BuffSize);

	this->_offset = new size_t[this->BuffSize];
	memset(_offset, 0, this->BuffSize);
}

void _3DRadSpaceDll::MeshPart::Draw(Matrix world, Matrix view, Matrix projection, ID3D11DeviceContext *context)
{
	context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY::D3D10_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	context->IASetIndexBuffer(_buffer, DXGI_FORMAT::DXGI_FORMAT_D32_FLOAT, 0);
	context->IASetVertexBuffers(0, 1, &_vertexbuffer, _stride, _offset);
	context->DrawIndexed(1, 0, 0);
}

_3DRadSpaceDll::MeshPart::~MeshPart()
{
	if(Buffer != nullptr) delete[] Buffer;
}
