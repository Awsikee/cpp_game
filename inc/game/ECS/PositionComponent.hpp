#ifndef POSITIONCOMPONENTCLASS_HPP
#define POSITIONCOMPONENTCLASS_HPP

#include "Components.hpp"
#include "../Vector2D.hpp"

class PositionComponent : public Component
{

public:
    Vector2D position;
    Vector2D velocity;

    int height = 128;
    int width = 128;
    float scale = 1.0f;

    int speed = 2;

    PositionComponent()
    {
        position.x = SCREEN_CENTER_X;
        position.y = SCREEN_CENTER_Y;    
    }
    PositionComponent(float sc)
    {
        position.x = SCREEN_CENTER_X;
        position.y = SCREEN_CENTER_Y;

        scale= sc;
    }
    PositionComponent(float x, float y)
    {
        position.x = x;
        position.y = y;
    }

    PositionComponent(float x, float y, int w, int h, float sc)
    {
        position.x = x;
        position.y = y;
        width = w;
        height = h;
        scale = sc;
    }

    void init() override
    {
        velocity.Zero();
    }

    void update() override
    {
    }
};

#endif