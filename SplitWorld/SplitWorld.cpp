#include<iostream>
#include "GameEngine.h"
#include "Melethril.h"
#include "TextureManager.h"
#include "Background.h"
#include "Time.h"
#include "ParticleEmitter.h"
#include <string>
#undef main
using namespace std;

//Game Settings
int targetFPS = 60;

//Global GameObjects
//Player Characters
Melethril* t = nullptr;
Melethril* mol = nullptr;

ParticleEmitter* particleEmitter = new ParticleEmitter();

vector<Background*> morningBackground;
vector<Background*> eveningBackground;


//GameEngine* GameEngine::instance = nullptr;
// Game Specific Initialization, this function is used to loaded in the scene and gameObjects
void GameEngine::GameInitialize()
{
	TextureManager::GetInstance()->LoadTexture("melethril_idle", "Art/Melethril/idle.png");
	TextureManager::GetInstance()->LoadTexture("melethril_jump", "Art/Melethril/jump.png");
	t = new Melethril(new GameObjectData("melethril_idle", 136, 195, 200, 300, 1, 1, SDL_FLIP_NONE), "t", 1, 1);
	mol = new Melethril(new GameObjectData("melethril_idle", 136, 195, 200, 900, 1, 1, SDL_FLIP_VERTICAL), "mol", 1, -1);
	GameEngine::GetInstance()->t = t;
	GameEngine::GetInstance()->mol = mol;

	TextureManager::GetInstance()->LoadTexture("morningBackground0", "Art/Background_Morning/0.png");
	TextureManager::GetInstance()->LoadTexture("morningBackground1", "Art/Background_Morning/1.png");
	TextureManager::GetInstance()->LoadTexture("morningBackground2", "Art/Background_Morning/2.png");
	TextureManager::GetInstance()->LoadTexture("morningBackground3", "Art/Background_Morning/3.png");
	TextureManager::GetInstance()->LoadTexture("morningBackground4", "Art/Background_Morning/4.png");
	TextureManager::GetInstance()->LoadTexture("morningBackground5", "Art/Background_Morning/5.png");

	morningBackground.push_back(new Background(new GameObjectData("morningBackground0", 1915, 319, 0, 221, 1, 1, SDL_FLIP_NONE), -1915, 0, 5));
	morningBackground.push_back(new Background(new GameObjectData("morningBackground1", 1915, 319, 0, 221, 1, 1, SDL_FLIP_NONE), -1915, 0, 4));
	morningBackground.push_back(new Background(new GameObjectData("morningBackground2", 1872, 130, 0, 100, 1, 1, SDL_FLIP_NONE), -1915, 0, 3));
	morningBackground.push_back(new Background(new GameObjectData("morningBackground3", 1915, 518, 0, 22, 1, 1, SDL_FLIP_NONE), -1915, 0, 2));
	morningBackground.push_back(new Background(new GameObjectData("morningBackground4", 552, 540, 1000, -50, 1, 1, SDL_FLIP_NONE), -1915, 0, 1));
	morningBackground.push_back(new Background(new GameObjectData("morningBackground5", 1915, 540, 0, 0, 1, 1, SDL_FLIP_NONE), -1915, 0, 0));

	TextureManager::GetInstance()->LoadTexture("eveningBackground0", "Art/Background_Evening/0.png");
	TextureManager::GetInstance()->LoadTexture("eveningBackground1", "Art/Background_Evening/1.png");
	TextureManager::GetInstance()->LoadTexture("eveningBackground2", "Art/Background_Evening/2.png");
	TextureManager::GetInstance()->LoadTexture("eveningBackground3", "Art/Background_Evening/3.png");
	TextureManager::GetInstance()->LoadTexture("eveningBackground4", "Art/Background_Evening/4.png");

	eveningBackground.push_back(new Background(new GameObjectData("eveningBackground0", 1915, 318, 0, 540, 1, 1, SDL_FLIP_VERTICAL), -1915, 0, 5));
	eveningBackground.push_back(new Background(new GameObjectData("eveningBackground1", 1915, 299, 0, 540, 1, 1, SDL_FLIP_VERTICAL), -1915, 0, 4));
	eveningBackground.push_back(new Background(new GameObjectData("eveningBackground2", 1915, 508, 0, 540, 1, 1, SDL_FLIP_VERTICAL), -1915, 0, 3));
	eveningBackground.push_back(new Background(new GameObjectData("eveningBackground3", 1915, 529, 0, 540, 1, 1, SDL_FLIP_VERTICAL), -1915, 0, 2));
	eveningBackground.push_back(new Background(new GameObjectData("eveningBackground4", 1915, 540, 0, 540, 1, 1, SDL_FLIP_VERTICAL), -1915, 0, 0));

	TextureManager::GetInstance()->LoadTexture("raindrop", "Art/Rain/rain.png");
	TextureManager::GetInstance()->LoadTexture("blooddrop", "Art/Rain/blood.png");


	particleEmitter->Initialize("raindrop", 0, 1200);
	particleEmitter->Initialize("blooddrop", 1, 1200);

}



// Handles Events is implemented here for personal convenience





// Function that implements parallax
void MoveBackGround(float deltaTime)
{


	for (int i = 0; i < (int)morningBackground.size() - 1; i++)
		morningBackground[i]->Update(deltaTime);

	for (int i = 0; i < (int)eveningBackground.size() - 1; i++)
		eveningBackground[i]->Update(deltaTime);
}


void RenderBackground()
{
	for (int i = (int)morningBackground.size() - 1; i >= 0; i--)
		morningBackground[i]->Draw();

	for (int i = (int)eveningBackground.size() - 1; i >= 0; i--)
		eveningBackground[i]->Draw();
}

//GameUpdate is called last in the Update Order
void GameEngine::GameUpdate(float deltaTime)
{

	//Displaying FPS

	//cout << deltaTime << endl;
	cout << GameEngine::GetInstance()->GetCurrentFPS() << endl;
	t->Update(deltaTime);
	mol->Update(deltaTime);
	MoveBackGround(deltaTime);
	particleEmitter->Update(deltaTime);
}


void GameEngine::Render()
{
	SDL_RenderClear(renderer);
	RenderBackground();
	t->Draw();
	mol->Draw();
	particleEmitter->Render();
	SDL_RenderPresent(renderer);
}

int main(int argc, const char* argv[])
{
	Time::GetInstance()->Initialize(60);
	GameEngine::GetInstance()->Initialize("MYGAME", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1915, 1080, false, targetFPS);
	GameEngine::GetInstance()->GameInitialize();

	while (GameEngine::GetInstance()->IsRunning())
	{
		GameEngine::GetInstance()->HandleEvents();
		GameEngine::GetInstance()->Update();
		GameEngine::GetInstance()->Render();
		Time::GetInstance()->Tick();
	}
	GameEngine::GetInstance()->CleanExit();

	return 0;
}
