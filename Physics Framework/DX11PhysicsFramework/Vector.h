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

	float x;
	float y;
	float z;
	
};

