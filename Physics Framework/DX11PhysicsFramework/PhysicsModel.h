#include "Transform.h"
#include "Debug.h"

#pragma once

class PhysicsModel
{
protected:
	Transform* _transform;
	Vector _velocity;
	Vector acceleration;
	Vector _netforce;
	float _mass = 1.0f;
	Debug _debug;
	bool _simulateGravity = false;
	float _dragCo = 1.05f;
	float _airDensity = 1.204f;
	float _area = 1.0f;
	float _frictionCo = 0.4f;
public:
	PhysicsModel(Transform* transform);
	PhysicsModel(Transform* transform, float mass);
	virtual void Update(float deltaTime);
	
	virtual Vector GetVelocity() { return _velocity; }
	virtual void SetVelocity(Vector position) { _velocity = position; }
	virtual void SetVelocity(float x, float y, float z) { _velocity.x = x; _velocity.y = y; _velocity.z = z; }
	virtual Vector GetAcceleration() { return acceleration; }
	virtual void SetAcceleration(Vector position) { acceleration = position; }
	virtual void SetAcceleration(float x, float y, float z) { acceleration.x = x; acceleration.y = y; acceleration.z = z; }
	virtual Vector GetForce() { return _netforce; }
	virtual void AddForce(float x, float y, float z) { _netforce.x += x; _netforce.y += y; _netforce.z += z; }
	virtual void AddForce (Vector force) { _netforce.x += force.x; _netforce.y += force.y;_netforce.z += force.z;}
	virtual Vector Multiply(Vector a, float b) { a.x *= b; a.y *= b; a.z *= b; return a; }
	virtual void setGrav() { _simulateGravity = true;}
	virtual float GravityForce() { return (- 9.81 * _mass); }
	virtual float DragForce(float Vel) { return (0.5*_dragCo*_airDensity*_area*Vel*Vel); }
	virtual float FrictionForce(float force) { return (_frictionCo * force); }
};

