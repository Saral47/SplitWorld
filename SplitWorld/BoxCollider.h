#pragma once
#ifndef BoxCollider_hpp
#define BoxCollider_hpp
#define SDL_MAIN_HANDLED
#include<SDL.h>

//Box collider class is bascially a slightly more useful version of SDL_Rect.
class BoxCollider
{
public:
	inline SDL_Rect GetCollider() { return box; }
	inline void SetBuffer(int x, int y, int w, int h) { boxBuffer.x = x; boxBuffer.y = y; boxBuffer.w = w; boxBuffer.h = h; }
	inline void SetCollider(int x, int y, int w, int h) { box.x = x - boxBuffer.x; box.y = y - boxBuffer.y; box.w = w - boxBuffer.w; box.h = h - boxBuffer.h; }

	void ShowCollider();

private:
	SDL_Rect box;
	SDL_Rect boxBuffer;
};
#endif
