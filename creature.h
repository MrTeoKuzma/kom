#ifndef CREATURE_H_
#define CREATURE_H_
#include <SFML/Graphics.hpp>
#include "map.h"
#include "skill.h"
#include "level.h"
#include "animation.h"

//direction
#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

//state
#define NORMAL 0
#define STUN 1
#define ATTACK 2
#define DASHING 3
#define RUNNING 4

//status
#define NOTHING 0
#define DOT 1
#define INVUNERABLE 2

#define SPRITE_NUM 1

#define Y_DIFF(s, d) (s * !(d%2) * (d-1)) // 0 = +step, 1 = 0, 2 = -step, 3 = 0
#define X_DIFF(s, d) (s * (d%2) * (d-2) * -1) // 0 = 0, 1 = +step, 2 = 0, 3 = -step

class Map;

class Creature{
    protected:
        int x;
        int y;
        int width;
        int height;
        int hpMax;
        int hp;
        int mpMax;
        int mp;
        float step;
        int direction;
        int state;
        int status;
        Skill statusChange;
        Skill stateChange;
        int spriteI;
        Animation * animation;
        sf::Texture sprite[4][5][3][SPRITE_NUM];

    public:
        Creature();
        Creature(int x, int y);
        void init();
        void draw(sf::RenderWindow *window);
        void setStatus(int status, int duration);
        void setState(int state, int duration);
        void canMove(int &step, Level * level);
        void move(int dir, Level * level);
        virtual void action(Map *map);
        virtual void loadImg() = 0; 
};
#endif
