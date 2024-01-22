#include "Rigidbody.h"

Rigidbody::Rigidbody(Transform* transform)
{
	_transform = transform;
	SetVelocity(0, 0, 0);
	SetAcceleration(0, 0, 0);
	_netforce = Vector(0, 0, 0);
}

Rigidbody::Rigidbody(Transform* transform, float mass)
{
	_transform = transform;
	SetVelocity(0, 0, 0);
	SetAcceleration(0, 0, 0);
	_mass = mass;
	_netforce = Vector(0, 0, 0);
}