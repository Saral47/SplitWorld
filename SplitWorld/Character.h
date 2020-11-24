#pragma once
#ifndef Character_hpp
#define Character_hpp
#include "GameObject.h"

class Character : public GameObject
{
public:
	Character(GameObjectData* data) : GameObject(data) {}
	virtual void Draw() = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void Clear() = 0;

protected:
	string name;
};
#endif