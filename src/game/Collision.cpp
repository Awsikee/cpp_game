#include "../../inc/game/ECS/Collision.hpp"
#include "../../inc/game/ECS/ColliderComponent.hpp"


CollisionDirection Collision::isColliding(const SDL_Rect& recA, const SDL_Rect& recB)
{
    // Check for horizontal separation
    bool separateX = recA.x + recA.w < recB.x || recB.x + recB.w < recA.x;

    // Check for vertical separation
    bool separateY = recA.y + recA.h < recB.y || recB.y + recB.h < recA.y;

    bool collision = recA.x + recA.w >= recB.x &&
        recB.x + recB.w >= recA.x &&
        recA.y + recA.h >= recB.y &&
        recB.y + recB.h >= recA.y;

    // If both horizontal and vertical separations exist, then there is no collision
    if (!collision)
    {
        return CollisionDirection::NONE;
    }
    else if (separateX) // Only vertical overlap
    {
        if (recA.y < recB.y) // recA is above recB
        {
            return CollisionDirection::UP;
        }
        else // recA is below recB
        {
            return CollisionDirection::DOWN;
        }
    }
    else if (separateY) // Only horizontal overlap
    {
        if (recA.x < recB.x) // recA is to the left of recB
        {
            return CollisionDirection::LEFT;
        }
        else // recA is to the right of recB
        {
            return CollisionDirection::RIGHT;
        }
    }
    else // Overlap on both axes
    {
        // Determine the axis with the minimum overlap
        int xDistance = std::min(recA.x + recA.w - recB.x, recB.x + recB.w - recA.x);
        int yDistance = std::min(recA.y + recA.h - recB.y, recB.y + recB.h - recA.y);

        if (xDistance < yDistance) // Collision is primarily horizontal
        {
            if (recA.x < recB.x) // recA is to the left of recB
            {
                return CollisionDirection::LEFT;
            }
            else // recA is to the right of recB
            {
                return CollisionDirection::RIGHT;
            }
        }
        else // Collision is primarily vertical
        {
            if (recA.y < recB.y) // recA is above recB
            {
                return CollisionDirection::UP;
            }
            else // recA is below recB
            {
                return CollisionDirection::DOWN;
            }
        }
    }
}

bool Collision::AABB(const SDL_Rect& recA, const SDL_Rect& recB)
{
    // Check for horizontal separation
    bool separateX = recA.x + recA.w < recB.x || recB.x + recB.w < recA.x;

    // Check for vertical separation
    bool separateY = recA.y + recA.h < recB.y || recB.y + recB.h < recA.y;

    // If both horizontal and vertical separations exist, then there is no collision
    if (separateX || separateY)
    {
        return false;
    }

    // Otherwise, there is a collision
    return true;
}


bool Collision::AABB(const ColliderComponent &colA, const ColliderComponent &colB)
{
    if (AABB(colA.collider, colB.collider))
    {
        std::cout << colA.tag << "hit: " << colB.tag << std::endl;
        return true;
    }
    else
    {
        return false;
    }
}