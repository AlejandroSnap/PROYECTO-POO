cmake_minimum_required(VERSION 3.30)
project(try1_Proyecto_2_POO)

set(CMAKE_CXX_STANDARD 20)

add_executable(try1_Proyecto_2_POO main.cpp
        src/Personaje.cpp
        src/Personaje.h
        src/Weapon.cpp
        src/Weapon.h
        src/Armour.cpp
        src/Armour.h
        src/Potion.cpp
        src/Potion.h
        src/Player.cpp
        src/Player.h)
