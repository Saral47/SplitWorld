#include "TextureManager.h"
#include "GameEngine.h"

TextureManager* TextureManager::instance = nullptr;

TextureManager::TextureManager()
{

}
SDL_Texture* TextureManager::GetTexture(string id)
{
	return textureMap[id];
}
bool TextureManager::LoadTexture(string id, string filename)
{
	SDL_Surface* sdlsurface = IMG_Load(filename.c_str());

	if (sdlsurface == nullptr)
	{
		cout << "Image " << filename << " failed to load : " << SDL_GetError() << endl;
		return false;
	}

	SDL_Texture* sdlTexture = SDL_CreateTextureFromSurface(GameEngine::GetInstance()->GetRenderer(), sdlsurface);

	if (sdlTexture == nullptr)
	{
		cout << "Texture " << filename << " failed to be created from surface : " << SDL_GetError() << endl;
		return false;
	}

	textureMap[id] = sdlTexture;

	return true;

}
void TextureManager::Draw(string id, Transform* transform)
{
	//cout << "DRAWING : " << transform->scaledWidth << " " << transform->scaledHeight << " " << transform->orgWidth << " " << transform->orgHeight << endl;
	SDL_Rect srcRect = { 0, 0,transform->orgWidth, transform->orgHeight };
	SDL_Rect destRect = { (int)transform->position->x, (int)transform->position->y, transform->scaledWidth, transform->scaledHeight };

	SDL_RenderCopyEx(GameEngine::GetInstance()->GetRenderer(), textureMap[id], &srcRect, &destRect, 0, nullptr, transform->flip);
}
void TextureManager::Draw(string id, int x, int y, int width, int height, SDL_RendererFlip flip)////////////////////////////not scale adj
{
	SDL_Rect srcRect = { 0, 0,width, height };
	SDL_Rect destRect = { x, y, width, height };

	SDL_RenderCopyEx(GameEngine::GetInstance()->GetRenderer(), textureMap[id], &srcRect, &destRect, 0, nullptr, flip);
}
void TextureManager::DrawSprite(string id, int x, int y, int width, int height, int scaledWidth, int scaledHeight, int row, int col, SDL_RendererFlip flip)
{
	SDL_Rect srcRect = { col * width, row * height, width, height };
	SDL_Rect destRect = { x, y, scaledWidth, scaledHeight };

	SDL_RenderCopyEx(GameEngine::GetInstance()->GetRenderer(), textureMap[id], &srcRect, &destRect, 0, nullptr, flip);
}

void TextureManager::DropTexture(string id)
{
	SDL_DestroyTexture(textureMap[id]);
	textureMap.erase(id);
}
void TextureManager::Clear()
{
	for (auto const& it : textureMap)
	{
		SDL_DestroyTexture(it.second);
	}

	textureMap.clear();

	cout << "Texture Map Cleared" << endl;
}

