#include <iostream>
#include <random>
#include <stdlib.h>

class Bunshin {       // buat summon robot apapun
    public: 
        int health;
        int damage;
};

class Robot {
    public:
        int health = 300;
        int damage = 10;
        int armor = 2;
        void giliran() {

        }
};

void newBunshin() {
    
    
}

void inti() {
    int bunshins = 0;
    
    Robot player;
    while (player.health > 0) {
        player.giliran();
    }
}

int main() {
    return 0;
};

