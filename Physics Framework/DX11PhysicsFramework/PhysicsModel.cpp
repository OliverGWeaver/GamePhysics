#include "PhysicsModel.h"

PhysicsModel::PhysicsModel(Transform* transform)
{
	_transform = transform;
	SetVelocity(0, 0, 0);
	SetAcceleration(0, 0, 0);
}

void PhysicsModel::Update(float deltaTime)
{
	Vector position = _transform->GetPosition();

	_velocity.x += _accelatration.x * deltaTime;
	_velocity.y += _accelatration.y * deltaTime;
	_velocity.z += _accelatration.z * deltaTime;

	position.x += _velocity.x * deltaTime;
	position.y += _velocity.y * deltaTime;
	position.z += _velocity.z * deltaTime;
	_transform->SetPosition(position);
}
