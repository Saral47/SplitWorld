#pragma once
#ifndef Animation_hpp
#define Animation_hpp
#include<string>
#include<SDL.h>
using namespace std;

//This class handles sprite animation. Rather than having it bloat up the GameObject update, an individual class handles it. The gameobject only needs to calls this class' update function
struct AnimationData
{
public:
	AnimationData(string textureID, int spriteRow, int spriteCol, int spriteRowCount, int animationSpeed, SDL_RendererFlip flip)
	{
		this->textureID = textureID;
		this->spriteRow = spriteRow;
		this->spriteCol = spriteCol;
		this->spriteRowCount = spriteRowCount;
		this->animationSpeed = animationSpeed;
		this->flip = flip;
	}
	string textureID;
	int spriteRow;
	int spriteCol;
	int spriteRowCount;
	int animationSpeed;
	SDL_RendererFlip flip;
};
class Animation
{
public:
	Animation() {}
	Animation(AnimationData* animationData) :textureID(animationData->textureID), spriteRow(animationData->spriteRow), spriteCol(animationData->spriteCol),
		spriteRowCount(animationData->spriteRowCount), animationSpeed(animationData->animationSpeed), flip(animationData->flip) {};

	void SetAnimation(string textureID, int spriteRow, int spriteCol, int spriteCount, int animationSpeed, SDL_RendererFlip flip);
	void Update();
	void Draw(float x, float y, int width, int height, int scaledWidth, int scaledHeight);

private:
	string textureID;
	int spriteRow;
	int spriteCol;
	int spriteRowCount;
	int animationSpeed;
	SDL_RendererFlip flip;
};
#endif