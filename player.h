#ifndef PLAYER_H_
#define PLAYER_H_
#include "creature.h"
#include "skill.h"
#include "projectile.h"

//skills
#define DASH 0
#define SHOOT 1

class Map;

class Player : public Creature{
    private:
        sf::Vector2i mouseCoord;
        Skill skills[4];
        
    public:
        Player(int x, int y);
        void loadImg();
        void dash();
        void turn(int mX, int mY);
        void attack(Map * map, int mX, int mY);
        void action(Map *map);
        int getX();
        int getY();
};
#endif
