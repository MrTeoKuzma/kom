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
        sf::Texture hudImage;
        sf::Sprite background;
        sf::Sprite foreground;
        sf::Sprite hud;
        vector <Creature *> creatures;
        vector <Projectile *> projectiles;
        Player *player;
        Sound *soundsDash;
        Sound *soundsBackground;
        Sound *soundsAttack;
        Sound *soundsYouDied;
        vector <Sound *> attackSound;
        Sound *soundsWalk;
        Level *level;
        int x;
        int y;
        bool playerStatusBar;
        int place;
        int waves;

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
        void addPlayerHP(int h);
        void doAttackPlayer(int mX, int mY);
        void loadLevel(string fileName, int dotDmg);
        void loadBackground(string bgImage);
        void loadForeground(string fgImage);
        void loadHUD(string hudimg);
        void loadEarth(string type);
        void logicEarth();
        void loadFire(string type);
        void loadWater(string type);
        void loadLobby(string type);
        void loadAir(string type);
		void loadSound();
        void playSound(Sound * s);
        void changeType(string t);
        void stopSoundFightingMap();
        void stopSoundLobby();
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
        void loadAttackSounds();
        void loadYouDiedSound();
        void loadAirSound();

        void setSkillsTest(int s);
};
#endif
