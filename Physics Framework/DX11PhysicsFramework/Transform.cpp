#include "Transform.h"
Transform::Transform()
{
	_position = Vector(0, 0, 0);
	_scale= Vector(1.0f, 1.0f, 1.0f);
	_rotation = Vector(0, 0, 0);
}
void Transform::Move(Vector direction)
{
	Vector Position;
	Position = GetPosition();
	Position.x += direction.x;
	Position.y += direction.y;
	Position.z += direction.z;
	SetPosition(Position);
}