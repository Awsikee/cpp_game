
#ifndef COLLISIONCLASS
#define COLLISIONCLASS

#include "SDL.h"

class Collision
{
    public:
    static bool AABB(const SDL_Rect& recA, SDL_Rect& recB);
    
};

#endif