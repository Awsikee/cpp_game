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


auto& tileGrass(manager.addEntity());
auto& tileWater(manager.addEntity());
auto& tileDirt(manager.addEntity());

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

    tileGrass.addComponent<TileComponent>(200,200,DEFAULT_TILE_SIZE,DEFAULT_TILE_SIZE,g);
    tileWater.addComponent<TileComponent>(250,250,DEFAULT_TILE_SIZE,DEFAULT_TILE_SIZE,w);
    tileDirt.addComponent<TileComponent>(150,150,DEFAULT_TILE_SIZE,DEFAULT_TILE_SIZE,d);
    tileWater.addComponent<ColliderComponent>("water");
    tileGrass.addGroup(groupMap);
    tileWater.addGroup(groupMap);
    tileDirt.addGroup(groupMap);

    player.addComponent<PositionComponent>(0,0,400,704,0.25f);
    player.addComponent<SpriteComponent>("../../assets/full_spritesheet.png",true);
    player.addComponent<KeyboardController>();
    player.addComponent<ColliderComponent>("player");
    player.addGroup(groupNPCs);
    
    building.addComponent<PositionComponent>(tilePosition(2.0f), tilePosition(2.0f), DEFAULT_TILE_SIZE, 2*DEFAULT_TILE_SIZE , 1);
    building.addComponent<SpriteComponent>("../../assets/brick.png");
    building.addComponent<ColliderComponent>("building");
    building.addGroup(groupEntities);
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
    tileWater.getComponent<ColliderComponent>().collider))
    {
        player.getComponent<PositionComponent>().velocity* -1;
        std::cout << "Wall Hit";
    }

    // map->loadMap();
}

auto& tiles(manager.getGroup(groupMap));
auto& players(manager.getGroup(groupNPCs));
auto& entities(manager.getGroup(groupEntities));


void Game::render()
{
    SDL_RenderClear(renderer);
    map->drawMap();
    // add stuff to render here
    for(auto& t : tiles)
    {
        t->draw();
    }
    for(auto& p : players)
    {
        p->draw();
    }
    for(auto& e : entities)
    {
        e->draw();
    }
    SDL_RenderPresent(renderer);
}

void Game::clean()
{
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "game cleaned" << std::endl;
}
