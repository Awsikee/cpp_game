#ifndef SPRITECOMPONENTCLASS_HPP
#define SPRITECOMPONENTCLASS_HPP

#include "Components.hpp"
#include "../textureManager.hpp"
#include "Animation.hpp"
#include "SDL.h"
#include <map>

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
    int animIndex = 0;

    std::map<const char*, Animation> animations;

    SpriteComponent() = default;
    SpriteComponent(const char *path)
    {
        setTex(path);
    }

    SpriteComponent(const char *path, bool isAnimated)
    {
        animated = isAnimated;
        //Animation idle = Animation(0, 0, 100);
        Animation walk_front = Animation(0,10,100);
        Animation walk_back = Animation(1,10,100);
        Animation walk_left = Animation(2,10,100);
        Animation walk_right = Animation(3,10,100);

        animations.emplace("walk_front",walk_front);
        animations.emplace("walk_back",walk_back);
        animations.emplace("walk_left",walk_left);
        animations.emplace("walk_right",walk_right);

        play("walk_front");
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
        srcRect.w = 400; // To be changed when image sizes are standarized
        srcRect.h = 704; // To be changed when image sizes are standarized
    }
    void update() override
    {
        if (animated)
        {
            srcRect.x = srcRect.w * static_cast<int>(SDL_GetTicks() / speed % frames);
        }

        srcRect.y = animIndex * transform->height;

        destRect.x = static_cast<int>(transform->position.x);
        destRect.y = static_cast<int>(transform->position.y);
        destRect.w = transform->width * transform->scale;
        destRect.h = transform->height * transform->scale;
    }
    void draw() override
    {
        TextureManager::Draw(texture, srcRect, destRect);
    }

    void play(const char* animName)
    {
        frames = animations[animName].frames;
        animIndex = animations[animName].index;
        speed = animations[animName].speed;
    }

    void setTex(const char *path)
    {
        texture = TextureManager::LoadTexture(path);
    }
};

#endif