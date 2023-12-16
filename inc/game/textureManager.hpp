#ifndef TEXTUREMANAGERCLASS_HPP
#define TEXTUREMANAGERCLASS_HPP

#include "game.hpp"
#include <iostream>

class TextureManager
{
public:
    static SDL_Texture *LoadTexture(const char *fileName);
    static void Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest);
};

#endif