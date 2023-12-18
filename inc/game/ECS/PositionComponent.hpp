#ifndef POSITIONCOMPONENTCLASS_HPP
#define POSITIONCOMPONENTCLASS_HPP

#include "Components.hpp"
#include "../Vector2D.hpp"

class PositionComponent : public Component
{

public:

    Vector2D posiiton;


    PositionComponent()
    {
        posiiton.x = 0.0f;
        posiiton.y = 0.0f;
    }
    PositionComponent(float x, float y)
    {
        posiiton.x = x;
        posiiton.y = y;
    }

    void update() override
    {
        
    }


};

#endif