//
// Created by caren on 4/05/2025.
//

#include "Player.h"
#include <iostream>

Player::Player(
        std::vector<Personaje*> heroes,
        std::tuple<std::vector<Potion*>, std::vector<Weapon*>, std::vector<Armour*>> inventory
        ) {
    this->heroes = heroes;
    this->inventory = inventory;
    histDamage = {};

}
//getters
std::vector<Personaje*> Player::getHeroes() {
    return this->heroes;
}
std::tuple<std::vector<Potion*>, std::vector<Weapon*>, std::vector<Armour*>>  Player::getInventory() {
    return this-> inventory;
}
std::vector<int> Player::getHistDamage() {
    return histDamage;
}

//Metodos REEEEEEEEEE CONTRA CHIMBOS
void Player::showHeroes() const {
    for (int i = 0; i < heroes.size(); i++) {
        heroes[i]->showStats();
    }
}
void Player::showInventory() {
    std::cout << "INVENTARIO: " << std::endl;
    for (int a = 0; a < std::get<0>(inventory).size(); a++) {
        std::cout << "Pocion: " << std::get<0>(inventory)[a]->getName() << "| ps: " << std::get<0>(inventory)[a]->getCure() << std::endl;
    }
    for (int e = 0; e < std::get<1>(inventory).size(); e++) {
        std::cout << "Arma: " << std::get<1>(inventory)[e]->getName() << " | damage: " << std::get<1>(inventory)[e]->getDamage() << " | bleed: " << std::get<1>(inventory)[e]->getBleed() << std::endl;
    }
    for (int i = 0; i < std::get<2>(inventory).size(); i++) {
        std::cout << "Armadura: " << std::get<2>(inventory)[i]->getName() << "| Proteccion: " << std::get<2>(inventory)[i]->getDefUp() << std::endl;
    }
}
void Player::curerHeroe() {
    if (!std::get<0>(inventory).empty()) {
        // sacar el indice de la pocion
        std::cout << "Seleccione una pocion: " << std::endl;
        for (int a = 0; a < std::get<0>(inventory).size(); a++) {
            std::cout << "Pocion: " << std::get<0>(inventory)[a]->getName() << "| ps: " << std::get<0>(inventory)[a]->getCure() << std::endl;
        }
        std::cout << "Seleccione una pocion por indice: " << std::endl;
        int spbi; //selected potion by index
        std::cin >> spbi;
        while (spbi-1 < 0 || spbi-1 > heroes.size()) {
            std::cout << "Indice fuera de rango :(, por favor seleccione un numero entre 1 y " << heroes.size() << std::endl;
            std::cin >> spbi;
        }

        // Sacar el indice del heroe
        std::cout << "Heroes: " << std::endl;
        for (int i = 0; i < heroes.size(); i++) {
            std::cout << i+1 << ") ";
            heroes[i]->showStats();
            std::cout << "\n";
        }
        std::cout << "Seleccione el heroe a curar heroe por indice: " << std::endl;
        int shbi; //selected hero by index
        std::cin >> shbi;
        while (shbi-1 < 0 || shbi-1 > heroes.size()) {
            std::cout << "Indice fuera de rango :(, por favor seleccione un numero entre 1 y " << heroes.size() << std::endl;
            std::cin >> shbi;
        }
        if (heroes[shbi]->getHpif() > 0) {
            if (heroes[shbi]->getHpif() + std::get<0>(inventory)[spbi]->getCure() < heroes[shbi]->getHp()) {
                std::cout << heroes[shbi]->getName() << " ha restaurado " << std::get<0>(inventory)[spbi]->getCure() << "hp." << std::endl;
            }
            else {
                std::cout << heroes[shbi]->getName() << " ha restaurado " << heroes[shbi]->getHp() - heroes[shbi]->getHpif() << "hp." << std::endl;
            }
            heroes[shbi]->cure(std::get<0>(inventory)[spbi]->getCure());
        }
        else {
            std::cout << "Lo sentimos pero parece ser que " << heroes[shbi]->getName() << " ESTA MUERTO." << std::endl;
        }
    }
    else {
        std::cout << "Mi bro, nos quedamos sin potis :(" << std::endl;
    }
} // hay que mejorar esta, tal vez tenga que mandarla a otra clase superiro como Pelea o algo asi
void Player::registerDamage(int damage) {
    histDamage.push_back(damage);
}
void Player::equipArmour(Armour* armour) {
    if (!std::get<2>(inventory).empty()) {
        std::cout << "Armaduras: " << std::endl;
        for (int i = 0; i < std::get<2>(inventory).size(); i++) {
            std::cout << "Armadura: " << std::get<2>(inventory)[i]->getName() << "| Proteccion: " << std::get<2>(inventory)[i]->getDefUp() << std::endl;
        }
        std::cout << "Seleccione el indice de la armadura que desea equipar: " << std::endl;
        int iate; //index armour to equip
        std::cin >> iate;
        while (iate < 0 || iate > std::get<2>(inventory).size()) {
            std::cout << "Indice fuera de rango :(, por favor seleccione un numero entre 1 y " << std::get<2>(inventory).size() << std::endl;
            std::cin >> iate;
        }
        std::cout << "\nHeroes: " << std::endl;
        showHeroes();
        std::cout << "Seleccione el indice del heroe a equipar la armadura: " << std::endl;
        int ihea; //index hero to equip armoour
        std::cin >> ihea;
        while (ihea-1 < 0 || ihea-1 > heroes.size()) {
            std::cout << "Indice fuera de rango :(, por favor seleccione un numero entre 1 y " << heroes.size() << std::endl;
            std::cin >> ihea;
        }
        heroes[ihea]->equipArmour(std::get<2>(inventory)[iate]);
    }
    else {
        std::cout << "Lamento tener que decirte que no tenes ni una sola armadura." << std::endl;
    }
}
