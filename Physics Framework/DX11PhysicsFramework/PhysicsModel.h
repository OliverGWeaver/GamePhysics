#include "Transform.h"

#pragma once

class PhysicsModel
{
protected:
	Transform* _transform;
	Vector _velocity;
public:
	PhysicsModel(Transform* transform);
	void Update(float deltaTime);
	
	Vector getVelocity() { return _velocity; }
	void SetPosition(Vector position) { _velocity = position; }
	void SetPosition(float x, float y, float z) { _velocity.x = x; _velocity.y = y; _velocity.z = z; }
	Vector Multiply(Vector a, float b) { a.x *= b; a.y *= b; a.z *= b; return a; }
};

