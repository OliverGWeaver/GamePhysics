#include "PhysicsModel.h"

PhysicsModel::PhysicsModel(Transform* transform)
{
	_transform = transform;
	SetVelocity(0, 0, 0);
	SetAcceleration(0, 0, 0);
	_netforce = Vector(0, 0, 0);
}

PhysicsModel::PhysicsModel(Transform* transform, float mass)
{
	_transform = transform;
	SetVelocity(0, 0, 0);
	SetAcceleration(0, 0, 0);
	_mass = mass;
	_netforce = Vector(0, 0, 0);
}

void PhysicsModel::Update(float deltaTime)
{
	Vector position = _transform->GetPosition();
	if (_simulateGravity) 
	{
		_netforce.y += GravityForce();
	}
	_netforce.x -= DragForce(_velocity.x);
	_netforce.y -= DragForce(_velocity.y);
	_netforce.z -= DragForce(_velocity.z);
	if (!_simulateGravity)
	{
		_netforce.x -= FrictionForce(_netforce.x);
		_netforce.z -= FrictionForce(_netforce.z);
	}
	_acceleration.x += _netforce.x / _mass;
	_acceleration.y += _netforce.y / _mass;
	_acceleration.z += _netforce.z / _mass;
	
	_velocity.x += _acceleration.x * deltaTime;
	_velocity.y += _acceleration.y * deltaTime;
	_velocity.z += _acceleration.z * deltaTime;

	position.x += _velocity.x * deltaTime;
	position.y += _velocity.y * deltaTime;
	position.z += _velocity.z * deltaTime;
	_transform->SetPosition(position);
	_netforce = Vector(0, 0, 0);
	_acceleration = Vector(0, 0, 0);

}

XMFLOAT3X3 PhysicsModel::MakeInertiaTensor(SphereCollider a)
{
	_intertiaTensor._11 = 2.0f / 5.0f * _mass * a.CheckRadius() * a.CheckRadius();
	_intertiaTensor._12 = 0;
	_intertiaTensor._13 = 0;

	_intertiaTensor._21 = 0;
	_intertiaTensor._22 = 2.0f / 5.0f * _mass * a.CheckRadius() * a.CheckRadius();
	_intertiaTensor._23 = 0;

	_intertiaTensor._31 = 0;
	_intertiaTensor._32 = 0;
	_intertiaTensor._33 = 2.0f / 5.0f * _mass * a.CheckRadius() * a.CheckRadius();

	return _intertiaTensor;
}