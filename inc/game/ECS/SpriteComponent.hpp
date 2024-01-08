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

        bool animated = false;
        int frames = 0;
        int speed = 100;

    public:
     SpriteComponent() = default;
     SpriteComponent(const char* path)
     {
        setTex(path);
     }

     SpriteComponent(const char* path, int nFrames, int mSpeed)
     {
         animated = true;
         frames = nFrames;
         speed = mSpeed;
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
        srcRect.w = 256; //To be changed when image sizes are standarized
        srcRect.h = 256;  //To be changed when image sizes are standarized

     }
     void update() override
     {
         if(animated)
         {
            srcRect.x =srcRect.w * static_cast<int> (SDL_GetTicks() /speed % frames);
         }
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