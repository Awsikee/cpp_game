
#ifndef COLLIDERCOMPONENTCLASS
#define COLLIDERCOMPONENTCLASS

#include <string>
#include "SDL.h"
#include "Components.hpp"

class ColliderComponent : public Component
{
    public:
    SDL_Rect collider;
    std::string tag;

    PositionComponent* transform;

    ColliderComponent(std::string t)
    {
        tag = t;
    }

    void init() override
    {
        if(!entity->hasComponent<PositionComponent>())
        {
            entity->addComponent<PositionComponent>();
        }
        transform = &entity->getComponent<PositionComponent>();

        Game::colliders.push_back(this);
    }

    void update() override
    {
        collider.x = transform->position.x;
        collider.y = transform->position.y;
        collider.w = static_cast<int>(transform->width * transform->scale);
        collider.h = static_cast<int>(transform->height * transform->scale);
    }


};


#endif