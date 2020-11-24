#include "GameEngine.h"
void BoxCollider::ShowCollider()
{
	SDL_Rect box = GetCollider();
	SDL_RenderDrawRect(GameEngine::GetInstance()->GetRenderer(), &box);
}