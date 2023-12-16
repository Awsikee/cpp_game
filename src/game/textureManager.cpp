#include "../inc/game/textureManager.hpp"

SDL_Texture *TextureManager::LoadTexture(const char *texture)
{
    SDL_Surface *tmpSurface = IMG_Load(texture);
    SDL_Texture *tex = nullptr;
    if(tmpSurface){
        tex = SDL_CreateTextureFromSurface(Game::renderer, tmpSurface);
    }
    else
    {
        std::cout << "Could not load Image"  <<std::endl;
    }
    SDL_FreeSurface(tmpSurface);

    return tex;
}

 void TextureManager::Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest)
 {
    SDL_RenderCopy(Game::renderer, tex, &src, &dest);
 }
