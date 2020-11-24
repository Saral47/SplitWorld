#pragma once
#ifndef Rain_hpp
#define Rain_hpp
#include "Particle.h"

//Custom Particle effect derived from the Particle class. Rain has additional parameters unique to the game.
//Raindrops also check for collision with the player characters. On collision the rain drop switches color.
class Rain : public Particle
{

public:
    string rainModTexture;
    int world;
    Rain(string textureID, Transform t, float vX, float vY, int lifeTime, int world, string rmT);
    void Update(float deltaTime);
    void Reset();
};


#endif
