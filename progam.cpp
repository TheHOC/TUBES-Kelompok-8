#include <iostream>
#include <random>
#include <stdlib.h>
#include <cmath>

class Bunshin {       // buat summon robot apapun
    public: 
        int health;
        int damage;
        int posX;
        int posY;
        void giliran() {
            if (sqrt(pow(player.posX - posX, 2) + pow(player.posY - posY))) {

            }
        }
        Bunshin() {
            health = rand() % 20 + 21;
            damage = rand() % 5 + 1;
            posX = rand() % mapSizeX;
            posY = rand() % mapSizeY;
        }
};

class Robot {
    public:
        int health = 300;
        int damage = 10;
        int posX = 0;
        int posY = 0;
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
    Bunshin a;
    int mapSizeX = 10;
    int mapSizeY = 10;
    return 0;
};

