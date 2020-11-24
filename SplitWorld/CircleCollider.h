#pragma once
#ifndef CircleCollider_hpp
#define CircleCollider_hpp
#include "Vector2D.h"
#include <math.h>
class CircleCollider
{
public:

	inline void SetBuffer(float b = 0) { bufferRadius = b; };
	inline void SetCollider(int x, int y, int width, int height)
	{

		float dia = sqrt(width * width + height * height);
		radius = dia / 2 + bufferRadius;

		position->x = x + width / 2;
		position->y = y + height / 2;
	}

	float radius;
	float bufferRadius;
	Vector2D* position;

	float GetColliderRadius()
	{
		return radius;
	}

	Vector2D* GetColliderPosition()
	{
		return position;
	}
};
#endif
