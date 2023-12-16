#ifndef TEXTUREMANAGERCLASS_HPP
#define TEXTUREMANAGERCLASS_HPP

#include "game.hpp"

class TextureManager
{
public:
    static SDL_Texture *LoadTexture(const char *fileName, SDL_Renderer *renderer);
};

#endif