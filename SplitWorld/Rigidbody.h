#pragma once
#ifndef Rigidbody_hpp
#define Rigidbody_hpp
#include "Vector2D.h"
class Rigidbody
{
public:
	Rigidbody() { this->mass = 1; this->gravity = 9.8; };
	Rigidbody(float m, float g) :mass(m), gravity(g) {};

	inline void SetMass(float mass) { this->mass = mass; };
	inline float GetMass() { return this->mass; };

	inline void SetGravity(float gravity) { this->gravity = gravity; };
	inline float GetGravity() { return this->gravity; };

	inline Vector2D GetPosition() { return this->position; };
	inline Vector2D GetVelocity() { return this->velocity; };
	inline Vector2D GetAcceleration() { return this->acceleration; };
	inline Vector2D GetForce() { return this->force; };


	inline void ApplyForce(Vector2D force) { this->force = force; };
	inline void ApplyForceX(float x) { this->force.x = x; }
	inline void ApplyForceY(float y) { this->force.y = y; }
	inline void RemoveForces() { this->force.x = this->force.y = 0; }

	void Update(float deltaTime)
	{
		acceleration.x = force.x * (1 / mass);
		acceleration.y = gravity + force.y * (1 / mass);
		velocity = acceleration * deltaTime;
		position = velocity * deltaTime;
	}



private:
	float mass;
	float gravity;

	Vector2D force;
	Vector2D friciton;

	Vector2D position;
	Vector2D velocity;
	Vector2D acceleration;
};
#endif