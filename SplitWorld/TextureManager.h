#pragma once
#ifndef TextureManager_hpp
#define TextureManager_hpp
#define SDL_MAIN_HANDLED
#include<iostream>
#include<string>
#include<map>
#include "GameEngine.h"


//This class manages all the textures in the game by maintaining a map between textureIDs and SDL_Textures. This class is a singleton, so all gameObjects use this class to render textures.
using namespace std;
class TextureManager
{
private:
	static TextureManager* instance;
	TextureManager();

public:
	inline static TextureManager* GetInstance() { if (!instance)instance = new TextureManager; return instance; };

	SDL_Texture* GetTexture(string id);
	bool LoadTexture(string id, string filename);
	void DropTexture(string id);
	void Clear();

	void Draw(string id, Transform* transform);
	void Draw(string id, int x, int y, int width, int height, SDL_RendererFlip flip);
	void DrawSprite(string id, int x, int y, int width, int height, int scaledWidth, int scaledHeight, int row, int col, SDL_RendererFlip flip);

private:
	map<string, SDL_Texture*> textureMap;
};

#endif
