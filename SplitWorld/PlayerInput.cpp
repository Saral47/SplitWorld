#include "PlayerInput.h"
#include "GameEngine.h"

PlayerInput* PlayerInput::instance = nullptr;

PlayerInput::PlayerInput()
{
	keyStates = SDL_GetKeyboardState(nullptr);
}
void PlayerInput::GetInput()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			GameEngine::GetInstance()->CleanExit();
			break;
		case SDL_KEYDOWN:
			this->KeyDown();
			break;
		case SDL_KEYUP:
			this->KeyUp();
			break;
		default:
			break;
		}
	}
}
bool PlayerInput::GetKey(SDL_Scancode key)
{
	if (keyStates[key] == 1)
		return true;
	else
		return false;
}
void PlayerInput::KeyDown()
{
	keyStates = SDL_GetKeyboardState(nullptr);
}
void PlayerInput::KeyUp()
{
	keyStates = SDL_GetKeyboardState(nullptr);
}
