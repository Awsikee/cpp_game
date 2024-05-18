
#ifndef COLLIDERCOMPONENTCLASS
#define COLLIDERCOMPONENTCLASS

#include <string>
#include "SDL.h"
#include "Components.hpp"
#include "../textureManager.hpp"


class ColliderComponent : public Component
{
    public:
    SDL_Rect collider;
    std::string tag;

    SDL_Texture* tex;
    SDL_Rect srcR, destR;

    PositionComponent* transform;

    ColliderComponent(std::string t)
    {
        tag = t;
        collider = {0};
    }

    ColliderComponent(std::string t, int x, int y)
    {
        tag =t;
        collider.x = x;
        collider.y = y;
        collider.h = collider.w = TILE_SIZE_SCALED;
    }

        ColliderComponent(std::string t, int x, int y, int h, int w)
    {
        tag =t;
        collider.x = x;
        collider.y = y;
        collider.h = h;
        collider.w = w;
    }

    void init() override
    {
        if(!entity->hasComponent<PositionComponent>())
        {
            entity->addComponent<PositionComponent>();
        }
        transform = &entity->getComponent<PositionComponent>();

        
        tex = TextureManager::LoadTexture("../assets/collider.png");
        srcR = {0,0,static_cast<int>(TILE_SIZE_SCALED),static_cast<int>(TILE_SIZE_SCALED)};
        destR = {collider.x, collider.y, collider.w, collider.h};

        Game::colliders.push_back(this);
    }

    void update() override
    {
        if(tag !="terrain")
        {
            collider.x = transform->position.x;
            collider.y = transform->position.y + 12;
            //collider.w = static_cast<int>(transform->width * transform->scale);
            //collider.h = static_cast<int>(transform->height * transform->scale);
        }

        destR.x = collider.x - Game::camera.x;
        destR.y = collider.y - Game::camera.y;

    }

    void draw() override
    {
        TextureManager::Draw(tex,srcR,destR);
    }


};


#endif