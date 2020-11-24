#pragma once
#ifndef ParticleEmitter_hpp
#define ParticleEmitter_hpp
#include<vector>
#include<string>
#include<math.h>
#include "Rain.h"
#include "TextureManager.h"
#include "Transform.h"
#define MAXRAINPARTICLES 200


using namespace std;

// Particle emitter class that handles all kinds of particles. I might use this class to derive other specialized emitters.
class ParticleEmitter
{

public:
	ParticleEmitter()
	{

	}

	vector<Particle*> particles;
	string textureID;
	int maxParticles;
	int currentParticles = 0;

	virtual void Initialize(string textureID, int particleType, int maxEmitterParticles)
	{
		this->textureID = textureID;
		this->maxParticles = maxEmitterParticles;

		int generateCount;

		if (currentParticles + MAXRAINPARTICLES > maxParticles)
			generateCount = currentParticles + MAXRAINPARTICLES - maxParticles;
		else
			generateCount = MAXRAINPARTICLES;


		switch (particleType)
		{
		case 0:

			this->currentParticles += generateCount;
			for (int i = 0; i < generateCount; i++)
			{
				int x, y;
				float vX = 0;
				float vY = 0;
				x = RandomGenerator::GetInstance()->RandomRange(0, 1920);
				y = RandomGenerator::GetInstance()->RandomRange(1080, 1130);

				vX = RandomGenerator::GetInstance()->RandomRange(-4, -1);
				vY = RandomGenerator::GetInstance()->RandomRange(4, 16);
				particles.push_back(new Rain(textureID, Transform(x, y, 1, 1, 15, 15, SDL_FLIP_NONE), vX, vY, 4000, 1, "raindrop"));

			}
			break;
		case 1:
			cout << "HERE" << endl;
			this->currentParticles += generateCount;
			for (int i = 0; i < generateCount; i++)
			{
				int x, y;
				float vX = 0;
				float vY = 0;
				x = RandomGenerator::GetInstance()->RandomRange(0, 1920);
				y = RandomGenerator::GetInstance()->RandomRange(1080, 1180);

				vX = RandomGenerator::GetInstance()->RandomRange(-4, -1);
				vY = RandomGenerator::GetInstance()->RandomRange(4, 16) * -1;
				particles.push_back(new Rain(textureID, Transform(x, y, 1, 1, 15, 15, SDL_FLIP_NONE), vX, vY, 4000, -1, "blooddrop"));
			}
			break;
		default:
			break;
		}
	}
	virtual void Update(float deltaTime)
	{
		for (int i = 0; i < (int)particles.size(); i++)
			particles[i]->Update(deltaTime);
	}
	virtual void Render()
	{
		for (int i = 0; i < (int)particles.size(); i++)
			particles[i]->Render();
	}

	virtual void ClearParticles()
	{
		particles.clear();
	}
};
#endif

