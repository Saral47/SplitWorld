#ifndef GameEngine_hpp
#define GameEngine_hpp

#define SDL_MAIN_HANDLED
#include <SDL.h> 
#include <SDL_image.h> 
#include <SDL_timer.h>
#include <vector> 
#include "GameObject.h"
#include "Melethril.h"
using namespace std;




class GameEngine
{

	///////////// GameEngine is a singleton/////////
public:
	inline static GameEngine* GetInstance() { if (instance == nullptr)instance = new GameEngine; return instance; };

private:
	GameEngine();
	static GameEngine* instance;
	////////////////////////////////


public:
	void Initialize(const char* title, int xpos, int ypos, int width, int height, bool fullscreen, int targetFPS);
	void GameInitialize();


	// Main GameEngine Loop
	void HandleEvents();
	void Update();
	void Render();
	void CleanExit();

	// Game specific update, this is implemented in SplitWorld.cpp
	void GameUpdate(float duration);


	inline bool IsRunning() { return isRunning; }
	inline  SDL_Renderer* GetRenderer() { return renderer; }
	inline int GetCurrentFPS() { return currentFPS; }


	static vector<GameObject> gameObjects;

public:
	int targetFPS;
	int currentFPS;
	float frameDuration;

	bool isRunning = false;


	int currentRecordedTime;
	int fpsCounter = 0;
	int lastRecordedTime = 0;
	float duration;

	Melethril* t;
	Melethril* mol;
private:
	SDL_Window* window;
	SDL_Renderer* renderer;

};




#endif // !Game_hpp#pragma once
