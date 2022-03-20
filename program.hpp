#ifndef __PROGRAM_HPP__
#define __PROGRAM_HPP__

#include <iostream>

using namespace std;

class Layout {
    public:
        int size[2];
        char matrix[15][15];
        Layout ();
};

class Robot {
    public:
        float health;
        float damage;
        float range;
        int pos[2];
        char turn;

        void takeTurn(Bunshin toHit[]);
};

class Bunshin {
    public:
        float health;
        float damage;
        float range;

        int pos[2];
        int appearIn;

        bool inMap;
        bool alive;

        void attack(Robot toHit);
        void move();
        void takeTurn();
        void deploy();
        void death();
};

#endif