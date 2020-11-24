#pragma once
#ifndef Melethril_hpp
#define Melethril_hpp
#include "Character.h"
#include "Rigidbody.h"
#include "BoxCollider.h"

#define JUMP_FORCE 20.0f
#define DOUBLE_JUMP_FORCE 15.0f
#define JUMP_TIME 30
#define DOUBLE_JUMP_TIME 25.0f;
#define GRAVITY 7
class Melethril : public Character
{
public:
	Melethril(GameObjectData* data, string name, float mass, int world);

	virtual void Draw();
	virtual void Update(float deltaTime);
	virtual void Clear();

	void SetAnimationState();
	BoxCollider* boxCollider;
	Rigidbody* rigidbody;

	Vector2D lastCollisionFreePos;

	bool isGrounded;
	bool isJumping;
	bool isFalling;
	bool canDoubleJump;
	bool hasDoubleJumped;
	float jumpTime;
	float jumpForce;

	float gravity;
	float doubleJumpForce;
	float world;

	SDL_Rect ground;

};
#endif
