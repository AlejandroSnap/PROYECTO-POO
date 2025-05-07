# Diagrama

```mermaid
classDiagram
    class Hero {
        +Hero()
    }

    class Soldier {
        +Soldier()
    }

    class MiniBoss {
        +MiniBoss()
    }

    class Boss {
        +Boss()
    }

    class Character {
        -string name
        -map<string, Attack> attacks
        -map<string, Attribute> attributes
        +Character(string name)
    }

    class Attribute {
        -int hp
        -int atk
        -int def
        -int spd
        -int lck
        +Attribute(int hp, int atk, int def, int spd, int lck)
    }

    class Attack {
        -string name
        -string desc
        -string action
        -int damage
        -int accuracy
        +Attack(string name, string desc, string action)
    }

    class Armoure {
        -string name
        -string desc
        -int def
    }

    class Weapon {
        -string name
        -string desc
        -int bleed
    }

    class Player {
        -vector<Hero> heroes
        -vector<Objeto> objetos
    }

    class Objeto {
        -string name
        -string category
        -int stack
    }

    class Potion {

    }

    class Chest {
        
    }

    class Mercado {
        
    }

    class Inventario {
        -vector<Objeto> objetos
        +Inventario()
    }

    Inventario o-- Objeto
    Potion <|-- Objeto    
    Player o-- Hero
    Player o-- Inventario
    Weapon o-- Attack
    Character o-- Weapon
    Character o-- Armoure
    Hero <|-- Character
    Soldier <|-- Character
    MiniBoss <|-- Character
    Boss <|-- Character
    Character o-- Attribute
```
