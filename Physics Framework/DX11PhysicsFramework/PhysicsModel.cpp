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
	_netforce.x += DragForce(_velocity.x);
	_netforce.y += DragForce(_velocity.y);
	_netforce.z += DragForce(_velocity.z);
	_netforce.x += FrictionForce(_netforce.x);
	_netforce.y += FrictionForce(_netforce.y);
	_netforce.z += FrictionForce(_netforce.z);
	acceleration.x += _netforce.x / _mass;
	acceleration.y += _netforce.y / _mass;
	acceleration.z += _netforce.z / _mass;
	
	_velocity.x += acceleration.x * deltaTime;
	_velocity.y += acceleration.y * deltaTime;
	_velocity.z += acceleration.z * deltaTime;

	position.x += _velocity.x * deltaTime;
	position.y += _velocity.y * deltaTime;
	position.z += _velocity.z * deltaTime;
	_transform->SetPosition(position);
	_netforce = Vector(0, 0, 0);
	acceleration = Vector(0, 0, 0);
}
