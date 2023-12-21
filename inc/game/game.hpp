
#ifndef GAMECLASS_HPP
#define GAMECLASS_HPP

#include "../inc/include/SDL2/SDL.h"
#include "../SDL2_image-2.8.1/SDL_IMAGE/include/SDL_image.h"
#include "../../inc/dataDefinition.hpp"

#include <iostream>
#include <vector>

class ColliderComponent;
class Game
{
private:
    bool isRunning;
    SDL_Window *window;
    int count;

public:
    static SDL_Renderer *renderer;
    static SDL_Event event;
    static std::vector<ColliderComponent*> colliders;

    Game();
    ~Game();

    void init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen);

    void handleEvents();
    void update();
    void render();
    void clean();

    inline bool running() { return isRunning; }
};

#endif