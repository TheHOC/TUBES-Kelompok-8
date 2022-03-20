#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cmath>
#include <time.h>
#include <string>
#include <chrono>
#include <thread>


// INISIALISASI
class Layout;
class Robot;
class Bunshin;

int score;
bool game;

void sleep(long seconds) {                                                      // utk ngepause setiap ada beberapa command
    std::this_thread::sleep_for(std::chrono::milliseconds(seconds*1000));
}

const int numberOfBunshins = 9;

float distance(float x0, float y0, float x1, float y1) {            // fungsi mengukur jarak
    float range = sqrt(pow(y1 - y0, 2) + pow(x1 - x0, 2));
    return range;
}

class Layout {                          // untuk amp
    public:
        int size[2] = {8, 8};
        char matrix[8][8];
        Layout () {
            srand(time(NULL));
        }
        
};
Layout map;


class Robot {                       // untuk robot yang dipakai pemain
    public:
        float health = 10;
        float damage = 10;
        float range = 4;
        int pos[2] = {1, 1};
        bool alive = true;
};

Robot player;

class Bunshin {                                 // buat summon bunshin
    public: 
        float health;
        float damage;
        float range = 3;
        int pos[2];
        int appearIn;
        bool inMap = false;
        bool alive = false;

        bool stuck(Layout map) {                            // boolean yang menandakan ketidakbisa gerakan player setelah mengambil turn, bisa karena bunshin maupun tembok (#)
            return ((map.matrix[pos[0]+1][pos[1]] != ' ') && (map.matrix[pos[0]-1][pos[1]] != ' ') && (map.matrix[pos[0]][pos[1]+1] != ' ') && (map.matrix[pos[0]][pos[1]-1] != ' '));
        }

        void move(Layout *map, int index = 0) {              // perintah buat bunshin bergerak (belum selesai)
            int dice = (rand() + index) % 5;

            if ((dice == 0) && (map->matrix[pos[0] - 1][pos[1]] == ' ') && (pos[0] != 1)) {
                pos[0] -= 1;
                map->matrix[pos[0] - 1][pos[1]] = '*';
                map->matrix[pos[0]][pos[1]] = ' ';
                sleep(0.5);
            } else if ((dice == 1) && (map->matrix[pos[0] + 1][pos[1]] == ' ') && (pos[0] != map->size[0] - 2)) {
                pos[0] += 1;
                map->matrix[pos[0] + 1][pos[1]] = '*';
                map->matrix[pos[0]][pos[1]] = ' ';
                sleep(0.5);
            } else if ((dice == 2) && (map->matrix[pos[0]][pos[1] - 1] == ' ') && (pos[1] != 1)) {
                pos[1] -= 1;
                map->matrix[pos[1] - 1][pos[1]] = '*';
                map->matrix[pos[1]][pos[1]] = ' ';
                sleep(0.5);
            } else if ((dice == 3) && (map->matrix[pos[0]][pos[1] + 1] == ' ') && (pos[1] != map->size[1] - 2)) {
                pos[1] += 1;
                map->matrix[pos[1] + 1][pos[1]] = '*';
                map->matrix[pos[1]][pos[1]] = ' ';
            } else if (dice == 4) {};
        }

        void deploy(Layout *map) {                      // untuk memunculkan bunshin di map
            health = rand() % 20 + 21;
            damage = rand() % 5 + 1;
            pos[0] = rand() % (map->size[0] - 2) + 1;
            pos[1] = rand() % (map->size[1] - 2) + 1;
            while ((map->matrix[pos[1]][pos[0]] != ' ') || distance(pos[0], pos[1], player.pos[0], player.pos[1]) < 5) {
                // std::cout << map->matrix[pos[1]][pos[0]] << (map->matrix[pos[1]][pos[0]] == ' ') << std::endl;
                pos[0] = rand() % (map->size[0] - 2) + 1;
                pos[1] = rand() % (map->size[1] - 2) + 1;
            }
            map->matrix[pos[1]][pos[0]] = '*';
            // std::cout << "deployed " << pos[0] << pos[1] << std::endl;
            alive = true;
        }

        void death(Layout *map) {                       // dijalankan ketika suatu bunshin mati
            alive = false;
            score += 1;
            std::cout << "Salah satu bunshin mati!" << std::endl;
            map->matrix[pos[1]][pos[0]] = ' ';
<<<<<<< HEAD
            appearIn = rand() % 2 + 8;
            sleep(1.5);
=======
            appearIn = rand() % 2 + 8;                  // bunshin lain akan muncul setelah beberapa giliran
            sleep(0.5);
>>>>>>> 0dd984d (Menambahkan komentar untuk keterangan beberapa fungsi)
        }
};

Bunshin bunshinList[numberOfBunshins];                         // bunshin diinisialisasiin di sini

void initMap() {
    for (int i = 0; i < map.size[1]; i++) {                                                                             
        for(int j = 0; j < map.size[0]; j++) {  
            map.matrix[j][i] = ' ';                                                      
            map.matrix[j][map.size[0] - 1] = '#';
            map.matrix[map.size[1] - 1][i] = '#';
            map.matrix[0][i] = '#';                             /* Membuat matrix tembok dengan kode # pada peta */
            map.matrix[j][0] = '#';                                                                 
        }                                                                           
    }

    map.matrix[player.pos[1]][player.pos[0]] = 'o';             // posisi player ditandai dengan 'o'
    for (int i = 0; i < numberOfBunshins; i++) {
        if (bunshinList[i].alive) {
            map.matrix[bunshinList[i].pos[1]][bunshinList[i].pos[0]] = '*';         // posisi bunshin ditandai dengan '*'
        }
    }

}

void blit() {                                                                       // untuk update map                                        
    initMap();
    for (int i = sizeof(map.matrix)/sizeof(map.matrix[0]) - 1; i >= 0; i--) {
        for (int j = 0; j < sizeof(map.matrix[i])/sizeof(map.matrix[0][0]); j++) {
            std::cout << map.matrix[i][j] << "  ";
        }
        std::cout << '\n';
    }
}

<<<<<<< HEAD
void botAttack(Bunshin *bot, Robot *player) {
    if (distance(player->pos[0], player->pos[1], bot->pos[0], bot->pos[1]) < bot->range && (player->alive == true)) {
=======
void botAttack(Bunshin *bot, Robot *player) {                                                   // output setelah bunshin menyerang
    if (distance(player->pos[0], player->pos[1], bot->pos[0], bot->pos[1]) < bot->range) {
>>>>>>> 0dd984d (Menambahkan komentar untuk keterangan beberapa fungsi)
        player->health = player->health - bot->damage;
        std::cout << "Kamu terkena serangan! (-" << bot->damage << " health)" << std::endl;
        sleep(1.5);
        std::cout << "lewat sini!1" << std::endl;
        if (player->health <= 0) {
            player->alive = false;
            std::cout << "Kamu telah mati!" << std::endl;
            sleep(3);
            game = false;
        }
    }
}

void botTurn(Bunshin *bot, Robot *player, Layout *map, int index = 0) {            // perintah buat bunshin untuk ambil giliran (belum selesai)
    int dice = (rand() % 10) + 1;
    if (bot->appearIn > 0) {
        bot->appearIn--;
        if (bot->appearIn <= 0) {
            bot->deploy(map);
        }
    } else if ((9 <= dice <= 10) && (distance(bot->pos[0], bot->pos[1], player->pos[0], player->pos[1]) < bot->range)) {
        botAttack(bot, player);
        std::cout << "lewat sini!2" << std::endl;
    } else if (4 <= dice <= 8) {
        if (distance(bot->pos[0], bot->pos[1], player->pos[0], player->pos[1]) < bot->range) {
            botAttack(bot, player);
            std::cout << "lewat sini!3" << std::endl;
        } else {
            bot->move(map, index);
        }
    } else if (1 <= dice <= 3) {
        bot->move(map, index);
    }
}

void playerTurn(Bunshin (&bot)[numberOfBunshins], Robot *player, Layout *map) {                        // perintah buat player untuk ambil giliran (belum selesai)
    char act;
    std::cout   << "Health: " << player->health << std::endl
                << "Apa yang mau kamu lakukan?" << std::endl
                << "1. Serang sekitar (" << player->damage << " damage, " << player->range << " range)" << std::endl
                << "2. Serang musuh terdekat (" << player->damage/10 << " damage)" << std::endl
                << "3. Bergerak" << std::endl
                << "0. Keluar program"
                << "\n>> ";
    std::cin    >> act;
    while (act != '1' && act != '2' && act != '3' && act != '0') {
        std::cout   << "Masukan salah!" << std::endl
                    << ">> ";
        std::cin    >> act;
    }
    if (act == '0') {
        char con;
        std::cout   << "Apakah anda yakin ingin keluar?[Y/n]"
                    << "\n>> ";
        std::cin    >> con;
        while (con != 'Y' && con != 'N' && con != 'n') {
            std::cout   << "Masukan salah!"
                        << "\n>> ";
            std::cin    >> con;
        }
        if (con == 'Y') {
            game = false;
            system("cls");
            std::cout << "Game diakhiri!";
            sleep(3);
        } else {
            system("cls");
            blit();
            playerTurn(bot, player, map);
        }
    } else if (act == '1') {
        int hitNum = 0;
        for (int i = 0; i < numberOfBunshins; i++) {
            if ((bot)[i].alive && (distance(player->pos[0], player->pos[1], (bot)[i].pos[0], (bot)[i].pos[1]) < player->range)) {
                (bot)[i].health -= player->damage;
                hitNum += 1;
                if ((bot)[i].health <= 0) {
                    (bot)[i].death(map);
                    map->matrix[(bot)[i].pos[1]][(bot)[i].pos[0]] = ' ';
                }
            }
        }
        if (hitNum > 0) {
            std::cout << hitNum << " bunshin kena seranganmu." << std::endl;
            sleep(1.5);
        } else {
            std::cout << "Tidak ada bunshin yang kena seranganmu!" << std::endl;
            sleep(1.5);
        }
    } else if (act == '2') {
        float botMinRange = 0;
        Bunshin *closest;
        for (int i = 0; i < numberOfBunshins; i++) {
            // std::cout << (distance(player->pos[0], player->pos[1], (bot)[i].pos[0], (bot)[i].pos[1]) < botMinRange) << " " << botMinRange << " " << distance(player->pos[0], player->pos[1], (bot)[i].pos[0], (bot)[i].pos[1]) << std::endl;
            // std::cout << (bot)[i].alive << " | " << (bot)[i].pos[0] << " | " << (bot)[i].pos[1] << std::endl;
            if (((bot)[i].alive) && ((botMinRange == 0) || (distance(player->pos[0], player->pos[1], (bot)[i].pos[0], (bot)[i].pos[1]) < botMinRange))) {
                botMinRange = distance(player->pos[0], player->pos[1], (bot)[i].pos[0], (bot)[i].pos[1]);
                closest = (&bot)[i];
            }
        }
        if (botMinRange != 0) {
            closest->health -= player->damage/10;
            if (closest->health <= 0) {
                closest->death(map);
                map->matrix[closest->pos[1]][closest->pos[0]] = ' ';
            }
            std::cout << "Seranganmu kena salah satu bunshin!" << std::endl;
            sleep(1.5);
        } else {
            std::cout << "Peluru seranganmu nyasar!" << std::endl;
            sleep(1.5);
        }
    } else if (act == '3') {
        char moves[4] = {'w', 'a', 's', 'd'};
        bool avMo[4];            // Available moves
        char choice;
        avMo[0] = (map->matrix[player->pos[0]][player->pos[1]+1] == ' ');
        avMo[1] = (map->matrix[player->pos[0]-1][player->pos[1]] == ' ');
        avMo[2] = (map->matrix[player->pos[0]][player->pos[1]-1] == ' ');
        avMo[3] = (map->matrix[player->pos[0]+1][player->pos[1]] == ' ');
        if (avMo[0] || avMo[1] || avMo[2] || avMo[3]) {
            std::cout << "Mau gerak ke mana? ( ";
            for (int i = 0; i < 4; i++) {
                if (avMo[i]) {
                    std::cout << moves[i] << " ";
                }
            }
            std::cout   << ")" << std::endl
                        << ">> ";
            std::cin    >> choice;
            while (!(avMo[0] && (choice == 'w' || choice == 'W')) && !(avMo[1] && (choice == 'a' || choice == 'A')) && !(avMo[2] && (choice == 's' || choice == 'S')) && !(avMo[3] && (choice == 'd' || choice == 'D'))) {
                std::cout << "Masukan salah!" << std::endl;
                sleep(1);
                std::cout   << ">> ";
                std::cin    >> choice;
            }
            if (avMo[0] && (choice == 'w' || choice == 'W')) {
                map->matrix[player->pos[0]][player->pos[1]] = ' ';
                player->pos[1] += 1;
                map->matrix[player->pos[0]][player->pos[1]+1] = 'o';
            } else if (avMo[1] && (choice == 'a' || choice == 'A')) {
                map->matrix[player->pos[0]][player->pos[1]] = ' ';
                player->pos[0] -= 1;
                map->matrix[player->pos[0]-1][player->pos[1]] = 'o';
            } else if (avMo[2] && (choice == 's' || choice == 'S')) {
                map->matrix[player->pos[0]][player->pos[1]] = ' ';
                player->pos[1] -= 1;
                map->matrix[player->pos[0]][player->pos[1]-1] = 'o';
            } else if (avMo[3] && (choice == 'd' || choice == 'D')) {
                map->matrix[player->pos[0]][player->pos[1]] = ' ';
                player->pos[0] += 1;
                map->matrix[player->pos[0]+1][player->pos[1]] = 'o';
            }     
        } else {
            system("cls");
            std::cout << "Kamu tidak bisa bergerak." << std::endl;
            sleep(1.5);
            system("cls");
            blit();
            playerTurn(bot, player, map);
        }
    }
}

void initGame() {                       // saat memulai game
    score = 0;
    initMap();
    map.matrix[player.pos[1]][player.pos[0]] = 'o';
    for (int i = 0; i < numberOfBunshins; i++) {
        bunshinList[i].appearIn = i * 3 + 1;
        botTurn(&bunshinList[i], &player, &map, i);
        std::cout << "lewat sini!4" << std::endl;
    }
    blit();
}

void mainLoop() {                                       // untuk pengulangan giliran.
    playerTurn(bunshinList, &player, &map);
    for (int i = 0; i < numberOfBunshins; i++) {
        srand(time(NULL));
        botTurn(&bunshinList[i], &player, &map, i);
        std::cout << "lewat sini!5" << std::endl;
        // std::cout << bunshinList[i].appearIn << " | " << bunshinList[i].pos[0] << " | " << bunshinList[i].pos[1] << " | " << bunshinList[i].health << std::endl;
    }
    system("cls");
    blit();
}

int main() {                       // kode diluar main() belum digabung
    initGame();
    game = true;
    while (game) {
        mainLoop();
    }
    system("cls");
    blit();
    std::cout   << "\nGAME BERAKHIR"
                << "\nskor : " << score << std::endl;
    system("Pause");
    return 0;
};

