#include "Transform.h"

#pragma once
class SphereCollider;
class Collider abstract
{
protected:
	Transform* _tf;
	
public:
	Collider(Transform* tf) { _tf = tf; }

	virtual bool CollidesWith(Collider& other) = 0;
	virtual bool CollidesWith(SphereCollider& other) = 0;

	Vector GetPosition() const { return _tf->GetPosition(); }
};

