#ifndef ARTIFICIALMOVEMENT_HPP
#define ARTIFICIALMOVEMENT_HPP

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

#include "../../inc/game/Map.hpp"
#include "../../inc/game/game.hpp"
#include "../../inc/game/ECS/Components.hpp"
#include <fstream>
#include <sstream>

extern Manager manager;

using namespace std;

struct Node
{
    int x, y; // Coordinates of the node
    int g;    // Cost from start to current node
    int h;    // Heuristic (Manhattan distance to goal)
    int f;    // f = g + h
    Node *parent;

    Node(int x, int y, int g, int h) : x(x), y(y), g(g), h(h), f(g + h), parent(nullptr) {}

    // Overloading comparison operator for priority queue
    bool operator>(const Node &other) const
    {
        return f > other.f;
    }
    bool operator==(const Node &other) const
    {
        return x == other.x && y == other.y;
    }
};
class ArtificialMovement : public Component
{

private:
    std::vector<std::vector<int>> collisionGrid;

    std::vector<Vector2D> path;

    static std::vector<std::vector<int>> readGridFromFile()
    {
        std::ifstream file("../../assets/collisionMap.map");
        std::vector<std::vector<int>> grid;

        if (file.is_open())
        {
            std::string line;

            while (std::getline(file, line))
            {
                std::vector<int> row;

                std::stringstream ss(line);
                std::string numberStr;

                // Read each number in the line and add it to the row vector
                while (std::getline(ss, numberStr, ','))
                {
                    int number = std::stoi(numberStr);
                    row.push_back(number);
                }

                // Add the row to the grid vector
                grid.push_back(row);
            }

            file.close();
        }

        return grid;
    }

    Vector2D calculateXY(Vector2D position)
    {
        position.x = (position.x + 1) * TILE_SIZE_SCALED;
        position.y = (position.y + 1) * TILE_SIZE_SCALED;

        return position;
    }

public:
    PositionComponent *transform;
    SpriteComponent *sprite;
    void init() override
    {
        transform = &entity->getComponent<PositionComponent>();
        sprite = &entity->getComponent<SpriteComponent>();
        collisionGrid = readGridFromFile();
    }


    void update() override
    {
        if (!path.empty())
        {
            Vector2D coordinates = path.front();
            if (transform->position.x == coordinates.x && transform->position.y == coordinates.y)
            {
                transform->velocity = {0, 0};
                path.erase(path.begin());
                return;
            }

            if (coordinates.x < transform->position.x)
            {
                transform->velocity.x = -1;
                sprite->play("walk_left");
            }
            else if (coordinates.x > transform->position.x)
            {
                transform->velocity.x = 1;
                sprite->play("walk_right");
            }
            else
            {
                transform->velocity.x = 0;
            }

            if (coordinates.y < transform->position.y)
            {
                transform->velocity.y = -1;
                sprite->play("walk_back");
            }
            else if (coordinates.y > transform->position.y)
            {
                transform->velocity.y = 1;
                sprite->play("walk_front");
            }
            else
            {
                transform->velocity.y = 0;
            }
        }
    }

    ArtificialMovement() {}
    ~ArtificialMovement() {}

    bool isValid(int x, int y, int rows, int cols)
    {
        return (x >= 0 && x < rows && y >= 0 && y < cols);
    }

    bool isVisited(const std::vector<Node *> &Set, const Node *neighbor)
    {
        for (auto node : Set)
        {
            if (*neighbor == *node)
            {
                return true;
            }
        }
        return false;
    }

    Node *getNodeWithLowestF(std::vector<Node *> &nodes)
    {
        if (nodes.empty())
        {
            return nullptr; // Return nullptr if the vector is empty
        }

        auto minElement = std::min_element(nodes.begin(), nodes.end(),
                                           [](const Node *a, const Node *b)
                                           {
                                               return a->f < b->f;
                                           });

        Node *nodeWithLowestF = *minElement;
        nodes.erase(minElement);
        return nodeWithLowestF;
    }

    std::vector<Vector2D> findPath(Vector2D start, Vector2D goal)
    {
        int rows = collisionGrid.size();
        int cols = collisionGrid[0].size();

        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};

        std::vector<Node *> openSet;
        std::vector<Node *> closedSet;

        Node *startNode = new Node(start.x, start.y, 0, abs(start.x - goal.x) + abs(start.y - goal.y));

        openSet.push_back(startNode);

        int steps = 0;
        while (!openSet.empty())
        {
            steps++;

            Node *current = getNodeWithLowestF(openSet);

            closedSet.push_back(current);

            if (current->x == goal.x && current->y == goal.y)
            {

                while (!closedSet.empty())
                {
                    if ((current->x == start.x) && (current->y == start.y))
                    {
                        break;
                    }
                    path.push_back({(current->x * TILE_SIZE_SCALED), (current->y * TILE_SIZE_SCALED)});
                    current = current->parent;
                }
                std::reverse(path.begin(), path.end());
                return path;
            }

            // Explore neighbors
            for (int i = 0; i < 4; ++i)
            {

                int newX = current->x + dx[i];
                int newY = current->y + dy[i];

                if (!isValid(newX, newY, rows, cols))
                {
                    continue;
                }
                if (collisionGrid[newY][newX] == 1)
                {
                    continue;
                }

                int newG = current->g + 1;
                int newH = abs(newX - goal.x) + abs(newY - goal.y);
                Node *neighbor = new Node(newX, newY, newG, newH);

                neighbor->parent = current;

                if (!isVisited(openSet, neighbor) && !isVisited(closedSet, neighbor))
                {
                    openSet.push_back(neighbor);
                }
            }
        }

        // If the open set is empty and goal is not reached, return an empty path
        return {};
    }
};

#endif