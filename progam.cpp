#include <iostream>
#include <stdlib.h>
#include <cmath>


int rows = 1, cols = 2;
int** matrix = new int*[rows];


const int mapSize[2] = {10, 10};
char **map = new char*[mapSize[0]];



void initMenu() {

}

class Robot {
    public:
        int health = 300;
        int damage = 10;
        int pos[2] = {0, 0};
        void giliran() {

        }
};

class Bunshin {       // buat summon bunshin
    public: 
        int health;
        int damage;
        int pos[2];
        int range = 2;
        void attack(Robot player) {
            if (sqrt(pow(player.pos[0] - pos[0], 2) + pow(player.pos[1] - pos[1], 2)) < range) {
                player.health = player.health - damage;
            }
        }
        void gerak(Robot player) {
            int arah = rand() % 4;
            if (arah) {

            }
            
        }
        void giliran(Robot player) {
            if (rand() % 1 == 1) {
                attack(player);
            } else {

            }
        }
        Bunshin() {
            health = rand() % 20 + 21;
            damage = rand() % 5 + 1;
            pos[0] = rand() % mapSize[0];
            pos[1] = rand() % mapSize[1];

        }
};

void newBunshin() {
    
    
}

void inti() {
    Bunshin bunshinsArr[0];
    for (int i = 0; i < rows; ++i) {
    matrix[i] = new int[cols];
    }
    int bunshins = 0;
    Robot player;
    while (player.health > 0) {
        player.giliran();
    }
}

int main() {
    Bunshin myObj;
    
    return 0;
};

