#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cmath>
#include <time.h>
#include <string>


// INISIALISASI
class Layout;
class Robot;
class Bunshin;
const int numberOfBunshins = 9;
float distance(float x0, float y0, float x1, float y1) {
    float range = sqrt(pow(y1 - y0, 2) + pow(x1 - x0, 2));
    return range;
}

class Layout {
    public:
        int size[2] = {15, 15};
        char matrix[15][15];
        Layout () {
            srand(time(NULL));
        }
        
};
Layout map;

class Robot {
    public:
        float health = 300;
        float damage = 10;
        float range = 4;
        int pos[2] = {1, 1};
        char turn;
        void takeTurn(Bunshin toHit[]) {                        // perintah buat player untuk ambil giliran (belum selesai)
            std::cout << "Apa yang mau kamu lakukan?" << std::endl;
            std::cout << "1. Serang sekitar (" << damage << " damage, " << range << " range)" << std::endl;
            std::cout << "2. Serang target terdekat (" << damage/5 << " damage)" << std::endl;
            std::cout << "3. Bergerak" << std::endl;
            std::cout << std::endl << ">> ";
            std::cin >> turn;
            while (turn != 1 && turn != 2 && turn != 3 && turn != 0) {
                std::cout << "Masukan salah!";
                std::cout << std::endl << ">> ";
                std::cin >> turn;
            }
            if (turn == 0) {

            } else if (turn == 1) {
                for (int i = 0; i < numberOfBunshins; i++) {
                    if (toHit[i].alive && distance(pos[0], pos[1], toHit[i].pos[0], toHit[i].pos[1])) {

                    }
                }
            } else if (turn == 2) {

            } else if (turn == 3) {

            }
        }
};

Robot player;

class Bunshin {                                 // buat summon bunshin
    public: 
        float health;
        float damage;
        float range = 2;
        int pos[2];
        int appearIn;
        bool inMap = false;
        bool alive = false;
        void attack(Robot toHit) {             // perintah buat bunshin untuk attack player
            if (distance(toHit.pos[0], toHit.pos[1], pos[0], pos[1]) < range) {
                toHit.health = toHit.health - damage;
            }
        }
        void move() {              // perintah buat bunshin bergerak (belum selesai)
            int arah = rand() % 5;
            if ((arah == 0) && ((pos[0] - 1 != player.pos[0]) || (pos[1] != player.pos[1])) && (pos[0] != 1)) {
                pos[0] = pos[0] - 1;
            } else if ((arah == 1) && ((pos[0] + 1 != player.pos[0]) || (pos[1] != player.pos[1])) && (pos[0] != 8)) {
                pos[0] = pos[0] + 1;
            } else if ((arah == 2) && ((pos[1] - 1 != player.pos[1]) || (pos[0] != player.pos[0])) && (pos[1] != 1)) {
                pos[1] = pos[1] - 1;
            } else if ((arah == 3) && ((pos[1] + 1 != player.pos[1]) || (pos[0] != player.pos[0])) && (pos[0] != 8)) {
                pos[1] = pos[1] + 1;
            } else if (arah == 4) {} else {
                move();
            };
        }
        void takeTurn() {            // perintah buat bunshin untuk ambil giliran (belum selesai)
            if (appearIn > 0) {
                appearIn--;
                if (appearIn <= 0) {
                    deploy();
                }
            } else if ((rand() % 1 == 1) && (distance(pos[0], pos[1], player.pos[0], player.pos[1]) < 2)) {
                attack();
            } else {
                move();
            }
        }
        void deploy() {
            health = rand() % 20 + 21;
            damage = rand() % 5 + 1;
            pos[0] = rand() % (map.size[0] - 2) + 1;
            pos[1] = rand() % (map.size[1] - 2) + 1;
            while (map.matrix[pos[0]][pos[1]] == ' ' || distance(pos[0], pos[1], player.pos[0], player.pos[1]) < 5) {
                pos[0] = rand() % (map.size[0] - 2) + 1;
                pos[1] = rand() % (map.size[1] - 2) + 1;
            }
            map.matrix[pos[0]][pos[1]] = '*';
            alive = true;
        }
        void death() {

        }
};

Bunshin bunshinList[numberOfBunshins];                         // bunshin diinisialisasiin di sini

void inti(Layout map) {                       // inisialisasi (belum selesai)
    int bunshinList = 0;
    player;
    while (player.health > 0) {
        player.takeTurn();
    }
}

void initMap() {
    for (int i = 0; i < map.size[1]; i++) {                                                                             
        for(int j = 0; j < map.size[0]; j++) {        
            map.matrix[i][j] = ' ';                                                  
            map.matrix[i][map.size[1] - 1] = '#';
            map.matrix[map.size[0] - 1][j] = '#';
            map.matrix[0][j] = '#';             /* Membuat matrix tembok dengan kode # pada peta */
            map.matrix[i][0] = '#';                                                                 
        }                                                                           
    }
}

void blit() {
    initMap();
    map.matrix[player.pos[0]][player.pos[1]] = 'o';
    for (int i = 0; i < numberOfBunshins; i++) {
        std::cout << bunshinList[i].alive << std::endl;
        if (bunshinList[i].alive) {
            map.matrix[bunshinList[i].pos[0]][bunshinList[i].pos[1]] = '*';
        }
    }
    for (int i = sizeof(map.matrix)/sizeof(map.matrix[0]) - 1; i >= 0; i--) {
        for (int j = 0; j < sizeof(map.matrix[i])/sizeof(map.matrix[0][0]); j++) {
            std::cout << map.matrix[i][j] << "  ";
        }
        std::cout << '\n';
    }
}

int main() {                       // kode diluar main() belum digabung
    map.matrix[player.pos[0]][player.pos[1]] = 'o';
    for (int i = 0; i < numberOfBunshins; i++) {
        bunshinList[i].appearIn = i * 3 + 1;
        bunshinList[i].takeTurn();
    }
    blit();
    player.takeTurn();
    for (int i = 0; i < numberOfBunshins; i++) {
        bunshinList[i].takeTurn();
    }
    blit();
    return 0;
};

