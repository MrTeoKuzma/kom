#ifndef ENEMY02_H_
#define ENEMY02_H_
#include "creature.h"
#include "skill.h"

class Map;
class Player;

#define SHOOT_E 0

class Enemy02 : public Creature{
    private:
        Skill skills[1];
        int startX;
        int endX;
        int startY;
        int endY;
        bool tick;
        Skill movement;


    public:
        Enemy02(int x, int y);
        void loadImg();
        void attack(Map * map, int pX, int pY);
        void action(Map *map);
        void die(Map * map);
};
#endif
