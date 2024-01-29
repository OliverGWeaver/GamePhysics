#pragma once
#include <windows.h>
#include <d3d11_1.h>
#include <d3dcompiler.h>
#include <directxmath.h>
class Vector
{
public:	
	Vector()= default;
	Vector(float r, float g, float b);
	float Dot(Vector a, Vector b);
	Vector Cross(Vector a,Vector b);
	Vector Normal(Vector a);
	float Mag(Vector a);
	Vector operator+(const Vector& b)
	{
		Vector total;
		total.x = this->x + b.x;
		total.y = this->y + b.y;
		total.z = this->z + b.z;
		return total;
	}	
	Vector operator-(const Vector& b)
	{
		Vector total;
		total.x = this->x - b.x;
		total.y = this->y - b.y;
		total.z = this->z - b.z;
		return total;
	}
	Vector operator+=(const Vector& b)
	{
		Vector total;
		total.x = this->x + b.x;
		total.y = this->y + b.y;
		total.z = this->z + b.z;
		return total;
	}

	float x;
	float y;
	float z;
	
};

