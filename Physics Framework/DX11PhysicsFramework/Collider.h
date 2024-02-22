#include "Transform.h"


#pragma once
class SphereCollider;
class PlaneCollider;
class AABB;
class Collider abstract
{
protected:
	Transform* _tf;
	
public:
	Collider(Transform* tf) { _tf = tf; }

	virtual bool CollidesWith(Collider& other) = 0;
	virtual bool CollidesWith(SphereCollider& other) = 0;
	virtual bool CollidesWith(PlaneCollider& other) = 0;
	virtual bool CollidesWith(AABB& other) = 0;

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
	virtual bool CollidesWith(AABB& other) override;
	float CheckRadius() const { return _rad; }
	
};

class PlaneCollider : public Collider
{
public:
	PlaneCollider(Transform* tf) : Collider(tf) { ; }

	virtual bool CollidesWith(Collider& other) override { return other.CollidesWith(*this); }
	virtual bool CollidesWith(SphereCollider& other) override
	{
		float Pos = other.GetPosition().y - GetPosition().y;
		return(Pos <= other.CheckRadius());
	}
	virtual bool CollidesWith(PlaneCollider& other) override { return false; }
	virtual bool CollidesWith(AABB& other) override; 
};

class AABB : public Collider
{
protected:
	Vector halfExtenets;
	Vector Extents = halfExtenets*2;
	Vector minCorner = (GetPosition() - halfExtenets);
	Vector maxCorner = (GetPosition()+halfExtenets);
public:
	AABB(Transform* tf, float halfx,float halfy, float halfz) : Collider(tf) { halfExtenets = Vector(halfx,halfy,halfz); }

	virtual bool CollidesWith(Collider& other) override { return other.CollidesWith(*this); }
	virtual bool CollidesWith(SphereCollider& other) override
	{	
		float x = max(GetPosition().x - halfExtenets.x, min(other.GetPosition().x, GetPosition().x + halfExtenets.x));
		float y = max(GetPosition().y - halfExtenets.y, min(other.GetPosition().y, GetPosition().y + halfExtenets.y));
		float z = max(GetPosition().z - halfExtenets.z, min(other.GetPosition().z, GetPosition().z + halfExtenets.z));

		float distance = sqrtf((x - other.GetPosition().x) * (x - other.GetPosition().x) + (y - other.GetPosition().y) * (y - other.GetPosition().y) + (z - other.GetPosition().z) * (z - other.GetPosition().z));
		return(distance < other.CheckRadius());
	}
	virtual bool CollidesWith(PlaneCollider& other) override { return false; }
	virtual bool CollidesWith(AABB& other) override
	{
		float combinedx = other.GetHalfExtenets().x + halfExtenets.x;
		float combinedy = other.GetHalfExtenets().y + halfExtenets.y;
		float combinedz = other.GetHalfExtenets().z + halfExtenets.z;
		Vector Pos = other.GetPosition() - GetPosition();
		float distance = Pos.Mag(Pos);
		if(distance > combinedx)
		{
			return(false);
		}
		if(distance > combinedy)
		{
			return(false);
		}
		if (distance > combinedz)
		{
			return(false);
		}
		return true;
	}
	Vector GetHalfExtenets() { return halfExtenets; }
};
