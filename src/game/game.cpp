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

bool Game::isRunning = false;

auto &player(manager.addEntity());
auto &wall(manager.addEntity());
auto &building(manager.addEntity());

const char* mapfile = "../../assets/map.png";

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
    Map::loadMap("../../assets/map.map",16,16);


    player.addComponent<PositionComponent>(GAMEWINDOW_X_SIZE/2,GAMEWINDOW_Y_SIZE/2,400,704,0.25f *GAMESCALE);
    player.addComponent<SpriteComponent>("../../assets/full_spritesheet.png",true);
    player.addComponent<KeyboardController>();
    player.addComponent<ColliderComponent>("player");
    player.addGroup(groupNPCs);
    
    // building.addComponent<PositionComponent>(tilePosition(2.0f), tilePosition(2.0f), DEFAULT_TILE_SIZE, 2*DEFAULT_TILE_SIZE , 1);
    // building.addComponent<SpriteComponent>("../../assets/brick.png");
    // building.addComponent<ColliderComponent>("building");
    // building.addGroup(groupEntities);
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

auto& tiles(manager.getGroup(groupMap));
auto& players(manager.getGroup(groupNPCs));
auto& entities(manager.getGroup(groupEntities));


void Game::update()
{
    count++;
    manager.refresh();
    manager.update();

    Vector2D pVel =  player.getComponent<PositionComponent>().velocity;
    int pSpeed = player.getComponent<PositionComponent>().speed;
    //std::cout<< pVel << std::endl;
    for(auto t : tiles)
    {
        t->getComponent<TileComponent>().destRect.x += -(pVel.x * pSpeed);
        t->getComponent<TileComponent>().destRect.y += -(pVel.y * pSpeed);

    }

    // if(Collision::AABB(player.getComponent<ColliderComponent>().collider,
    // tileWater.getComponent<ColliderComponent>().collider))
    // {
    //     player.getComponent<PositionComponent>().velocity* -1;
    //     std::cout << "Wall Hit";
    // }

    // map->loadMap();
}

void Game::render()
{
    SDL_RenderClear(renderer);
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

void Game::addTile(int srcX, int srcY, int xpos, int ypos)
{
  auto& tile(manager.addEntity());
  tile.addComponent<TileComponent>(srcX,srcY,xpos, ypos, mapfile);
//   if(id == 1)
//   {
//     tile.addComponent<ColliderComponent>("water");
//   }
  tile.addGroup(groupMap);
}
