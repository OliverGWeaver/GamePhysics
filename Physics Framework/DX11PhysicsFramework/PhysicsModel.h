#include "Transform.h"
#include "Debug.h"
#include "Collider.h"
#include <cmath>

#pragma once

class PhysicsModel abstract
{
protected:
	Transform* _transform;
	Vector _velocity;
	Vector _acceleration;
	Vector _netforce;
	Collider* _collider = nullptr;
	float _mass = 1.0f;
	Debug _debug;
	bool _simulateGravity = false;
	float _dragCo = 1.05f;
	float _airDensity = 1.204f;
	float _area = 1.0f;
	float _SfrictionCo = 0.65f;
	float _DfrictionCo = 0.40f;
	XMFLOAT3X3 _intertiaTensor;
	bool _Tensor = false;
public:
	PhysicsModel()= default;
	PhysicsModel(Transform* transform);
	PhysicsModel(Transform* transform, float mass);
	virtual void Update(float deltaTime);
	
	virtual Vector GetVelocity() { return _velocity; }
	virtual void SetVelocity(Vector position) { _velocity = position; }
	virtual void SetVelocity(float x, float y, float z) { _velocity.x = x; _velocity.y = y; _velocity.z = z; }
	
	virtual Vector GetAcceleration() { return _acceleration; }
	virtual void SetAcceleration(Vector position) { _acceleration = position; }
	virtual void SetAcceleration(float x, float y, float z) { _acceleration.x = x; _acceleration.y = y; _acceleration.z = z; }
	
	virtual Vector GetForce() { return _netforce; }
	virtual void AddForce(float x, float y, float z) { _netforce.x += x; _netforce.y += y; _netforce.z += z; }
	virtual void AddForce (Vector force) { _netforce.x += force.x; _netforce.y += force.y;_netforce.z += force.z;}
	virtual Vector Multiply(Vector a, float b) { a.x *= b; a.y *= b; a.z *= b; return a; }
	
	virtual void setGrav(bool grav) { _simulateGravity = grav;}
	virtual float GravityForce() { return (- 9.81f * _mass); }
	virtual float DragForce(float Vel) { if (Vel < 0) return (-0.5f * _dragCo * _airDensity * _area * Vel * Vel); if (Vel > 0) return (0.5f * _dragCo * _airDensity * _area * Vel * Vel); }
	virtual float FrictionForce(float force) { if (_velocity.x == 0&& _velocity.z == 0 ) return (_SfrictionCo * force); else return(_DfrictionCo * force); }
	
	virtual bool IsCollideable() const { return _collider != nullptr; }
	virtual Collider* GetCollider() const { return _collider;}
	virtual void  SetCollider(Collider* col) { _collider = col; }
	
	virtual void ApllyImpulse(Vector impulse) { _velocity =_velocity + impulse; }
	virtual float GetMass() { return _mass; }
	virtual void SetMass(float a) { _mass = a; }

	virtual void AddRelativeForce(Vector force, Vector point) = 0;
	XMFLOAT3X3 MakeInertiaTensor(SphereCollider a);
	XMFLOAT3X3 MakeInertiaTensor(AABB a);
};

