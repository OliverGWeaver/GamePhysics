#include "appearance.h"

appearance::appearance(Geometry geometry, Material material)
{
	_geometry = geometry;
	_material = material;

	_textureRV = nullptr;
}

appearance::~appearance()
{
	_textureRV = nullptr;
	_geometry.vertexBuffer = nullptr;
	_geometry.indexBuffer = nullptr;
}

void appearance::Draw(ID3D11DeviceContext* pImmediateContext)
{

		// We are assuming that the constant buffers and all other draw setup has already taken place

		// Set vertex and index buffers
		pImmediateContext->IASetVertexBuffers(0, 1, &_geometry.vertexBuffer, &_geometry.vertexBufferStride, &_geometry.vertexBufferOffset);
		pImmediateContext->IASetIndexBuffer(_geometry.indexBuffer, DXGI_FORMAT_R16_UINT, 0);

		pImmediateContext->DrawIndexed(_geometry.numberOfIndices, 0, 0);
}
