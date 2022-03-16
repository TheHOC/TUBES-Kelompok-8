#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cmath>
#include <time.h>
#include <string>


// INISIALISASI


class Layout {
    public:
        int size[2] = {10, 10};
        char matrix[10][10];
        Layout () {
            srand(time(NULL));
        }
        
};
Layout map;

class Robot {
    public:
        int health = 300;
        int damage = 10;
        int pos[2] = {1, 1};
        void giliran() {                        // perintah buat player untuk ambil giliran (belum selesai)

        }
};

Robot player;

class Bunshin {                                 // buat summon bunshin
    public: 
        int health;
        int damage;
        int pos[2];
        int range = 2;
        void attack() {             // perintah buat bunshin untuk attack player
            if (sqrt(pow(player.pos[0] - pos[0], 2) + pow(player.pos[1] - pos[1], 2)) < range) {
                player.health = player.health - damage;
            }
        }
        void gerak() {              // perintah buat bunshin bergerak (belum selesai)
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
                gerak();
            };
        }
        void giliran() {            // perintah buat bunshin untuk ambil giliran (belum selesai)
            if ((rand() % 1 == 1) && (health > 0)) {
                attack();
            } else {
                gerak();
            }
        }
        Bunshin() {
            srand(time(NULL));
            health = rand() % 20 + 21;
            damage = rand() % 5 + 1;
            pos[0] = rand() % (map.size[0] - 2) + 1;
            pos[1] = rand() % (map.size[1] - 2) + 1;

        }
};

Bunshin bunshins[15];                         // bunshin diinisialisasiin di sini

void inti(Layout map) {                       // inisialisasi (belum selesai)
    int bunshins = 0;
    player;
    while (player.health > 0) {
        player.giliran();
    }
}

void initMap() {
    for (int i = 0; i < map.size[1]; i++) {                                                                             
        for(int j = 0; j < map.size[0]; j++) {        
            map.matrix[i][j] = ' ';                                                  
            map.matrix[i][9] = '#';
            map.matrix[9][j] = '#';
            map.matrix[0][j] = '#';             /* Membuat matrix tembok dengan kode # pada peta */
            map.matrix[i][0] = '#';                                                                 
        }                                                                           
    }
}

void blit(Bunshin mecha[]) {
    initMap();
    map.matrix[player.pos[0]][player.pos[1]] = '@';
    for (int i = 0; i < sizeof(mecha); i++) {
        map.matrix[mecha[i].pos[0]][mecha[i].pos[1]] = '*';
    }
    for (int i = sizeof(map.matrix)/sizeof(map.matrix[0]) - 1; i >= 0; i--) {
        for (int j = 0; j < sizeof(map.matrix[i])/sizeof(map.matrix[0][0]); j++) {
            std::cout << map.matrix[i][j] << "  ";
        }
        std::cout << '\n';
    }
}

int main() {                       // kode diluar main() belum digabung                                       
    blit(bunshins);
    return 0;
};

