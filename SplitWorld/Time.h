#pragma once
#ifndef Time_hpp
#define Time_hpp
#include<SDL.h>
#define MAX_DELTA_TIME 1.5
class Time
{
private:
	static Time* instance;
	Time() {};

public:
	inline static Time* GetInstance() { if (!instance)instance = new Time; return instance; };
	void Initialize(int fps);
	void Tick();
	inline float DeltaTime() { return deltaTime; }
private:
	int targetFPS;
	int currentFPS;
	int frameCounter;
	float deltaTime;
	float currentRecordedTime;
	float lastRecordedTime;

};
#endif
