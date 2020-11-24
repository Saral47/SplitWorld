#pragma once
#ifndef Collision_hpp
#define Collision_hpp
#define SDL_MAIN_HANDLED

#include <SDL.h>
#include <math.h>
#include <vector>
#include "CircleCollider.h"
//Global collision checker, all collisions that happen in the game are detected through this class. 
class Collision
{
private:
	static Collision* instance;
	Collision();

public:
	inline static Collision* GetInstance() { if (!instance)instance = new Collision; return instance; };

	inline float Distance(Vector2D a, Vector2D b) { return sqrt((a.x - b.x) * (a.x - b.x) - (a.y - b.y) * (a.y - b.y)); }

	bool BoxCollisionCheck(SDL_Rect A, SDL_Rect B);
	bool CircleCollisionCheck(CircleCollider A, CircleCollider B);

};
#endif
