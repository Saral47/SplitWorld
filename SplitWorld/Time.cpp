#include "Time.h"
#include <iostream>
using namespace std;
Time* Time::instance = nullptr;

void Time::Initialize(int targetFps)
{
	this->targetFPS = 60;
	if (deltaTime > MAX_DELTA_TIME || deltaTime < 0)
		deltaTime = MAX_DELTA_TIME;
}
void Time::Tick()
{
	deltaTime = (SDL_GetTicks() - this->lastRecordedTime) * (this->targetFPS / 1000.0f);

	if (deltaTime > MAX_DELTA_TIME)
		deltaTime = MAX_DELTA_TIME;

	lastRecordedTime = SDL_GetTicks();
}