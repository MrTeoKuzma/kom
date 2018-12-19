#ifndef ENEMY01_H_
#define ENEMY01_H_
#include "creature.h"
#include "skill.h"
#include "player.h"

class Map;

class Enemy01 : public Creature{
    private:
        Skill skills[4];
        int startX;
        int endX;
        
    public:
        Enemy01(int x, int y);
        void loadImg();
        void attack(int mX, int mY);
        void action(Map *map);
};
#endif
