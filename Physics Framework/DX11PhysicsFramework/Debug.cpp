#include "Debug.h"
Debug::Debug()
{}
Debug::~Debug()
{}

int Debug::VDebugPrintF(const char* format, va_list args)
{
	const UINT32 Maxchars = 1024;
	static char s_buffer[Maxchars];

	int Charswritten = vsnprintf(s_buffer, Maxchars, format, args);
	OutputDebugStringA(s_buffer);

	return Charswritten;
}
int Debug::DebugPrintF(const char* format, ...)
{
	va_list argList;
	va_start(argList, format);

	int charsWritten = VDebugPrintF(format, argList);
	va_end(argList);

	return charsWritten;
}