#include "SphereCollider.h"

SphereCollider::~SphereCollider()
{
}

bool SphereCollider::CollidesWith(SphereCollider& other)
{
	float combinedRad = other.CheckRadius() + _rad;
	Vector Pos;
	Pos = other.GetPosition() + GetPosition();
	float distance = Pos.Mag(Pos);
	return(combinedRad < distance);
}
