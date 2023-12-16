#include "game.hpp"


class GameObject{

    public:
    GameObject();
    GameObject(const char* texturesheet, SDL_Renderer* ren, int x, int y);
    ~GameObject();

    void update();      // TBD: virtual method
    void renderObj();   // TBD: virtual method
 
    protected:
    int xpos;
    int ypos;

    SDL_Texture* objTexture;
    SDL_Rect srcRect, destRect;
    SDL_Renderer* renderer;
};