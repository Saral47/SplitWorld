#include "Animation.h"
#include "TextureManager.h"


void Animation::SetAnimation(string textureID, int spriteRow, int spriteCol, int spriteCount, int animationSpeed, SDL_RendererFlip flip)
{
	this->textureID = textureID;
	this->spriteRow = spriteRow;
	this->spriteCol = spriteCol;
	this->spriteRowCount = spriteCount;
	this->animationSpeed = animationSpeed;
	this->flip = flip;
}
void Animation::Update()
{
	//cout << "SDL TICKS " << SDL_GetTicks() << endl;
	this->spriteCol = (SDL_GetTicks() / this->animationSpeed) % this->spriteRowCount;
	//cout << "SPRITE COL UPDATE " <<this->spriteCol<<endl;
}
void Animation::Draw(float x, float y, int width, int height, int scaledWidth, int scaledHeight)
{
	//cout << "SPRITE COL DRAW   " << this->spriteCol << endl;
	TextureManager::GetInstance()->DrawSprite(this->textureID, x, y, width, height, scaledWidth, scaledHeight, this->spriteRow, this->spriteCol, this->flip);

}

