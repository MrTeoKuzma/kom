#ifndef PLAYER_H_
#define PLAYER_H_
#include "creature.h"
#include "skill.h"

//skills
#define DASH 0

class Map;

class Player : public Creature{
    private:
        Skill skills[4];

    public:
        Player(sf::Vector2f center);
        void loadImg();
        void move(sf::View &view, int dir);
        void dash(sf::View &view);
        void action(Map *map);
};
#endif
