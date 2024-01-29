#include "Collider.h"

bool SphereCollider::CollidesWith(PlaneCollider& other)
{
	return other.CollidesWith(*this);
}
