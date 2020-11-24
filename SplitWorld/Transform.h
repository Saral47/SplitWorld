#pragma once
#ifndef Transform_hpp
#define Transform_hpp
#define SDL_MAIN_HANDLED
#include<iostream>
#include "Vector2D.h"

using namespace std;
//I tried making the transform class to be similar to how it is in Unity. There's still a couple of missing parts like rotation and some more flexibility when it comes to scaling(in place/with translation).
class Transform
{

public:
	Vector2D* position;
	Vector2D* scale;
	int scaledWidth, scaledHeight;
	int orgWidth, orgHeight;
	SDL_RendererFlip flip;

	Transform(float xIn = 0, float yIn = 0, float sXIn = 1, float sYIn = 1, int width = 0, int height = 0, SDL_RendererFlip flip = SDL_FLIP_NONE) {
		position = new Vector2D(xIn, yIn);
		scale = new Vector2D(sXIn, sYIn);
		scaledWidth = orgWidth = width;
		scaledHeight = orgHeight = height;
		this->flip = flip;
		SetScaleX(sXIn);
		SetScaleY(sYIn);
	}


	inline void TranslateX(float x) { position->x = position->x + x; }
	inline void TranslateY(float y) { position->y = position->y + y; }
	inline void Translate(Vector2D v) { position->x = position->x + v.x; position->y = position->y + v.y; }


	inline void SetScaleX(float x)
	{
		scale->x = x;
		scaledWidth = x * orgWidth;
		position->x = position->x + (orgWidth - scaledWidth) / 2;
	}
	inline void SetScaleY(float y)
	{
		//cout << "X: " << scale->x << " Y: " << scale->y << " W: " << orgWidth << " H: " << orgHeight << " SW: " << scaledWidth << " SH: " << scaledHeight << endl;
		scale->y = y;
		scaledHeight = orgHeight * y;
		position->y = position->y + (orgHeight - scaledHeight) / 2;
		//cout << "X: " << position->x << " Y: " << position->y << " W: " << orgWidth << " H: " << orgHeight << " SW: " << scaledWidth << " SH: " << scaledHeight << endl;
	}

	inline void ResetScale() { SetScaleX(1); SetScaleY(1); }


};
#endif

