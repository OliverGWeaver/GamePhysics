#include <windows.h>
#include <d3d11_1.h>
#include <d3dcompiler.h>
#include <directxmath.h>
#include "Vector.h"
#pragma once
class Transform
{
public:
	Transform();
	void SetPosition(Vector position) { _position = position; }
	void SetPosition(float x, float y, float z) { _position.x = x; _position.y = y; _position.z = z; }

	Vector GetPosition() const { return _position; }

	void SetScale(Vector scale) { _scale = scale; }
	void SetScale(float x, float y, float z) { _scale.x = x; _scale.y = y; _scale.z = z; }

	Vector GetScale() const { return _scale; }

	void SetRotation(Vector rotation) { _rotation = rotation; }
	void SetRotation(float x, float y, float z) { _rotation.x = x; _rotation.y = y; _rotation.z = z; }

	Vector GetRotation() const { return _rotation; }

	void Move(Vector direction);
protected:
	Vector _position;
	Vector _rotation;
	Vector _scale;
};

