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

//Sound
#define DASHSOUND 0
#define HOJAPOTRAVISOUND 1
#define HOJAPOMOKREMPESKUSOUND 2
#define HOJAPOKAMENJUSOUND 3
#define PRIKAZNASPROTNIKA01SOUND 4
#define PRIKAZNASPROTNIKA02SOUND 5
#define PRIKAZNASPROTNIKA03SOUND 6
#define PRIKAZNASPROTNIKA04SOUND 7
#define PRIKAZNASPROTNIKA05SOUND 8
#define PRIKAZNASPROTNIKA06SOUND 9
#define PRIKAZNASPROTNIKA07SOUND 10
#define PRIKAZNASPROTNIKA08SOUND 11
#define LEDSOUND 12
#define NALAGANJESTRELESOUND 13
#define NEVIHTASOUND 14
#define OGENJSOUND 15
#define PSIHOKINEZASOUND 16
#define TEMASOUND 17
#define UDARSTRELESOUND 18
#define VETERSOUND 19
#define VODASOUND 20
#define KUPLJENOSHOPSOUND 21
#define POBIRANJECOINOVSOUND 22
#define PREJEMUDARCASOUND 23
#define GLASBA006SOUND 24
#define GLASBA008SOUND 25

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
        int left;
        int top;
        sf::IntRect hitbox;
        Skill statusChange;
        Skill stateChange;
        int spriteI;
        Animation * animation;
        sf::Texture sprite[4][5][3][SPRITE_NUM];
        int category;

    public:
        Creature();
        Creature(int x, int y);
        void init();
        void draw(sf::RenderWindow *window);
        void setStatus(int status, int duration);
        void setState(int state, int duration);
        void canMove(int &step, Level * level);
        void move(int dir, Level * level);
        void setHP(int h);
        int getHP();
        bool isHit(sf::IntRect obst);
        virtual void action(Map *map);
        virtual void loadImg() = 0;
        virtual void die(Map *map) = 0;
};
#endif
