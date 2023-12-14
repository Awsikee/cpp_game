
#ifndef SMALLHOUSE_HPP
#define SMALLHOUSE_HPP

#include "../characters/npc.hpp"
#include <string>
#include "building.hpp"

#define MAX_RESIDENTS_SM 4

class SmallHouse : public Building{ 


    private:
        /*----------------------------
        @brief max number of npcs assigned to building. Dependent on buliding type.
        ----------------------------*/
        NPC residents[MAX_RESIDENTS_SM];

        void repell_energy(int *arg)
        {
            *arg = 100;
        }

    public:
 
        SmallHouse()
        {


        }
        SmallHouse(std::string name, int posX, int posY): Building(name, posX, posY)
        {

            for (size_t i = 0; i < MAX_RESIDENTS_SM; ++i) {
                residents[i].name = "DefaultNPC" + std::to_string(i + 1);
        }

        }
        void assignCharacter(const NPC &character) {
            // Check if there's space in the residents array
            if (sizeof(residents) / sizeof(residents[0]) > 0) {
                this->residents[0] = character;
            } else {
                std::cerr << "Cannot assign more characters to SmallHouse. Residents array is full." << std::endl;
            }
        }
        void get_address(); //

        void getInfo() {
            
            std::cout << this->buildingName << " has resident named " << this->residents[0].name << "." << std::endl;
        }

        void interact(int *arg)
        {
            //std::cout << " Interacted with"<< buildingName << std::endl;
            repell_energy(arg);
        }

};

#endif