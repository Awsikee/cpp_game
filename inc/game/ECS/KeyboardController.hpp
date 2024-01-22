#ifndef KEYBOARDCOMPONENTCLASS_HPP
#define KEYBOARDCOMPONENTCLASS_HPP

#include "../game.hpp"
#include "ECS.hpp"
#include "Components.hpp"

class KeyboardController : public Component
{
private:
    bool isAnimated;

public:
    PositionComponent *transform;
    SpriteComponent *sprite;

    void init() override
    {
        transform = &entity->getComponent<PositionComponent>();
        if(entity->hasComponent<SpriteComponent>())
        {
            sprite = &entity->getComponent<SpriteComponent>();
        }
        else
        {
            isAnimated = false;
        }


    }
    void update() override
    {
        if (Game::event.type == SDL_KEYDOWN)
        {
            switch (Game::event.key.keysym.sym)
            {
            case SDLK_w:
                transform->velocity.y = -1 * transform->speed;
                if (isAnimated)
                {
                    sprite->play("walk_back");
                }
                break;
            case SDLK_a:
                transform->velocity.x = -1 * transform->speed;
                if (isAnimated)
                {
                    sprite->play("walk_left");
                }
                break;
            case SDLK_s:
                transform->velocity.y = 1 * transform->speed;
                if (isAnimated)
                {
                    sprite->play("walk_front");
                }
                break;
            case SDLK_d:
                transform->velocity.x = 1 * transform->speed;
                if (isAnimated)
                {
                    sprite->play("walk_right");
                }
                break;

            default:
                break;
            }
        }

        if (Game::event.type == SDL_KEYUP)
        {
            switch (Game::event.key.keysym.sym)
            {
            case SDLK_w:
                transform->velocity.y = 0;
                break;
            case SDLK_a:
                transform->velocity.x = 0;
                break;
            case SDLK_s:
                transform->velocity.y = 0;
                break;
            case SDLK_d:
                transform->velocity.x = 0;
                break;
            case SDLK_ESCAPE:
                Game::isRunning = false;
            default:
                break;
            }
        }
    }
};

#endif
