#include "Transform.h"
#include "Debug.h"

#pragma once

class PhysicsModel
{
protected:
	Transform* _transform;
	Vector _velocity;
	Vector _accelatration;
	Debug _debug;
public:
	PhysicsModel(Transform* transform);
	void Update(float deltaTime);
	
	Vector getVelocity() { return _velocity; }
	void SetVelocity(Vector position) { _velocity = position; }
	void SetVelocity(float x, float y, float z) { _velocity.x = x; _velocity.y = y; _velocity.z = z; }
	Vector getAcceleration() { return _accelatration; }
	void SetAcceleration(Vector position) { _accelatration = position; }
	void SetAcceleration(float x, float y, float z) { _accelatration.x = x; _accelatration.y = y; _accelatration.z = z; }
	Vector Multiply(Vector a, float b) { a.x *= b; a.y *= b; a.z *= b; return a; }
};

