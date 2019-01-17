#ifndef PLAYER_H_
#define PLAYER_H_
#include "creature.h"
#include "skill.h"
#include "projectile.h"

//skills
#define DASH 0
#define SHOOT 1
#define FIRE1 2
#define WATER1 3


class Map;

class Player : public Creature{
    private:
        sf::Vector2i mouseCoord;
        Skill skills[4];
        string type;
        //string skillsList[2];
        bool thereIsSkin[13];
        int currentSkill;

    public:
        Player(int x, int y, string type);
        void loadImg();
        void dash();
        void turn(int mX, int mY);
        void attack(Map * map, int mX, int mY);
        void action(Map *map);
        int getX();
        int getY();
        void setType(string type);
        bool haveSkin(int index);
        void die(Map *map);
        void drawHp(sf::RenderWindow * window);
        void setAttackSpeed(int i);
        void setSkill(int skill);
};
#endif
