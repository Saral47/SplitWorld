#pragma once
#ifndef Particle_hpp
#define Particle_hpp
#include <SDL.h>
#include <string.h>
#include "Transform.h"
#include "Vector2D.h"
#include "TextureManager.h"
#include "RandomGenerator.h"
#include "BoxCollider.h"
#include "GameEngine.h"
#include "Collision.h"

//Particle class, this is a general class that is inherited by other classes to create different types of particles. (Ex the Rain class)
//Note: This class will undergo changes since it is not as robust as I'd like it to be. For example, I'd need different kind of behavior for both worlds.
class Particle
{
public:
	Particle(string textureID, Transform t, float vX, float vY, int lifeTime)
	{
		this->velocity.x = vX;
		this->velocity.y = vY;
		this->textureID = textureID;
		this->transform = Transform(t.position->x, t.position->y, t.scale->x, t.scale->y, t.orgWidth, t.orgHeight);

		this->lifetime = SDL_GetTicks() + lifeTime;

		this->boxCollider.SetCollider(t.position->x, t.position->y, t.orgWidth, t.orgHeight);
	}
	virtual void Update(float deltaTime)
	{
		transform.Translate(velocity * deltaTime);

	}
	virtual void Render()
	{
		//	cout << transform.position->x << " " << transform.position->y << " " << transform.orgWidth << " " << transform.orgHeight << endl;
		TextureManager::GetInstance()->Draw(textureID, &transform);
	};
	virtual bool DeathCheck(int world)
	{
		if (world == 1)
		{
			if (this->lifetime < (int)SDL_GetTicks() || (int)transform.position->x < 0 || (int)transform.position->x > 1920 || (int)transform.position->y < 0 || (int)transform.position->y > 515)
				return true;
		}

		else if (world == -1)
		{

			if (this->lifetime < (int)SDL_GetTicks() || (int)transform.position->x < 0 || (int)transform.position->x > 1920 || (int)transform.position->y > 1080 || (int)transform.position->y < 565)
				return true;
		}
		return false;
	}
	string textureID;
	Transform transform;
	Vector2D velocity;
	int lifetime;

	BoxCollider boxCollider;
};
#endif
