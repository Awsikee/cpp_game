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
     ~SpriteComponent()
     {
         SDL_DestroyTexture(texture);
     }
     void init() override
     {
        transform = &entity->getComponent<PositionComponent>();

        srcRect.x = srcRect.y = 0;
        srcRect.w = transform->width; //To be changed when image sizes are standarized
        srcRect.h = transform->height;  //To be changed when image sizes are standarized

     }
     void update() override
     {
        destRect.x = static_cast<int>(transform->position.x);
        destRect.y = static_cast<int>(transform->position.y);
        destRect.w = transform->width * transform->scale;
        destRect.h = transform->height * transform->scale;

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