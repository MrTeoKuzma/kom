#include "map.h"
#include "creature.h"
#include "player.h"
#include "enemy01.h"
#include "projectile.h"
#include <algorithm>
#include <SFML/Audio.hpp>

Map::Map(): x(0), y(0), playerStatusBar(0){
    setBGsound = -1;
}

void Map::draw(sf::RenderWindow *window){
    window->draw(background);
    playSound(setBGsound);
    if(playerStatusBar){
        player->drawHp(window);
    }
    unsigned int i;
    for(i = 0; i < creatures.size(); i++){
        (creatures[i])->action(this);
        (creatures[i])->draw(window);
    }

    for(i = 0; i < projectiles.size(); i++){
        (projectiles[i])->draw(window);
        (projectiles[i])->action(this);
    }
    window->draw(foreground);
}

void Map::addCreature(Creature *creature){
    creatures.push_back(creature);
}

void Map::addPlayer(Player *player){
    Map::player = player;
    addCreature(player);
}

void Map::addProjectile(Projectile * projectile){
    projectiles.push_back(projectile);
}

void Map::removeProjectile(Projectile * projectile){
    //https://stackoverflow.com/questions/26567687/how-to-erase-vector-element-by-pointer
    projectiles.erase(std::remove(projectiles.begin(), projectiles.end(), projectile), projectiles.end());
}

void Map::removeCreature(Creature * creature){
    creatures.erase(std::remove(creatures.begin(), creatures.end(), creature), creatures.end());
}

void Map::movePlayer(int dir){
    playSound(HOJAPOTRAVISOUND);
    player->move(dir, level);
}

void Map::dashPlayer(){
    playSound(DASHSOUND);
    player->dash();
}

void Map::doAttackPlayer(int mX, int mY){
    player->attack(this, mX, mY);
}

void Map::loadLevel(string fileName, int dotDmg){
    level = new Level(fileName, dotDmg);
}

void Map::loadBackground(string bgImage){
    backgroundImage.loadFromFile(bgImage);
    background.setTexture(backgroundImage, true);
}

void Map::loadForeground(string fgImage){
    foregroundImage.loadFromFile(fgImage);
    foreground.setTexture(foregroundImage, true);
}

void Map::loadEarth(){
    setPlayerStatusBar(true);
    loadEarthSound();
    setBackgroundSound(GLASBA008SOUND);
    addCreature(new Enemy01(800, 600));
    addCreature(new Enemy01(900, 400));
    addCreature(new Enemy01(500, 300));
    addPlayer(new Player(500, 500, "earth"));
}

void Map::loadLobby(){
    loadLobbySound();
    setBackgroundSound(GLASBA006SOUND);
    addPlayer(new Player(500, 500, "earth"));
}
Level * Map::getLevel(){
    return level;
}

Player * Map::getPlayer(){
    return player;
}

int Map::isProjectileHit(sf::IntRect * obj, int category){
    for(unsigned int i=0; i<projectiles.size(); i++){
        if(projectiles[i]->getHitbox()->intersects(*obj) && projectiles[i]->getTarget() == category){
            removeProjectile(projectiles[i]);
            return projectiles[i]->getDmg();
        }
    }
    return 0;
}
/*
void Map::loadSound() {

    sounds[DASHSOUND] = new Sound("Zvocni efekti/Akcije/Dash.wav");
    sounds[KUPLJENOSHOPSOUND] = new Sound("Zvocni efekti/Akcije/Kupljeno_shop.wav");
    sounds[POBIRANJECOINOVSOUND] = new Sound("Zvocni efekti/Akcije/Pobiranje_coinov.wav");
    sounds[HOJAPOTRAVISOUND] = new Sound("Zvocni efekti/Hoja/HojaPoTravi.wav");
    sounds[HOJAPOMOKREMPESKUSOUND] = new Sound("Zvocni efekti/Hoja/HojaPoMokremPesku.wav");
    sounds[HOJAPOKAMENJUSOUND] = new Sound("Zvocni efekti/Hoja/HojaPoKamenju.wav");
    sounds[LEDSOUND] = new Sound("Zvocni efekti/Napad/Led.wav");
    sounds[NALAGANJESTRELESOUND] = new Sound("Zvocni efekti/Napad/Nalaganje strele.wav");
    sounds[NEVIHTASOUND] = new Sound("Zvocni efekti/Napad/Nevihta.wav");
    sounds[OGENJSOUND] = new Sound("Zvocni efekti/Napad/Ogenj.wav");
    sounds[PSIHOKINEZASOUND] = new Sound("Zvocni efekti/Napad/Psihokineza.wav");
    sounds[TEMASOUND] = new Sound("Zvocni efekti/Napad/Tema.wav");
    sounds[UDARSTRELESOUND] = new Sound("Zvocni efekti/Napad/Udar_strele.wav");
    sounds[VETERSOUND] = new Sound("Zvocni efekti/Napad/Veter.wav");
    sounds[VODASOUND] = new Sound("Zvocni efekti/Napad/Voda.wav");
    sounds[PREJEMUDARCASOUND] = new Sound("Zvocni efekti/Prejem_udarca/Prejem_udarca.wav");
    sounds[PRIKAZNASPROTNIKA01SOUND] = new Sound("Zvocni efekti/Prikaz nasprotnika/Prikaz_nasprotnika001.wav");
    sounds[PRIKAZNASPROTNIKA02SOUND] = new Sound("Zvocni efekti/Prikaz nasprotnika/Prikaz_nasprotnika002.wav");
    sounds[PRIKAZNASPROTNIKA03SOUND] = new Sound("Zvocni efekti/Prikaz nasprotnika/Prikaz_nasprotnika003.wav");
    sounds[PRIKAZNASPROTNIKA04SOUND] = new Sound("Zvocni efekti/Prikaz nasprotnika/Prikaz_nasprotnika004.wav");
    sounds[PRIKAZNASPROTNIKA05SOUND] = new Sound("Zvocni efekti/Prikaz nasprotnika/Prikaz_nasprotnika005.wav");
    sounds[PRIKAZNASPROTNIKA06SOUND] = new Sound("Zvocni efekti/Prikaz nasprotnika/Prikaz_nasprotnika006.wav");
    sounds[PRIKAZNASPROTNIKA07SOUND] = new Sound("Zvocni efekti/Prikaz nasprotnika/Prikaz_nasprotnika007.wav");
    sounds[PRIKAZNASPROTNIKA08SOUND] = new Sound("Zvocni efekti/Prikaz nasprotnika/Prikaz_nasprotnika008.wav");
}
*/
void Map::loadLobbySound(){
    sounds[GLASBA006SOUND] = new Sound("Glasba/sestaglasba.wav");
    sounds[HOJAPOTRAVISOUND] = new Sound("Zvocni efekti/Hoja/HojaPoTravi.wav");
}
void Map::loadEarthSound(){
    sounds[HOJAPOTRAVISOUND] = new Sound("Zvocni efekti/Hoja/HojaPoTravi.wav");
    sounds[GLASBA008SOUND] = new Sound("Glasba/osmaglasba.wav");
    sounds[HOJAPOTRAVISOUND] = new Sound("Zvocni efekti/Hoja/HojaPoTravi.wav");
    sounds[PSIHOKINEZASOUND] = new Sound("Zvocni efekti/Napad/Psihokineza.wav");
    sounds[DASHSOUND] = new Sound("Zvocni efekti/Akcije/Dash.wav");
}


void Map::playSound(int i){
    if(i>=0)
    {
        sounds[i]->play();
    }

}
void Map::setBackgroundSound(int i){
    setBGsound = i;
}


void Map::changeType(int t) // spremeni tip skina
{

    if (player->haveSkin(t)) // ce ima dolocan skil
    {
        switch (t)
        {
            case 0:
                player->setType("standard");
                break;

            case 1:
                player->setType("fire");
                break;

            case 2:
                player->setType("water");
                break;

            case 3:
                player->setType("air");
                break;

            case 4:
                player->setType("earth");
                break;

            case 5:
                player->setType("lightning");
                break;

            case 6:
                player->setType("lava");
                break;

            case 7:
                player->setType("storm");
                break;

            case 8:
                player->setType("ice");
                break;

            case 9:
                player->setType("light");
                break;

            case 10:
                player->setType("dark");
                break;

            case 11:
                player->setType("psi");
                break;

            case 12:
                player->setType("vakuum");
                break;
        }
        player->loadImg();
    }
}

void Map::setPlayerStatusBar(bool status){
    playerStatusBar = status;
}

void Map::action(int &place){
    place = Map::place;
    switch(place){
        case 2:
            if(creatures.size() == 1){
                place = 0;
            }
        break;
    }
}

void Map::setPlace(int place){
    Map::place = place;
}
