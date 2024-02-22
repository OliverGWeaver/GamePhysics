#include "Transform.h"
Transform::Transform()
{
	_parent = nullptr;
	_position = Vector(0, 0, 0);
	_qRotation = Quaternion();
	_scale= Vector(1.0f, 1.0f, 1.0f);
}
void Transform::Move(Vector direction)
{
	Vector Position;
	Position = GetPosition();
	Position.x += direction.x;
	Position.y += direction.y;
	Position.z += direction.z;
	SetPosition(Position);
}
void Transform::Update(float dt)
{
	// Calculate world matrix

	XMMATRIX scale = XMMatrixScaling(_scale.x, _scale.y, _scale.z);
	XMMATRIX rotation = XMMatrixRotationQuaternion(XMVectorSet(_qRotation.v.x, _qRotation.v.y, _qRotation.v.z, _qRotation.n ));
	XMMATRIX translation = XMMatrixTranslation(_position.x, _position.y, _position.z);

	XMStoreFloat4x4(&_world, scale * rotation * translation);
	if (_parent != nullptr)
	{
		XMStoreFloat4x4(&_world, this->GetWorldMatrix() * _parent->GetWorldMatrix());
	}
}