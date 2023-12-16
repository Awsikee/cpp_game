
#ifndef GAMECLASS_HPP
#define GAMECLASS_HPP

#include "../inc/include/SDL2/SDL.h"
#include <iostream>
class Game
{
    private:
        bool isRunning;
        SDL_Window *window;
        SDL_Renderer *renderer;
        int count;
    
    public:
        Game();
        ~Game();

        void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

        void handleEvents();
        void update();
        void render();
        void clean();

        inline bool running(){return isRunning;}




};

#endif