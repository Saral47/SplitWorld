#pragma once
#ifndef GameObject_hpp
#define GameObject_hpp
#define SDL_MAIN_HANDLED
#include <string>
#include <vector> 
#include <SDL.h> 
#include <SDL_image.h> 
#include <SDL_timer.h>

#include "IObject.h"
#include "Transform.h"
#include "Animation.h"
using namespace std;


struct GameObjectData
{
public:
	GameObjectData(string textureID, int width, int height, float x, float y, float sX, float sY, SDL_RendererFlip flip)
	{
		this->textureID = textureID;
		this->width = width;
		this->height = height;
		this->x = x;
		this->y = y;
		this->flip = flip;
		this->sX = sX;
		this->sY = sY;
		this->flip = flip;
	}

	string textureID;
	int width, height;
	float x, y, sX, sY;
	SDL_RendererFlip flip;
};

class GameObject : public IObject
{
public:
	GameObject() {};
	GameObject(GameObjectData* data) :textureID(data->textureID)
	{
		this->transform = new Transform(data->x, data->y, data->sX, data->sY, data->width, data->height, data->flip);

	};
	virtual void Draw() = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void Clear() = 0;
protected:
	string textureID;
	Transform* transform;



	Animation* animation;



};

#endif

