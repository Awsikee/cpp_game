
#ifndef COLLISIONCLASS
#define COLLISIONCLASS

#include "SDL.h"
enum class CollisionDirection { NONE, UP, DOWN, LEFT, RIGHT, UP_LEFT, UP_RIGHT, DOWN_LEFT, DOWN_RIGHT };

class ColliderComponent;

class Collision
{
    public:
    static bool AABB(const SDL_Rect& recA, const SDL_Rect& recB);
    static bool AABB(const ColliderComponent& colA, const ColliderComponent& colB);
    static CollisionDirection isColliding(const SDL_Rect& recA, const SDL_Rect& recB);
    static CollisionDirection collisionByBoundaries(const SDL_Rect& recA, int minX, int maxX, int minY, int maxY);
    
};

#endif