//
// Created by caren on 1/05/2025.
//

#ifndef PERSONAJE_H
#define PERSONAJE_H
#include <string>
#include <vector>
#include "Armour.h"
#include "Weapon.h"

class Personaje {
protected:
    std::string name;
    int level;
    int xp;
    int hp; //estadistica bace de vida
    int hpif; // health points in figth
    int atk;
    int def;
    int spd;
    int lck;
    Weapon* weapon;
    Armour* armour;

public:
    Personaje();
    Personaje(std::string n, int l, int x, int h, int at, int d, int vl, int s,
        int lc, Weapon* w, Armour* a);

    //getters
    std::string getName() const;
    int getLevel() const;
    int getHp() const;
    int getAtk() const;
    int getDef() const;
    int getSpd() const;
    int getLck() const;
    Weapon getWeapon() const;
    Armour getArmour() const;
    int getHpif() const;
    //Metodos Re chimbos
    void zenkai (); //Aumento de estadisticas tras batalla
    void showStats();
    void levelUp (int xpEarned);
    void equipWeapon(Weapon* newWeapon);
    void equipArmour(Armour* newArmour);
    void showArmour();
    void showWeapon();
    void cure(int psp);
};



#endif //PERSONAJE_H
