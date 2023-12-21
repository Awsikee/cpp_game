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

std::vector<ColliderComponent*> Game::colliders;

auto &player(manager.addEntity());
auto &wall(manager.addEntity());
auto &building(manager.addEntity());


auto& tile0(manager.addEntity());
auto& tile1(manager.addEntity());
auto& tile2(manager.addEntity());

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

    tile0.addComponent<TileComponent>(200,200,32,32,0);
    tile1.addComponent<TileComponent>(250,250,32,32,1);
    tile2.addComponent<TileComponent>(150,150,32,32,3);
    tile1.addComponent<ColliderComponent>("water");

    player.addComponent<PositionComponent>();
    player.addComponent<SpriteComponent>("../../assets/texture.png");
    player.addComponent<KeyboardController>();
    player.addComponent<ColliderComponent>("player");
    wall.addComponent<PositionComponent>(300.0f, 300.0f, 20, 300, 1);
    wall.addComponent<SpriteComponent>("../../assets/dirt.png");
    wall.addComponent<ColliderComponent>("wall");
    building.addComponent<PositionComponent>(250.0f, 300.0f, 100, 200 , 1);
    building.addComponent<SpriteComponent>("../../assets/brick.png");
    building.addComponent<ColliderComponent>("building");
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
        player.getComponent<PositionComponent>().velocity* -1;
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
