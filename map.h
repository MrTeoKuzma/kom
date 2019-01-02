#ifndef MAP_H_
#define MAP_H_
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "creature.h"
#include "level.h"
#include "projectile.h"

using namespace std;

class Creature;
class Player;
class Projectile;

class Map{
    private:
        sf::Texture image;
        sf::Sprite background;
        vector <Creature *> creatures;
        vector <Projectile *> projectiles;
        Player *player;
        Level *level;
        int x;
        int y;

    public:
        Map(string bgImage); 
        void draw(sf::RenderWindow *window);
        void addCreature(Creature *creature);
        void addPlayer(Player *player);
        void addProjectile(Projectile * projectile);
        void removeProjectile(Projectile * projectile);
        void movePlayer(int dir);
        void dashPlayer();
        void doAttackPlayer(int mX, int mY);
        void loadLevel(string fileName, int dotDmg);
        Level * getLevel();
        Player * getPlayer();
};
#endif
