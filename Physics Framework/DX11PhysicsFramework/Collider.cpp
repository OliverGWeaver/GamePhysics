#include "Collider.h"

//bool SphereCollider::CollidesWith(PlaneCollider& other)
//{
//	return other.CollidesWith(*this);
//}

bool SphereCollider::CollidesWith(AABB& other)
{

	float x = max(other.GetPosition().x - other.GetHalfExtenets().x, min(GetPosition().x, other.GetPosition().x + other.GetHalfExtenets().x));
	float y = max(other.GetPosition().y - other.GetHalfExtenets().y, min(GetPosition().y, other.GetPosition().y + other.GetHalfExtenets().y));
	float z = max(other.GetPosition().z - other.GetHalfExtenets().z, min(GetPosition().z, other.GetPosition().z + other.GetHalfExtenets().z));

	float distance = sqrtf((x - GetPosition().x) * (x - GetPosition().x) + (y - GetPosition().y) * (y - GetPosition().y) + (z - GetPosition().z) * (z - GetPosition().z));
	return(distance < CheckRadius());
}

bool PlaneCollider::CollidesWith(AABB& other)
{
	
	float pos = other.GetPosition().y - other.GetHalfExtenets().y;
		return(GetPosition().y >= pos);
}
