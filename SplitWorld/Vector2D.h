#pragma once
#ifndef Vector2D_hpp
#define Vector2D_hpp


#define UP -1
#define DOWN 1
#define RIGHT 1
#define LEFT -1
class Vector2D
{
public:
	float x, y;

	Vector2D(float xIn = 0, float yIn = 0) : x(xIn), y(yIn) {}

	inline Vector2D operator+ (Vector2D& v2) { return Vector2D(this->x + v2.x, this->y + v2.y); }
	inline Vector2D operator- (Vector2D& v2) { return Vector2D(this->x - v2.x, this->y - v2.y); }
	inline Vector2D operator* (float s) { return Vector2D(this->x * s, this->y * s); }

};

#endif

