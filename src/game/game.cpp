#include "../../inc/game/game.hpp"
#include "../../inc/game/textureManager.hpp"
#include "../../inc/game/GameObject.hpp"
#include "../../inc/game/Map.hpp"
#include "../../inc/game/Vector2D.hpp"
#include "../../inc/game/ECS/ECS.hpp"
#include "../../inc/game/ECS/Components.hpp"
#include "../../inc/game/ECS/SpriteComponent.hpp"
#include "../../inc/game/ECS/Collision.hpp"

Map *mapObj;

SDL_Renderer *Game::renderer = nullptr;
Manager manager;
SDL_Event Game::event;
SDL_Rect Game::camera = {0, 0, 800, 640};

std::vector<ColliderComponent *> Game::colliders;

vector<Vector2D> path;

bool Game::isRunning = false;

auto &cameraEntity(manager.addEntity());

auto &player(manager.addEntity());
auto &wall(manager.addEntity());
auto &building(manager.addEntity());

Game::Game()
{
}
Game::~Game() {}

void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    int flags = 0;
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
    mapObj = new Map("../../assets/map.png");
    mapObj->loadMap("../../assets/map.map", MAP_X_DIM, MAP_Y_DIM);

    
    cameraEntity.addComponent<PositionComponent>(GAMEWINDOW_X_SIZE/2, GAMEWINDOW_Y_SIZE/2, 3);
    //cameraEntity.addComponent<SpriteComponent>("../../assets/full_spritesheet.png", true);
    cameraEntity.addComponent<KeyboardController>();
    cameraEntity.addComponent<ColliderComponent>("camera", GAMEWINDOW_X_SIZE/2, GAMEWINDOW_Y_SIZE/2, 1, 1);
    //cameraEntity.addComponent<ArtificialMovement>();
    cameraEntity.addGroup(groupNPCs);

    player.addComponent<PositionComponent>(0, 0, 256, 256, 0.5 * GAMESCALE);
    player.addComponent<SpriteComponent>("../../assets/full_spritesheet.png", true);
    //player.addComponent<KeyboardController>();
    player.addComponent<ColliderComponent>("player", 0, 0, 48, 48);
    player.addComponent<ArtificialMovement>();
    player.addGroup(groupNPCs);


    path = player.getComponent<ArtificialMovement>().findPath({0,0},{14,6});
    
    
    // Print the path

    // std::cout << "Path: ";
    // for (const auto &point : path)
    // {
    //     cout << "(" << point.x << ", " << point.y << ") ";
    // }
    // std::cout << std::endl;

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

auto &tiles(manager.getGroup(groupMap));
auto &colliders(manager.getGroup(groupColliders));
auto &players(manager.getGroup(groupNPCs));
auto &entities(manager.getGroup(groupEntities));

void Game::update()
{
    SDL_Rect cameraEntityCol = cameraEntity.getComponent<ColliderComponent>().collider;
    Vector2D cameraEntityPos = cameraEntity.getComponent<PositionComponent>().position;
    manager.refresh();
    manager.update();

// since the movement is defined by A* algorithm this functionality may be removed

    for (auto &c : colliders)
    {
        SDL_Rect cCol = c->collider;
        ;
        if (c->tag != cameraEntity.getComponent<ColliderComponent>().tag)
        {
            CollisionDirection collidingDirection = Collision::collisionByBoundaries(cameraEntityCol, camera.w/2, TILE_SIZE_SCALED*MAP_X_DIM - camera.w/2, camera.h/2, TILE_SIZE_SCALED*MAP_Y_DIM - camera.h/2);
            if (collidingDirection != CollisionDirection::NONE)
            {
                switch (collidingDirection)
                {
                case CollisionDirection::UP:
                    if (cameraEntity.getComponent<PositionComponent>().velocity.y < 0) // Only stop upward movement if cameraEntity is moving upwards
                    {
                        cameraEntity.getComponent<PositionComponent>().velocity.y += 1;
                    }
                    break;
            
                case CollisionDirection::DOWN:
                    if (cameraEntity.getComponent<PositionComponent>().velocity.y > 0) // Only stop downward movement if cameraEntity is moving downwards
                    {
                        cameraEntity.getComponent<PositionComponent>().velocity.y -= 1;
                    }
                    break;
            
                case CollisionDirection::LEFT:
                    if (cameraEntity.getComponent<PositionComponent>().velocity.x < 0) // Only stop leftward movement if cameraEntity is moving leftwards
                    {
                        cameraEntity.getComponent<PositionComponent>().velocity.x += 1;
                    }
                    break;
            
                case CollisionDirection::RIGHT:
                    if (cameraEntity.getComponent<PositionComponent>().velocity.x > 0) // Only stop rightward movement if cameraEntity is moving rightwards
                    {
                        cameraEntity.getComponent<PositionComponent>().velocity.x -= 1;
                    }
                    break;
            
                case CollisionDirection::UP_LEFT:
                    if (cameraEntity.getComponent<PositionComponent>().velocity.x < 0)
                    {
                        cameraEntity.getComponent<PositionComponent>().velocity.x += 1;

                    } 
                    if(cameraEntity.getComponent<PositionComponent>().velocity.y < 0)
                    {
                        cameraEntity.getComponent<PositionComponent>().velocity.y += 1;
                    }
                    break;
            
                case CollisionDirection::UP_RIGHT:
                    if (cameraEntity.getComponent<PositionComponent>().velocity.x > 0)
                    {
                        cameraEntity.getComponent<PositionComponent>().velocity.x -= 1;
                    }
                    else if(cameraEntity.getComponent<PositionComponent>().velocity.y < 0)
                    {
                        cameraEntity.getComponent<PositionComponent>().velocity.y += 1;
                    }
                    break;
            
                case CollisionDirection::DOWN_LEFT:
                    if (cameraEntity.getComponent<PositionComponent>().velocity.x < 0) 
                    {
                        cameraEntity.getComponent<PositionComponent>().velocity.x += 1;
                    }
                    else if(cameraEntity.getComponent<PositionComponent>().velocity.y > 0)
                    {
                        cameraEntity.getComponent<PositionComponent>().velocity.y -= 1;
                    }
                    break;
            
                case CollisionDirection::DOWN_RIGHT:
                    if (cameraEntity.getComponent<PositionComponent>().velocity.x > 0) 
                    {
                        cameraEntity.getComponent<PositionComponent>().velocity.x -= 1;
                    }
                    else if( cameraEntity.getComponent<PositionComponent>().velocity.y > 0)
                    {
                        cameraEntity.getComponent<PositionComponent>().velocity.y -= 1;
                    }
                    break;
            
                default:
                    break;
                }
            }
            
            
        }
    }


//camera movement boundaries should be restricted
    PositionComponent &cameraEntityPosition = cameraEntity.getComponent<PositionComponent>();
    camera.x = cameraEntityPosition.position.x - (GAMEWINDOW_X_SIZE / 2);
    camera.y = cameraEntityPosition.position.y - (GAMEWINDOW_Y_SIZE / 2);

    // Calculate the maximum camera x and y position
    const int maxCameraX = static_cast<int>(MAP_X_DIM * TILE_SIZE_SCALED - camera.w);
    const int maxCameraY = static_cast<int>(MAP_Y_DIM * TILE_SIZE_SCALED - camera.h);

    //camera movement boundaries should be restricted
    // Clamp the camera position within the valid range
    camera.x = std::max(camera.x, 0);
    camera.y = std::max(camera.y, 0);
    camera.x = std::min(camera.x, maxCameraX);
    camera.y = std::min(camera.y, maxCameraY);
}

void Game::render()
{
    SDL_RenderClear(renderer);
    // add stuff to render here
    for (auto &t : tiles)
    {
        t->draw();
    }
    for (auto &c : colliders)
    {
        c->draw();
    }
    for (auto &p : players)
    {
        p->draw();
    }
    SDL_RenderPresent(renderer);
}

void Game::clean()
{
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "game cleaned" << std::endl;
}
