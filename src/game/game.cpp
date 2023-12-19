#include "../../inc/game/game.hpp"
#include "../../inc/game/textureManager.hpp"
#include "../../inc/game/GameObject.hpp"
#include "../../inc/game/Map.hpp"
#include "../../inc/game/Vector2D.hpp"
#include "../../inc/game/ECS/ECS.hpp"
#include "../../inc/game/ECS/Components.hpp"
#include "../../inc/game/ECS/SpriteComponent.hpp"
#include "../../inc/game/ECS/Collision.hpp"

Map *map;
SDL_Renderer *Game::renderer = nullptr;
Manager manager;
SDL_Event Game::event;

auto &player(manager.addEntity());
auto &wall(manager.addEntity());

Game::Game()
{
}
Game::~Game() {}

void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    int flags = 0;
    count = 0;
    if (fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

        if (window)
        {
            std::cout << " window Created. " << std::endl;
        }

        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer)
        {
            SDL_SetRenderDrawColor(renderer, 255, 128, 128, 255);
            std::cout << " Renderer Created. " << std::endl;
        }
        isRunning = true;
    }
    else
    {
        isRunning = false;
    }
    map = new Map();

    player.addComponent<PositionComponent>();
    player.addComponent<SpriteComponent>("../../assets/texture.png");
    player.addComponent<KeyboardController>();
    player.addComponent<ColliderComponent>("player");
    wall.addComponent<PositionComponent>(300.0f, 300.0f,20, 300,1);
    wall.addComponent<SpriteComponent>("../../assets/dirt.png");
    wall.addComponent<ColliderComponent>("wall");
}

void Game::handleEvents()
{
    SDL_PollEvent(&event);
    switch (event.type)
    {
    case SDL_QUIT:
        isRunning = false;
        break;
    default:
        break;
    }
}

void Game::update()
{
    count++;
    manager.refresh();
    manager.update();

    if(Collision::AABB(player.getComponent<ColliderComponent>().collider,
    wall.getComponent<ColliderComponent>().collider))
    {
        std::cout << "Wall Hit";
    }

    // map->loadMap();
}

void Game::render()
{
    SDL_RenderClear(renderer);
    map->drawMap();
    // add stuff to render here
    manager.draw();
    SDL_RenderPresent(renderer);
}

void Game::clean()
{
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "game cleaned" << std::endl;
}
