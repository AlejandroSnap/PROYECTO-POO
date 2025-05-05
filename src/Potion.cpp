//
// Created by caren on 1/05/2025.
//

#include "Potion.h"

Potion::Potion(std::string name, int cure) {
    this->name = name;
    this->cure = cure;
}
std::string Potion::getName() {
    return this->name;
}
int Potion::getCure() {
    return this->cure;
}

