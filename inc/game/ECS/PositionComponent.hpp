#ifndef POSITIONCOMPONENTCLASS_HPP
#define POSITIONCOMPONENTCLASS_HPP

#include "Components.hpp"
#include "../Vector2D.hpp"

class PositionComponent : public Component
{

public:

    Vector2D position;
    Vector2D velocity;

    int height = 32;
    int width = 32;
    int scale = 1;

    int speed = 3;


    PositionComponent()
    {
        position.x = 0.0f;
        position.y = 0.0f;
    }
    PositionComponent(float x, float y)
    {
        position.x = x;
        position.y = y;
    }

        PositionComponent(float x, float y, int w, int h, int sc)
    {
        position.x = x;
        position.y = y;
        height = h;
        width = w;
        scale = sc;
    }

    void init() override
    {
        velocity.x = 0;
        velocity.y = 0;
    }

    void update() override
    {
        position.x += velocity.x * speed;
        position.y += velocity.y * speed;
        //std::cout<<position;
    }


};

#endif