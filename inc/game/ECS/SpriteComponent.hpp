#ifndef SPRITECOMPONENTCLASS_HPP
#define SPRITECOMPONENTCLASS_HPP

#include "Components.hpp"
#include "../textureManager.hpp"
#include "SDL.h"


class SpriteComponent : public Component
{
    private:
        PositionComponent *position;
        SDL_Texture *texture;
        SDL_Rect srcRect, destRect;

    public:
     SpriteComponent() = default;
     SpriteComponent(const char* path)
     {
        texture = TextureManager::LoadTexture(path);
     }
     void init() override
     {
        position = &entity->getComponent<PositionComponent>();

        srcRect.x = srcRect.y = 0;
        srcRect.w = 768; //To be changed when image sizes are standarized
        srcRect.h = 980;  //To be changed when image sizes are standarized
        destRect.w = destRect.h = 64;

     }
     void update() override
     {
        destRect.x = position->x();
        destRect.y = position->y();
     }
     void draw() override
     {
        TextureManager::Draw(texture,srcRect,destRect);
     }
};

#endif