//
// Created by caren on 1/05/2025.
//

#include "Weapon.h"
Weapon::Weapon(std::string name, int damage, int bleed) {
    this->name = name;
    this->damage = damage;
    this->bleed = bleed;
}
std::string Weapon::getName() {
    return this -> name;
}
int Weapon::getDamage() {
    return this -> damage;
}
int Weapon::getBleed() {
    return this -> bleed;
}