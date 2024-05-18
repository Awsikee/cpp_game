
#ifndef GAMECLASS_HPP
#define GAMECLASS_HPP

#include "../SDL2-2.30.1/include/SDL.h"
#include "../SDL2_image-2.8.2/include/SDL_image.h"
#include "../../inc/dataDefinition.hpp"

#include <iostream>
#include <vector>

class ColliderComponent;
class Game
{
private:
    SDL_Window *window;
    int count;

public:
    static bool isRunning;


    static SDL_Renderer *renderer;
    static SDL_Event event;
    static std::vector<ColliderComponent*> colliders;
    static SDL_Rect camera;

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