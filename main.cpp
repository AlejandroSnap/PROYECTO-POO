#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <string>
//#include "src/Personaje.h"
//#include "src/Personaje.h""
//#include "src/Player.h"
using namespace std;

struct Objeto {
    string name;
    string category;
    int stack;
};

void agregar_objeto(vector<Objeto> &objetos, Objeto &objeto) {
    bool encontrado = false;
    for (auto& obj : objetos) {
        if (obj.category == objeto.category) {
            if (obj.name == objeto.name) {
                obj.stack += 1;
                encontrado = true;
                cout << "encontrado" << endl;
                break;
            }
        }
    }
    if (!encontrado) {
        //cout << "no encontrado" << endl;
        objetos.push_back(objeto);
    }
}

int main() {
    vector<Objeto> objetos;

    Objeto test;
    test.name = "test";
    test.category = "Espada";
    test.stack = 1;

    agregar_objeto(objetos, test);

    string category = "Espada";
    cout << "TEST" << endl;
    for (const auto& obj : objetos) {
        if (category == obj.category) {
            cout << obj.name << endl;
        }
        //cout << obj.name << obj.category << obj.stack << endl;
    }



    //Weapon espadaFina("Espada Fina", 40, 10);
    //Armour armaduraFina("Armadura Fina", 100);
    //Personaje cr7("El Bicho", 999, 999, 999, 999,999, 999, 999, 999, &espadaFina, &armaduraFina);

    return 0;
}