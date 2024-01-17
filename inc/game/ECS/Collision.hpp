
#ifndef COLLISIONCLASS
#define COLLISIONCLASS

#include "SDL.h"
enum class CollisionDirection { NONE, UP, DOWN, LEFT, RIGHT };

class ColliderComponent;

class Collision
{
    public:
    static bool AABB(const SDL_Rect& recA, const SDL_Rect& recB);
    static bool AABB(const ColliderComponent& colA, const ColliderComponent& colB);
    static CollisionDirection Collision::isColliding(const SDL_Rect& recA, const SDL_Rect& recB);
    
};

#endif