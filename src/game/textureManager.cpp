#include "../inc/game/textureManager.hpp"

SDL_Texture *TextureManager::LoadTexture(const char *texture, SDL_Renderer *renderer)
{
    SDL_Surface *tmpSurface = IMG_Load(texture);
    SDL_Texture *tex = nullptr;
    if(tmpSurface){
        tex = SDL_CreateTextureFromSurface(renderer, tmpSurface);
    }
    else
    {
        std::cout << "Could not load Image"  <<std::endl;
    }
    SDL_FreeSurface(tmpSurface);

    return tex;
}