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
    Node* parent;

    Node(int x, int y, int g, int h) : x(x), y(y), g(g), h(h), f(g + h), parent(nullptr) {}

    // Overloading comparison operator for priority queue
    bool operator>(const Node &other) const
    {
        return f > other.f;
    }
};
class ArtificialMovement : public Component
{

private:
    std::vector<std::vector<int>> collisionGrid;
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
    void init() override
    {
        collisionGrid = readGridFromFile();
    }

    void update() override
    {
    }

    ArtificialMovement() {}
    ~ArtificialMovement() {}

bool isValid(int x, int y, int rows, int cols) {
    return (x >= 0 && x < rows && y >= 0 && y < cols);
}

std::vector<Vector2D> findPath(Vector2D start, Vector2D goal) {
    int rows = collisionGrid.size();
    int cols = collisionGrid[0].size();

    // Define possible movement directions (4-way movement)
    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};

    // Priority queue for open nodes
    std::priority_queue<Node, std::vector<Node>, std::greater<Node>> openSet;
    std::vector<Node> closedSet;

    // Matrix to keep track of visited nodes
    std::vector<std::vector<bool>> visited(rows, std::vector<bool>(cols, false));

    // Start node
    Node startNode(start.x, start.y, 0, abs(start.x - goal.x) + abs(start.y - goal.y));
    openSet.push(startNode);
    closedSet.push_back(startNode);
    // Main A* loop
    while (!openSet.empty()) {
        // Get the node with the lowest f value
        Node current = openSet.top();
        if(closedSet.back().h > current.h)
        {
            closedSet.push_back(current);
        }
        openSet.pop();

        // Mark current node as visited
        visited[current.x][current.y] = true;

        // Check if the goal is reached
        if (current.x == goal.x && current.y == goal.y) {
            // Reconstruct the path
            std::vector<Vector2D> path;
            
            while (!closedSet.empty()) {
                current = closedSet.front();
                path.push_back({current.x, current.y});
                closedSet.erase(closedSet.begin());
                
            }
            //path.push_back({start.x, start.y}); // Add the start node to the path
            //std::reverse(path.begin(), path.end());
            return path;
        }

        // Explore neighbors
        for (int i = 0; i < 4; ++i) {
            int newX = current.x + dx[i];
            int newY = current.y + dy[i];

            // Check if the neighbor is valid and not visited
            if (isValid(newX, newY, rows, cols) && !visited[newX][newY] && collisionGrid[newY][newX] == 0) {
                int newG = current.g + 1;
                int newH = abs(newX - goal.x) + abs(newY - goal.y);
                Node neighbor(newX, newY, newG, newH);
                neighbor.parent = new Node(current.x, current.y, 0, 0); // Directly create a new node instead of dynamically allocating
                // Check if the neighbor is not in the open set or has a lower f value
                if (!visited[newX][newY]) {
                    openSet.push(neighbor);
                    visited[newX][newY] = true;
                }
            }
        }
    }

    // If the open set is empty and goal is not reached, return an empty path
    return {};
}

};

// int main()
// {
//     // Example usage

//     auto &grid = manager.getGroup(groupMap);

//     vector<vector<int>> grid = readGridFromFile();

//     Vector2D start = {0, 0};
//     Vector2D goal = {4, 4};

//     vector<Vector2D> path = findPath(grid, start, goal);

//     // Print the path
//     cout << "Path: ";
//     for (const auto &point : path)
//     {
//         cout << "(" << point.x << ", " << point.y << ") ";
//     }
//     cout << endl;

//     return 0;
// }
