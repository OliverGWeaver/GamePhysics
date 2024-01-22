#pragma once
#include<string>
#include<Windows.h>
#include <d3d11_1.h>
#include <d3dcompiler.h>
#include <directxmath.h>
class Debug
{
public:
	Debug();
	~Debug();
	static int VDebugPrintF(const char* format, va_list args);
	static int DebugPrintF(const char* format, ...);

};


