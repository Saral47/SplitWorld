#include "Background.h"
#include "TextureManager.h"
Background::Background(GameObjectData* data, int wL, int wR, int lSpeed) :GameObject(data)
{
	wrapMaxLeft = wL;
	wrapMaxRight = wR;
	layerSpeed = lSpeed;
}

void Background::Update(float deltaTime)
{
	this->transform->TranslateX(-this->layerSpeed * deltaTime);

	if (this->transform->position->x < wrapMaxLeft)
		this->transform->position->x = 0;
}

void Background::Draw()
{
	TextureManager::GetInstance()->Draw(this->textureID, this->transform->position->x, this->transform->position->y, this->transform->orgWidth, this->transform->orgHeight, this->transform->flip);
	TextureManager::GetInstance()->Draw(this->textureID, this->transform->position->x - wrapMaxLeft, this->transform->position->y, this->transform->orgWidth, this->transform->orgHeight, this->transform->flip);
}

void Background::Clear()
{
	//TextureManager::GetInstance()->Clear();
}