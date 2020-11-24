#pragma once
#ifndef Background_hpp
#define Background_hpp
#include "GameObject.h"
class Background : public GameObject
{
public:
	Background(GameObjectData* data, int wL, int wR, int layerSpeed);
	virtual void Draw();
	virtual void Update(float deltaTime);
	virtual void Clear();

	string name;
	float layerSpeed;

	int wrapMaxRight;
	int wrapMaxLeft;

};
#endif
