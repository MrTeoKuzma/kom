#ifndef MAP_H_
#define MAP_H_
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "creature.h"
#include "level.h"

using namespace std;

class Creature;
class Player;

class Map{
    private:
        sf::Texture image;
        sf::Sprite background;
        std::vector <Creature *> creatures;
        Player *player;
        Level *level;
        int x;
        int y;

    public:
        Map(string bgImage); 
        void draw(sf::RenderWindow *window);
        void addCreature(Creature *creature);
        void addPlayer(Player *player);
        void movePlayer(int dir);
        void dashPlayer();
        void doAttackPlayer(int mX, int mY);
        void loadLevel(string fileName, int dotDmg);
        Level * getLevel();
};
#endif
