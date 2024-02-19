#include "Transform.h"

#pragma once
class SphereCollider;
class PlaneCollider;
class Collider abstract
{
protected:
	Transform* _tf;
	
public:
	Collider(Transform* tf) { _tf = tf; }

	virtual bool CollidesWith(Collider& other) = 0;
	virtual bool CollidesWith(SphereCollider& other) = 0;
	virtual bool CollidesWith(PlaneCollider& other) = 0;

	Vector GetPosition() const { return _tf->GetPosition(); }
};


class SphereCollider : public Collider
{
	float _rad = 1.0f;

public:
	SphereCollider(Transform* tf, float rad) : Collider(tf) { _rad = rad; }
	virtual bool CollidesWith(Collider& other) override { return other.CollidesWith(*this); }
	virtual bool CollidesWith(SphereCollider& other) override 
	{float combinedRad = other.CheckRadius() + _rad;
		Vector Pos = other.GetPosition() - GetPosition();
		float distance = Pos.Mag(Pos);
		return(distance < combinedRad );
	}
	virtual bool CollidesWith(PlaneCollider& other) override
	{
		return true;
	}
	float CheckRadius() const { return _rad; }
	
};

class PlaneCollider : public Collider
{
public:
	PlaneCollider(Transform* tf) : Collider(tf) { ; }

	virtual bool CollidesWith(Collider& other) override { return other.CollidesWith(*this); }
	virtual bool CollidesWith(SphereCollider& other) override
	{
		Vector Pos = other.GetPosition().y - GetPosition().y;
		return(distance < other.CheckRadius());
	}
	virtual bool CollidesWith(PlaneCollider& other) override { return false; }
};
