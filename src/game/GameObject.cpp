#include "../../inc/game/GameObject.hpp"
#include "../../inc/game/textureManager.hpp"

GameObject::GameObject(const char* texturesheet, SDL_Renderer* ren, int x, int y) 
: renderer(ren), xpos(x), ypos(y)
{
    objTexture = TextureManager::LoadTexture(texturesheet,ren);
}

GameObject::~GameObject()
{

}

void GameObject::update()
{
    xpos++;
    ypos++;

    srcRect.h = 80;
    srcRect.w = 64;
    srcRect.x = 0;
    srcRect.y = 0;

    destRect.x = xpos;
    destRect.y = ypos;
    destRect.w = srcRect.w *2;
    destRect.h = srcRect.h *2;

}

void GameObject::renderObj()
{
    SDL_RenderCopy(renderer,objTexture, NULL, &destRect);
}