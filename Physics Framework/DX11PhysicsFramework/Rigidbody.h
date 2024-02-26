#include "PhysicsModel.h"

#pragma once

class Rigidbody : public PhysicsModel
{
public:
	Vector _tourque= Vector(0,0,0);
	float _damper = 0.87f;
	Vector _aVel = Vector(0,0,0);
	Vector _aAcel = Vector(0, 0, 0);
		Rigidbody(Transform* transform);
		Rigidbody(Transform* transform, float mass);
		virtual void AddRelativeForce(Vector force, Vector point) override { AddForce(force); _tourque = point.Cross(point, force); }
		
		Vector CalcAVel(float dt);
		virtual void Update(float deltaTime)override;
};

