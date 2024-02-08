#include "Vector.h"
Vector::Vector(float r, float g, float b)
{
	x = r;
	y = g;
	z = b;
}

float Vector::Mag(Vector a)
{
	return(sqrt((a.x * a.x) + (a.y * a.y) + (a.z * a.z)));
}
float Vector::Dot(Vector a, Vector b)
{

	float dot = ((a.x * b.x) + (a.y * b.y) + (a.z + b.z));

	return dot;
}
Vector Vector::Cross(Vector a, Vector b)
{
	Vector cross;
	cross.x = (a.y * b.z - a.z * b.y);
	cross.y = (a.x * b.z - a.z * b.x);
	cross.z = (a.x * b.y - a.y * b.x);
	return cross;
}
Vector Vector::Normal(Vector a)
{
	float mag = a.Mag(a);
	if (mag == 0)
		return Vector(0, 0, 0);
	Vector norm;
	norm.x = a.x / mag;
	norm.y = a.y / mag;
	norm.z = a.z / mag;
	return norm;
}