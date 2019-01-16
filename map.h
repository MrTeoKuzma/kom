#ifndef MAP_H_
#define MAP_H_
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "creature.h"
#include "level.h"
#include "projectile.h"
#include "sound.h"
#include <SFML/Audio.hpp>

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
        Sound *sounds[40];
        Level *level;
        int x;
        int y;

    public:
        Map();
        void draw(sf::RenderWindow *window);
        void addCreature(Creature *creature);
        void addPlayer(Player *player);
        void addProjectile(Projectile * projectile);
        void removeProjectile(Projectile * projectile);
        void removeCreature(Creature * creature);
        void movePlayer(int dir);
        void dashPlayer();
        void doAttackPlayer(int mX, int mY);
        void loadLevel(string fileName, int dotDmg);
        void loadBackground(string bgImage);
        void loadEarth();
        void loadLobby();
		void loadSound();
        void playSound(int i);
        void changeType(int t);
        int isProjectileHit(sf::IntRect * obj, int category);
        Level * getLevel();
        Player * getPlayer();
};
#endif
