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
	Vector LHS=a.Normal(a);
	Vector RHS=b.Normal(b);
	float dot = ((LHS.x * RHS.x) + (LHS.y * RHS.y) + (LHS.z + RHS.z));
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
	Vector norm;
	norm.x = a.x / mag;
	norm.y = a.y / mag;
	norm.z = a.z / mag;
	return norm;
}