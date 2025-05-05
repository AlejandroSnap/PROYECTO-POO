//
// Created by caren on 1/05/2025.
//

#ifndef WEAPON_H
#define WEAPON_H
#include <string>


class Weapon {
private:
    std::string name;
    int damage;
    int bleed;

public:
    Weapon();
    Weapon(std::string name, int damage, int bleed);
    //getters
    std::string getName();
    int getDamage();
    int getBleed();
};



#endif //WEAPON_H
