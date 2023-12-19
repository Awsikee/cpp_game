#ifndef SPRITECOMPONENTCLASS_HPP
#define SPRITECOMPONENTCLASS_HPP

#include "Components.hpp"
#include "../textureManager.hpp"
#include "SDL.h"


class SpriteComponent : public Component
{
    private:
        PositionComponent *transform;
        SDL_Texture *texture;
        SDL_Rect srcRect, destRect;

    public:
     SpriteComponent() = default;
     SpriteComponent(const char* path)
     {
        setTex(path);
     }
     void init() override
     {
        transform = &entity->getComponent<PositionComponent>();

        srcRect.x = srcRect.y = 0;
        srcRect.w = 768; //To be changed when image sizes are standarized
        srcRect.h = 980;  //To be changed when image sizes are standarized
        destRect.w = destRect.h = 64;

     }
     void update() override
     {
        destRect.x = (int)transform->position.x;
        destRect.y = (int)transform->position.y;
     }
     void draw() override
     {
        TextureManager::Draw(texture,srcRect,destRect);
     }

     void setTex(const char* path)
     {
         texture = TextureManager::LoadTexture(path);
     }
};

#endif