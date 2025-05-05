//
// Created by caren on 1/05/2025.
//
#include "Personaje.h"
#include <cmath>
#include <iostream>

Personaje::Personaje(std::string n, int l, int x, int h, int at, int d, int vl, int s,
        int lc, Weapon* w, Armour* a) {
    name = n;
    level = l;
    xp = x;
    hp = h;
    atk = at;
    def = d;
    spd = vl;
    lck = lc;
    weapon = w;
    armour = a;
    hpif = hp;
}
//getters
std::string Personaje::getName() const {
    return name;
}
int Personaje::getLevel() const {
    return level;
}
int Personaje::getHp() const {
    return hp;
}
int Personaje::getAtk() const {
    return atk;
}
int Personaje::getDef() const {
    return def;
}
int Personaje::getSpd() const {
    return spd;
}
int Personaje::getLck() const {
    return lck;
}
Weapon Personaje::getWeapon() const {
    return *weapon;
}
Armour Personaje::getArmour() const {
    return *armour;
}
int Personaje::getHpif() const {
    return hpif;
}

//Metodos REEEEEEEE CHIMBOS
void Personaje::zenkai() {
    // Admito que la parte del redondeo si fue con IA xD
    atk += static_cast<int>(round(0.02*atk));
    def += static_cast<int>(round(0.02*def));
}
void Personaje::showStats() {
    std::cout << "Stadisticas de: " << name << std::endl;
    std::cout << "1) Nivel: " << level << std::endl;
    std::cout << "2) Vida: " << hp << std::endl;
    std::cout << "3) Ataque: " << atk << std::endl;
    std::cout << "4) Defensa: " << def << std::endl;
    std::cout << "5) Velocidad: " << spd << std::endl;
    std::cout << "6) Suerte: " << lck << std::endl;
}
void Personaje::levelUp(int xpEarned) {
    xp += xpEarned;
    while (xp >= 100) {
        level++;
        std::cout << "Tu personaje " << name << " ha subido a nivel " << level << std::endl;
        showStats();
        bool estadisticaValida = false;
        while (!estadisticaValida) { // Sigue preguntando hasta obtener una entrada válida
            std::cout << "Ingrese el número de la estadística a subir (1-6): ";
            int ieas;
            std::cin >> ieas;

            if (ieas >= 1 && ieas <= 6) {
                switch (ieas) {
                    case 1: level += 1; break;
                    case 2: hp += 1; break;
                    case 3: atk += 1; break;
                    case 4: def += 1; break;
                    case 5: spd += 1; break;
                    case 6: lck += 1; break;
                }
                estadisticaValida = true; // Sale del bucle solo si la entrada es válida
            } else {
                std::cout << "Opción inválida. Por favor, ingrese un número entre 1 y 6." << std::endl;
            }
        }
        xp -= 100;
    }
}
void Personaje::showArmour() {
    std::cout << "Armadura: " << armour->getName()<< ": " << armour->getDefUp() << std::endl;
}
void Personaje::showWeapon() {
    std::cout << "Arma: " << weapon->getName() << std::endl;
    std::cout << "Ataque: " << weapon->getDamage() << std::endl;
    std::cout << "sangrado: " << weapon->getBleed() << std::endl;
}
void Personaje::equipWeapon(Weapon* newWeapon) {
    if (weapon) {
        delete weapon;
    }
    weapon = newWeapon;
}
void Personaje::equipArmour(Armour* newArmour) {
    if (armour) {
        delete armour;
    }
    armour = newArmour;
}
void Personaje::cure(int psp) {
    hpif += psp;
    if (hpif > hp) {
        hpif = hp;
    }
}

