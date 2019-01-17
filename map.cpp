#include "map.h"
#include "creature.h"
#include "player.h"
#include "enemy01.h"
#include "enemy02.h"
#include "projectile.h"
#include <algorithm>
#include <SFML/Audio.hpp>

Map::Map(): x(0), y(0), playerStatusBar(0), soundsBackground(0), soundsAttack(0), soundsDash(0), soundsWalk(0){
}

void Map::draw(sf::RenderWindow *window){
    window->draw(background);
    playSound(soundsBackground);

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
    window->draw(hud);
    if(playerStatusBar){
        player->drawHp(window);
    }
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
    playSound(soundsWalk);
    player->move(dir, level);
}

void Map::dashPlayer(){
    playSound(soundsDash);
    player->dash();
}

void Map::doAttackPlayer(int mX, int mY){
    player->attack(this, mX, mY);
    playSound(soundsAttack);
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
void Map::loadHUD(string hudimg){
    hudImage.loadFromFile(hudimg);
    hud.setTexture(hudImage, true);
}

void Map::loadEarth(){
    setPlayerStatusBar(true);
    soundsBackground=0;
    loadEarthSound();

    addCreature(new Enemy01(800, 600));
    addCreature(new Enemy01(900, 400));
    addCreature(new Enemy02(500, 300));
    addPlayer(new Player(500, 500, "earth"));
    player->setAttackSpeed(800);
}

void Map::loadFire(){
    setPlayerStatusBar(true);
    loadFireSound();

    addCreature(new Enemy01(800, 600));
    addCreature(new Enemy01(900, 400));
    addCreature(new Enemy01(500, 300));
    addPlayer(new Player(500, 500, "earth"));
    player->setAttackSpeed(1400);
}

void Map::loadWater(){
    setPlayerStatusBar(true);
    loadWaterSound();

    addCreature(new Enemy01(800, 600));
    addCreature(new Enemy01(900, 400));
    addCreature(new Enemy01(500, 300));
    addPlayer(new Player(500, 500, "earth"));
    player->setAttackSpeed(800);
}

void Map::loadLobby(){
    loadLobbySound();
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
    soundsBackground = new Sound("Glasba/sestaglasba.wav");
    soundsWalk = new Sound("Zvocni efekti/Hoja/HojaPoTravi.wav");
}
void Map::loadEarthSound(){
    loadAttackSounds();
    soundsWalk = new Sound("Zvocni efekti/Hoja/HojaPoTravi.wav");
    soundsBackground = new Sound("Glasba/osmaglasba.wav");
    soundsAttack = new Sound("Zvocni efekti/Napad/Psihokineza.wav");
    soundsDash = new Sound("Zvocni efekti/Akcije/Dash.wav");
}

void Map::loadFireSound(){
    soundsWalk = new Sound("Zvocni efekti/Hoja/HojaPoKamenju.wav");
    soundsBackground = new Sound("Glasba/sestaglasba.wav");
    soundsAttack = new Sound("Zvocni efekti/Napad/Fire.wav");
    soundsDash = new Sound("Zvocni efekti/Akcije/Dash.wav");
}

void Map::loadWaterSound(){
    soundsWalk = new Sound("Zvocni efekti/Hoja/HojaPoMokremPesku.wav");
    soundsBackground = new Sound("Glasba/sestaglasba.wav");
    soundsAttack = new Sound("Zvocni efekti/Napad/Voda.wav");
    soundsDash = new Sound("Zvocni efekti/Akcije/Dash.wav");
}

void Map::loadAttackSounds(){
    attackSound.push_back(new Sound ("Zvocni efekti/Napad/Psihokineza.wav"));
    attackSound.push_back(new Sound ("Zvocni efekti/Napad/Fire.wav"));
    attackSound.push_back(soundsAttack = new Sound("Zvocni efekti/Napad/Voda.wav"));
}

void Map::playSound(Sound *s){
    if(s){
        s->play();
    }
}

void Map::stopSoundLobby(){
    if(soundsBackground){
        soundsWalk->stop();
        soundsBackground->stop();
        delete soundsBackground;
        delete soundsWalk;
        soundsBackground = 0;
        soundsWalk = 0;
    }
}

void Map::stopSoundFightingMap(){
    if(soundsBackground){
        soundsWalk->stop();
        soundsBackground->stop();
        soundsAttack->stop();
        soundsDash->stop();
        delete soundsAttack;
        delete soundsDash;
        delete soundsBackground;
        delete soundsWalk;
        soundsBackground = 0;
        soundsWalk = 0;
        soundsAttack = 0;
        soundsDash = 0;
    }
}


void Map::setSkillsTest(int s)
{
    sf::err()<<soundsAttack<<std::endl;
    player->setSkill(s);
    switch(s){
    case 1:
        soundsAttack = attackSound[0];
        break;
    case 2:
        soundsAttack = attackSound[1];
        break;

    case 3:
        soundsAttack = attackSound[2];
        break;
    }
    sf::err()<<soundsAttack<<std::endl;
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
