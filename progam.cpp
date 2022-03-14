#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cmath>
#include <time.h>


// INISIALISASI
const int mapSize[2] = {10, 10};

class Robot {
    public:
        int health = 300;
        int damage = 10;
        int pos[2] = {0, 0};
        void giliran() {                        // perintah buat player untuk ambil giliran (belum selesai)

        }
};

class Bunshin {                                 // buat summon bunshin
    public: 
        int health;
        int damage;
        int pos[2];
        int range = 2;
        void attack(Robot player) {             // perintah buat bunshin untuk attack player
            if (sqrt(pow(player.pos[0] - pos[0], 2) + pow(player.pos[1] - pos[1], 2)) < range) {
                player.health = player.health - damage;
            }
        }
        void gerak(Robot player) {              // perintah buat bunshin bergerak (belum selesai)
            int arah = rand() % 4;
            if (arah) {

            }
            
        }
        void giliran(Robot player) {            // perintah buat bunshin untuk ambil giliran (belum selesai)
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

void inti() {                       // inisialisasi (belum selesai)
    Bunshin bunshinsArr[0];
    char **map = new char*[mapSize[1]];
    for (int i = 0; i < mapSize[1]; ++i) {
        map[i] = new char[mapSize[0]];
    }
    int bunshins = 0;
    Robot player;
    while (player.health > 0) {
        player.giliran();
    }
}

int main() {                        // kode diluar main() belum digabung
    int matrix[10][10];                                             
    int i,j,koor_x,koor_y, lower, upper,x,y;                                                                                                                                    
    for (i=0;i<10;i++) {                                                                             
        for (j=0;j<10;j++) {                                                                           
        matrix[i][j]=0;             /* Membuat matriks 10x10 ( yang beroperasi hanya 8x8 ) karena dikurangi oleh tembok */                                                    
        }                                                                           
    }   
    for (i=0;i<10;i++) {                                                                             
        for(j=0;j<10;j++) {                                                                           
        matrix[i][9]=2;
        matrix[9][j]=2;
        matrix[0][j]=2;             /* Membuat matrix tembok dengan kode 2 pada peta */
        matrix[j][0]=2;                                                                 
        }                                                                           
    }                                                                          
    printf("\nMatrix : \n"); 

    matrix[1][8]=1;                 /* Meletakan posisi robot awal (0,0) */
  
    for(i=9;i>-1;i=i-1) {                                                                             
        for(j=9;j>-1;j=j-1) {                                                                           
            if (matrix[i][j]==1) {       /* Program pembaca koordinat robot  */
                koor_x=9-j-1 ;
                koor_y=i-1;             /* Melakukan transformasi agar ke titik cartesius  */
            }                                        
        }                                                                                                                                          
    }       
    printf("koordinat-x: %d\n", koor_x);
    printf("koordinat-y: %d\n", koor_y);                    


    srand(time(0));    
    lower = 0;
    upper = 7;
    x = (rand() % (upper - lower + 1)) + lower;       /* Menginisiasikan bunshin mecha kurama */
    y = (rand() % (upper - lower + 1)) + lower;                       
    printf("koordinat x mecha :%d\n", x);
    printf("koordinat y mecha :%d\n", y);
    if (x==0) {
        if (y==0) {
            y = (rand() % (upper - lower + 1)) + lower;
            printf("koordinat x mecha :%d ", x);
            printf("koordinat y mecha %d\n", y);
        } 
    }
    
    matrix[y+1][8-x]=3;
    
    for(i=9;i>-1;i=i-1) {                                                                             
        for(j=9;j>-1;j=j-1) {                                                                           
          printf("%d\t", matrix[i][j]);                                    
        }                                                                           
        printf("\n");                                   /* Membuat peta */                            
    } 
    
    int inputUser, check;
    printf("Type 0 for attack or 1 to move: ");
    scanf("%d", &inputUser);
    if(inputUser == 0) {
        printf("Making desicion to attack"); 
    }
    else if (inputUser ==1) {
        printf("Making desicion to move");
    } else {
        check = 0;
        while (check == 0) {
            printf("Wrong input please try again");
            printf("Type 0 for attack or 1 to move: ");
            scanf("%d", &inputUser);
            if (inputUser == 0 ) {
            check = 1;
            printf("Making desicion to attack"); 
            }
            else if (inputUser == 1) {
                check = 1;
                printf("Making desicion to move");
            } else {
                check = 0;
            }     
        }
    }
    return 0;
};

