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
        sf::Texture backgroundImage;
        sf::Texture foregroundImage;
        sf::Sprite background;
        sf::Sprite foreground;
        vector <Creature *> creatures;
        vector <Projectile *> projectiles;
        Player *player;
        Sound *soundsDash;
        Sound *soundsBackground;
        Sound *soundsAttack;
        Sound *soundsWalk;
        Level *level;
        int x;
        int y;
        bool playerStatusBar;
        int place;
        int setBGsound;
        int walkSound;
        int attackSound;

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
        void loadForeground(string fgImage);
        void loadEarth();
        void loadFire();
        void loadWater();
        void loadLobby();
		void loadSound();
        void playSound(Sound * s);
        void stopSoundLobby();
        void stopSoundFightingMap();
        void changeType(int t);
        int isProjectileHit(sf::IntRect * obj, int category);
        Level * getLevel();
        Player * getPlayer();
        void setPlayerStatusBar(bool status);
        void action(int &place);
        void setPlace(int place);

        void loadLobbySound();
        void loadEarthSound();
        void loadFireSound();
        void loadWaterSound();
        void setBackgroundSound(int i);

        void setSkillsTest(int s);
};
#endif
