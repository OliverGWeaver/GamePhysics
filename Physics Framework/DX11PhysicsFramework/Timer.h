#include <chrono>
#pragma once
using namespace std::chrono;

class Timer
{
public:
	Timer();

	float GetDeltaTime();
	void Tick();
private:
	steady_clock::time_point lastFrame;

};

