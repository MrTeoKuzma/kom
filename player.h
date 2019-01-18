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
#define MPREGEN 4
#define ADDHP 5


class Map;

class Player : public Creature{
    private:
        sf::Vector2i mouseCoord;
        Skill skills[6];
        string type;
        int currentSkill;

    public:
        Player(int x, int y, string type);
        void loadImg();
        int dash();
        void turn(int mX, int mY);
        int attack(Map * map, int mX, int mY);
        void action(Map *map);
        int getX();
        int getY();
        void setType(string type);
        void die(Map *map);
        void drawHp(sf::RenderWindow * window);
        void drawMP(sf::RenderWindow * window);
        void drawCurrentSkill(sf::RenderWindow * window);
        void setAttackSpeed(int i);
        void setSkill(int skill);
        void addHP();
};
#endif
