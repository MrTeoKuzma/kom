#include "map.h"
#include "creature.h"
#include "player.h"
#include "enemy01.h"
#include "enemy02.h"
#include "projectile.h"
#include <algorithm>
#include <SFML/Audio.hpp>

Map::Map(): soundsDash(0), soundsBackground(0), soundsAttack(0), soundsWalk(0), x(0), y(0), playerStatusBar(0) {
}

void Map::draw(sf::RenderWindow *window){
    window->draw(background);
    playSound(soundsBackground);

    unsigned int i;
    for(i = 0; i < creatures.size(); i++){
        (creatures[i])->action(this);
        (creatures[i])->draw(window);
    }
    sf::err() << std::endl;

    for(i = 0; i < projectiles.size(); i++){
        (projectiles[i])->draw(window);
        (projectiles[i])->action(this);
    }
    window->draw(foreground);
    window->draw(hud);
    if(playerStatusBar){
        player->drawHp(window);
        player->drawMP(window);
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
    if(player->dash()){
        playSound(soundsDash);
    }
}

void Map::doAttackPlayer(int mX, int mY){
    if(player->attack(this, mX, mY)){
        playSound(soundsAttack);
    }
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

void Map::loadEarth(string type){
    waves = 2;
    setPlayerStatusBar(true);
    soundsBackground=0;
    loadEarthSound();


    addPlayer(new Player(500, 500, type));
    player->setAttackSpeed(800);
}

void Map::loadFire(string type){
    setPlayerStatusBar(true);
    loadFireSound();
    waves= 4;

    addPlayer(new Player(500, 500, type));
    player->setAttackSpeed(800);
}

void Map::loadWater(string type){
    setPlayerStatusBar(true);
    loadWaterSound();

    addCreature(new Enemy01(800, 600));
    addCreature(new Enemy01(900, 400));
    addCreature(new Enemy01(500, 300));
    addPlayer(new Player(500, 500, type));
    player->setAttackSpeed(800);
}

void Map::loadAir(string type){
    setPlayerStatusBar(true);
    loadAirSound();

    addCreature(new Enemy01(800, 600));
    addCreature(new Enemy01(900, 400));
    addCreature(new Enemy01(500, 300));
    addPlayer(new Player(500, 500, type));
    player->setAttackSpeed(800);
}

void Map::loadLobby(string type){
    loadLobbySound();
    addPlayer(new Player(500, 500, type));
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
    loadAttackSounds();
    soundsWalk = new Sound("Zvocni efekti/Hoja/HojaPoKamenju.wav");
    soundsBackground = new Sound("Glasba/petaglasba.wav");
    soundsAttack = new Sound("Zvocni efekti/Napad/Psihokineza.wav");
    soundsDash = new Sound("Zvocni efekti/Akcije/Dash.wav");
}

void Map::loadWaterSound(){
    loadAttackSounds();
    soundsWalk = new Sound("Zvocni efekti/Hoja/HojaPoMokremPesku.wav");
    soundsBackground = new Sound("Glasba/sedmaglasba.wav");
    soundsAttack = new Sound("Zvocni efekti/Napad/Psihokineza.wav");
    soundsDash = new Sound("Zvocni efekti/Akcije/Dash.wav");
}

void Map::loadYouDiedSound(){
    soundsYouDied = new Sound("Zvocni efekti/Akcije/you_died.wav");
    soundsYouDied->playOnce();
}

void Map::loadAirSound(){
    loadAttackSounds();
    soundsWalk = new Sound("Zvocni efekti/Hoja/HojaPoTravi.wav");
    soundsBackground = new Sound("Glasba/osmaglasba.wav");
    soundsAttack = new Sound("Zvocni efekti/Napad/Psihokineza.wav");
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

void Map::changeType(string t) // spremeni tip skina
{
    player->setType(t);
}

void Map::setPlayerStatusBar(bool status){
    playerStatusBar = status;
}

void Map::action(int &place){
    place = Map::place;
    switch(place){
        case 2:
            logicEarth();
        break;
        case 4:
            logicFire();
            break;
    }
}

void Map::logicEarth(){
    if(waves == 0 && creatures.size() == 1)
        place = 0;

    if(creatures.size() == 1){
        waves--;
        switch(waves){
            default:
                addCreature(new Enemy01(800, 600));
                addCreature(new Enemy01(900, 400));
                addCreature(new Enemy01(500, 300));
                break;
        }
    }
}

void Map::logicFire(){
    if(waves == 0 && creatures.size() == 1)
        place = 0;

    if(creatures.size() == 1){
        waves--;
        switch(waves){
            default:
                addCreature(new Enemy02(100, 200));
                addCreature(new Enemy01(200, 200));
                addCreature(new Enemy02(300, 200));
                addCreature(new Enemy01(400, 200));
                addCreature(new Enemy02(500, 200));
                addCreature(new Enemy01(600, 200));
                break;
        }
    }
}

void Map::setPlace(int place){
    Map::place = place;
}

void Map::addPlayerHP()
{

    player->addHP();
}
