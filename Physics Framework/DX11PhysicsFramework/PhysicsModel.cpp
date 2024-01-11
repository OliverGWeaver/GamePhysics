#include "PhysicsModel.h"

PhysicsModel::PhysicsModel(Transform* transform)
{

}

void PhysicsModel::Update(float deltaTime)
{
	Vector position = _transform->GetPosition();

	position.x += _velocity.x * deltaTime;
	position.y += _velocity.y * deltaTime;
	position.z += _velocity.z * deltaTime;

	_transform->SetPosition(position);
}
