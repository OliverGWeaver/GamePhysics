#include "Vector.h"
#include "Structures.h"

#pragma once
class appearance
{
private:
	Geometry _geometry;
	Material _material;
	ID3D11ShaderResourceView* _textureRV = nullptr;
public:
	appearance(Geometry geometry, Material material);
	~appearance();

	Geometry GetGeometryData() const { return _geometry; }
	Material GetMaterial() const { return _material; }

	void SetGeometryData(Geometry Geometry) { _geometry = Geometry; }
	void SetMaterial(Material Material) { _material = Material; }

	void SetTextureRV(ID3D11ShaderResourceView* textureRV) { _textureRV = textureRV; }
	ID3D11ShaderResourceView* const* GetTextureRV() { return &_textureRV; }
	bool HasTexture() const { return _textureRV ? true : false; }

	void Draw(ID3D11DeviceContext* pImmediateContext);
};

