#define SDL_MAIN_HANDLED
#include <iostream>

#include "inc/dataDefinition.hpp"
#include "inc/characters/villager.hpp"
#include "inc/buildings/smallHouse.hpp"
#include "inc/characters/NPC.hpp"
#include "inc/game/game.hpp"

Game *game = nullptr;

int main()
{
    constexpr int FPS = 60;
    constexpr int frameDelay = 1000/FPS;

    Uint32 frameStart;
    int frameTime;
    SDL_SetMainReady();

    game = new Game();

    game->init("test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, GAMEWINDOW_X_SIZE, GAMEWINDOW_Y_SIZE, false);


    while(game->running())
    {
        frameStart = SDL_GetTicks();

        game->handleEvents();
        game->update();
        game->render();

        frameTime = SDL_GetTicks() - frameStart;

        if(frameDelay> frameTime)
        {
            SDL_Delay(frameDelay - frameTime);
        }

    }

    game->clean();
    //Villager villager;
    //villager.
    return 0;
}