#pragma once
#include <windows.h>
#include <d3d11_1.h>
#include <d3dcompiler.h>
#include <directxmath.h>

float const tol = 0.0001f;

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
	Vector operator*(const Vector& b)
	{
		Vector total;
		total.x = this->x * b.x;
		total.y = this->y * b.y;
		total.z = this->z * b.z;
		return total;
	}
	Vector operator*(const float b)
	{
		Vector total;
		total.x = this->x * b;
		total.y = this->y * b;
		total.z = this->z * b;
		return total;
	}
	Vector operator/(const float b)
	{
		this->x /= b;
		this->y /= b;
		this->z /= b;
		return *this;
	}

	float x;
	float y;
	float z;
	
};

