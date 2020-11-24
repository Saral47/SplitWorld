#include "Collision.h"
#include "GameEngine.h"

Collision* Collision::instance = nullptr;

Collision::Collision()
{

}

bool Collision::BoxCollisionCheck(SDL_Rect A, SDL_Rect B)
{

	if (A.x + A.w < B.x) return false;
	if (A.x > B.x + B.w) return false;
	if (A.y + A.h < B.y) return false;
	if (A.y > B.y + B.h) return false;

	return true;

}

bool Collision::CircleCollisionCheck(CircleCollider A, CircleCollider B)
{
	if (distance(A.position, B.position) > A.radius + B.radius)
		return true;
	return false;
}

