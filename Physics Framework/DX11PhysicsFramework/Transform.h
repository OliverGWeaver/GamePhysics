#include <windows.h>
#include <d3d11_1.h>
#include <d3dcompiler.h>
#include <directxmath.h>
#include "Quaternion.h"
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

	void SetRotation(Vector rotation) { _qRotation = MakeQFromEulerAngles(rotation.x,rotation.y,rotation.z); }
	void SetRotation(float x, float y, float z) { _qRotation = MakeQFromEulerAngles(x,y,z); }
	void SetOrientation(Quaternion rotation) { _qRotation = rotation; }

	Vector GetRotation() const { return MakeEulerAnglesFromQ(_qRotation); }
	Quaternion GetOrientation() const { return _qRotation; }

	void Move(Vector direction);

	void Update(float dt);
	XMMATRIX GetWorldMatrix() const { return XMLoadFloat4x4(&_world); }

protected:
	Vector _position;
	Quaternion _qRotation;
	Vector _scale;

	XMFLOAT4X4 _world;
	Transform* _parent = nullptr;
};

