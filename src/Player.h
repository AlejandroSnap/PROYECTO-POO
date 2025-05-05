//
// Created by caren on 4/05/2025.
//

#ifndef PLAYER_H
#define PLAYER_H
#include <tuple>
#include "Personaje.h"
#include "Potion.h"

{
    "Espada":std::vector<Objeto>;
    "aa":3
}

// INVENTARIO
// 1. Espadas
// 2. Armaduras
// 3. Posiones

// x2 Espada de madera


std::vector<Objeto> objeto;

class Player {
private:
    std::vector<Personaje*> heroes;
    std::tuple<std::vector<Potion*>, std::vector<Weapon*>, std::vector<Armour*>> inventory;
    std::vector<int> histDamage; // historial de daño
public:
    Player();
    Player(
        std::vector<Personaje*> heroes,
        std::tuple<std::vector<Potion*>, std::vector<Weapon*>, std::vector<Armour*>> inventory
        );
    // getters
    std::vector<Personaje*> getHeroes();
    std::tuple<std::vector<Potion*>, std::vector<Weapon*>, std::vector<Armour*>> getInventory();
    std::vector<int> getHistDamage();
    //metoditos
    void showHeroes() const;
    void showInventory();
    void curerHeroe();
    void registerDamage(int damage);
    void equipArmour(Armour* armour);
    void equipWeapon(Weapon* weapon); // Falta hacer esta yo del futuro
};



#endif //PLAYER_H
