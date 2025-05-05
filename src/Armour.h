//
// Created by caren on 1/05/2025.
//

#ifndef ARMOUR_H
#define ARMOUR_H
#include <string>


class Armour {
private:
    std::string name;
    int defUp;

public:
    Armour();
    Armour(std::string name, int defUp);
    //getters
    std::string getName();
    int getDefUp();
};



#endif //ARMOUR_H
