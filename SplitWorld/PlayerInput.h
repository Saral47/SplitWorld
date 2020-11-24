#pragma once
#ifndef PlayerInput_hpp
#define PlayerInput_hpp
#include<SDL.h>
class PlayerInput
{
private:
	static PlayerInput* instance;
	PlayerInput();

public:
	inline static PlayerInput* GetInstance() { if (!instance)instance = new PlayerInput; return instance; };

	void GetInput();
	bool GetKey(SDL_Scancode key);

private:
	void KeyUp();
	void KeyDown();
	const Uint8* keyStates;

};
#endif
