#include "Collider.h"

#pragma once
class SphereCollider : public Collider
{
	float _rad = 1.0f;

public:
	SphereCollider(Transform* tf, float rad) : Collider(tf) { _rad = rad; }
	virtual bool CollidesWith(Collider& other) override { return other.CollidesWith(*this); }
	virtual bool CollidesWith(SphereCollider& other) override;

	float CheckRadius() const { return _rad; }
};

