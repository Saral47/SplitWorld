#include<iostream>
#include<string>
#include "GameEngine.h"
#include "GameObject.h"

#include "TextureManager.h"
#include "PlayerInput.h"
#include "Time.h"
using namespace std;

vector<GameObject> GameEngine::gameObjects;
GameEngine* GameEngine::instance = nullptr;

GameEngine::GameEngine()
{

}
void GameEngine::Initialize(const char* title, int xpos, int ypos, int width, int height, bool fullscreen, int targetFPS)
{
	SDL_SetMainReady();
	int flag = 0;

	if (fullscreen)
		flag = SDL_WINDOW_FULLSCREEN;

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "SDL Initialized " << std::endl;

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flag);

		if (window)
			std::cout << "WINDOW CREATED" << std::endl;

		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

		if (renderer)
		{

			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << " RENDERER CREATED" << std::endl;
		}

		this->targetFPS = targetFPS;
		this->frameDuration = 1000 / this->targetFPS;
		this->isRunning = true;

	}

	else
	{
		this->isRunning = false;
		std::cout << "SDL Failed " << SDL_GetError() << std::endl;
	}

}


void GameEngine::Update()
{
	float deltaTime = Time::GetInstance()->DeltaTime();

	currentRecordedTime = SDL_GetTicks();

	fpsCounter++;
	if (currentRecordedTime >= (lastRecordedTime + 1000))
	{
		lastRecordedTime = currentRecordedTime;
		currentFPS = fpsCounter;
		fpsCounter = 0;
	}

	duration = SDL_GetTicks() - currentRecordedTime;

	if (duration < frameDuration)
	{
		SDL_Delay(frameDuration - duration);
	}


	GameUpdate(deltaTime);
}
void GameEngine::HandleEvents()
{
	PlayerInput::GetInstance()->GetInput();
}

void GameEngine::CleanExit()
{
	TextureManager::GetInstance()->Clear();
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	IMG_Quit();
	SDL_Quit();
	std::cout << " GAME CLOSED" << std::endl;
}


