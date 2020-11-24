#include "Melethril.h"
#include "TextureManager.h"
#include "PlayerInput.h"
#include <SDL.h>
#include"Collision.h"

//The Player class of the project. 
Melethril::Melethril(GameObjectData* data, string s, float mass, int world) :Character(data)
{
	animation = new Animation();
	animation->SetAnimation(this->textureID, 0, 0, 1, 60, this->transform->flip);

	rigidbody = new Rigidbody(mass, gravity);
	boxCollider = new BoxCollider();
	boxCollider->SetBuffer(0, 0, 0, 0);
	this->name = s;
	this->gravity = gravity;
	this->world = world;
	this->jumpForce = JUMP_FORCE;
	this->jumpTime = JUMP_TIME;
	this->doubleJumpForce = DOUBLE_JUMP_FORCE;

	isGrounded = true;

	ground.x = 0;
	ground.y = 515;
	ground.w = 1920;
	ground.h = 50;
}

void Melethril::Update(float deltaTime)
{


	rigidbody->RemoveForces();


	// JUMP
	if (PlayerInput::GetInstance()->GetKey(SDL_SCANCODE_UP) && isGrounded && this->name == "t")
	{
		isJumping = true;
		isGrounded = false;
		canDoubleJump = true;
		hasDoubleJumped = false;
		rigidbody->ApplyForceY(-jumpForce * world);
		cout << "STARTED JUMP" << endl;
	}

	else if (PlayerInput::GetInstance()->GetKey(SDL_SCANCODE_UP) && isJumping && jumpTime > 0 && hasDoubleJumped == false && this->name == "t")
	{
		jumpTime = jumpTime - deltaTime;
		rigidbody->ApplyForceY(-jumpForce * world);
		//cout << "IF JUMP TIME :" << jumpTime << endl;
	}
	else if (PlayerInput::GetInstance()->GetKey(SDL_SCANCODE_UP) && isJumping && jumpTime <= 0 && hasDoubleJumped == false && this->name == "t")
	{
		isJumping = false;
		jumpTime = JUMP_TIME;
		isFalling = true;
		cout << "MAX JUMP REACHED " << jumpTime << endl;
	}


	if (PlayerInput::GetInstance()->GetKey(SDL_SCANCODE_DOWN) && isGrounded && this->name == "mol")
	{
		isJumping = true;
		isGrounded = false;
		canDoubleJump = true;
		hasDoubleJumped = false;
		rigidbody->ApplyForceY(-jumpForce * world);
		cout << "STARTED JUMP" << endl;
	}
	if (PlayerInput::GetInstance()->GetKey(SDL_SCANCODE_DOWN) && isJumping && jumpTime > 0 && hasDoubleJumped == false && this->name == "mol")
	{
		jumpTime = jumpTime - deltaTime;
		rigidbody->ApplyForceY(-jumpForce * world);
		//cout << "IF JUMP TIME :" << jumpTime << endl;
	}
	else if (PlayerInput::GetInstance()->GetKey(SDL_SCANCODE_DOWN) && isJumping && jumpTime <= 0 && hasDoubleJumped == false && this->name == "mol")
	{
		isJumping = false;
		jumpTime = JUMP_TIME;
		isFalling = true;
		cout << "MAX JUMP REACHED " << jumpTime << endl;
	}


	if (isFalling)
	{
		rigidbody->SetGravity(GRAVITY * world);
	}


	// Collision checks. If the gameobject collides with something like the ground, it is pushed back to it's previous location.
	//cout << "RIGID " << rigidbody->GetForce().x << " " << rigidbody->GetForce().y << endl;
	rigidbody->Update(deltaTime);
	lastCollisionFreePos.x = transform->position->x;
	transform->position->x = transform->position->x + rigidbody->GetPosition().x;
	boxCollider->SetCollider(transform->position->x, transform->position->y, 136, 195);
	if (Collision::GetInstance()->BoxCollisionCheck(boxCollider->GetCollider(), ground)) //Collision correction with respect to x
	{
		transform->position->x = lastCollisionFreePos.x;
	}
	rigidbody->Update(deltaTime);
	lastCollisionFreePos.y = transform->position->y;
	transform->TranslateY(this->rigidbody->GetPosition().y);
	boxCollider->SetCollider(transform->position->x, transform->position->y, 136, 195);
	if (Collision::GetInstance()->BoxCollisionCheck(boxCollider->GetCollider(), ground)) //Collision correction with respect to x
	{
		//	cout << "In collision" << endl;
		isGrounded = true;
		isJumping = false;
		jumpTime = JUMP_TIME;
		rigidbody->SetGravity(0);
		transform->position->y = lastCollisionFreePos.y;
	}
	else
	{
		isGrounded = false;
		rigidbody->SetGravity(GRAVITY * world);
	}

	animation->Update();
	SetAnimationState();
}

void Melethril::Draw()
{
	animation->Draw(this->transform->position->x, this->transform->position->y, this->transform->orgWidth, this->transform->orgHeight, this->transform->scaledWidth, this->transform->scaledHeight);
	boxCollider->ShowCollider();
	SDL_RenderDrawRect(GameEngine::GetInstance()->GetRenderer(), &this->ground);
}
void Melethril::SetAnimationState()
{
	if (isGrounded)
		animation->SetAnimation("melethril_idle", 0, 0, 1, 60, this->transform->flip);

	if (isJumping)
		animation->SetAnimation("melethril_jump", 0, 0, 3, 600, this->transform->flip);
}
void Melethril::Clear()
{
	//TextureManager::GetInstance()->Clear();
}
