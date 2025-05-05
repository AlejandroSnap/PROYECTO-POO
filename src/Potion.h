//
// Created by caren on 1/05/2025.
//

#ifndef POTION_H
#define POTION_H
#include <string>


class Potion {
private:
    std::string name;
    int cure;
public:
    Potion();
    Potion(std::string name, int cure);
    //getters
    std::string getName();
    int getCure();
};



#endif //POTION_H
