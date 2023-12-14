
#ifndef SMALLHOUSE_HPP
#define SMALLHOUSE_HPP

#include "../characters/npc.hpp"
#include <string>
#include "building.hpp"

#define MAX_RESIDENTS_SM 4

class SmallHouse : public Building
{

private:
    /*----------------------------
    @brief max number of npcs assigned to building. Dependent on buliding type.
    ----------------------------*/
    NPC residents[MAX_RESIDENTS_SM];

    void repell_energy(int *arg);

public:
    SmallHouse();

    SmallHouse(std::string name, int posX, int posY);

    virtual ~SmallHouse();

    void assignCharacter(const NPC &character);

    void get_address(); //

    void getInfo();

    void interact(int *arg);
};

#endif