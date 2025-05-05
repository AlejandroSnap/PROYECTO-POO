//
// Created by caren on 1/05/2025.
//

#include "Armour.h"

Armour::Armour(std::string name, int defUp) {
    this->name = name;
    this->defUp = defUp;
}
//getters
std::string Armour::getName() {
    return this->name;
}
int Armour::getDefUp() {
    return this->defUp;
}
