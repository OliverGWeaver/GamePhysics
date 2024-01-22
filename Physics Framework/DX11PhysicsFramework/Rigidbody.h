#include "PhysicsModel.h"

#pragma once

class Rigidbody : public PhysicsModel
{
public:
		Rigidbody(Transform* transform);
		Rigidbody(Transform* transform, float mass);
};

