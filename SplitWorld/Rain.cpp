#include "Rain.h"
#include<string>


Rain::Rain(string textureID, Transform t, float vX, float vY, int lifeTime, int world, string rMT) :Particle(textureID, t, vX, vY, lifeTime)
{
	rainModTexture = rMT;
	this->world = world;
}

//Custom update for the rain particle effect
void Rain::Update(float deltaTime)
{
	//cout << velocity.x << " " << velocity.y <<" "<< transform.position->x<<" "<< transform.position->y<<endl;
	transform.Translate(velocity * deltaTime);
	if (DeathCheck(this->world))
	{

		if (world == 1)
		{
			textureID = "raindrop";
			transform.position->x = RandomGenerator::GetInstance()->RandomRange(0, 1920);
			transform.position->y = RandomGenerator::GetInstance()->RandomRange(0, 100);
			velocity.x = RandomGenerator::GetInstance()->RandomRange(-4, -1);
			velocity.y = RandomGenerator::GetInstance()->RandomRange(4, 16);

		}
		if (this->world == -1)
		{
			textureID = "blooddrop";
			transform.position->x = RandomGenerator::GetInstance()->RandomRange(0, 1920);
			transform.position->y = RandomGenerator::GetInstance()->RandomRange(0, 100) + 1080;
			velocity.x = RandomGenerator::GetInstance()->RandomRange(-4, -1);
			velocity.y = RandomGenerator::GetInstance()->RandomRange(4, 16) * -1;
		}
		lifetime = SDL_GetTicks() + 5000;
	}

	this->boxCollider.SetCollider(transform.position->x, transform.position->y, transform.orgWidth, transform.orgHeight);

	//Collision checks with the player.
	if (Collision::GetInstance()->BoxCollisionCheck(GameEngine::GetInstance()->t->boxCollider->GetCollider(), boxCollider.GetCollider()))
	{
		textureID = "blooddrop";
	}
	if (Collision::GetInstance()->BoxCollisionCheck(GameEngine::GetInstance()->mol->boxCollider->GetCollider(), boxCollider.GetCollider()))
	{
		textureID = "raindrop";
	}
}