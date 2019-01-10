#include "map.h"
#include "creature.h"
#include "player.h"
#include "enemy01.h"
#include "projectile.h"
#include <algorithm>
#include <SFML/Audio.hpp>

Map::Map(): x(0), y(0){
	loadSound();
}

void Map::draw(sf::RenderWindow *window){
    window->draw(background);
    unsigned int i;
    for(i = 0; i < creatures.size(); i++){
        (creatures[i])->action(this);
        (creatures[i])->draw(window);
    }

    for(i = 0; i < projectiles.size(); i++){
        (projectiles[i])->draw(window);
        (projectiles[i])->action(this);
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

void Map::movePlayer(int dir){
	playSound(HOJAPOTRAVISOUND);
    player->move(dir, level);
}

void Map::dashPlayer(){
    player->dash();
}

void Map::doAttackPlayer(int mX, int mY){
    player->attack(this, mX, mY);
}

void Map::loadLevel(string fileName, int dotDmg){
    level = new Level(fileName, dotDmg);
}

void Map::loadBackground(string bgImage){
    image.loadFromFile(bgImage);
    background.setTexture(image, true);
}

void Map::loadEarth(){
    addPlayer(new Player(500, 500, "earth"));
    addCreature(new Enemy01(800, 600));
}

Level * Map::getLevel(){
    return level;
}

Player * Map::getPlayer(){
    return player;
}
void Map::loadSound() {
    buffer[DASHSOUND].loadFromFile("Zvocni efekti/Akcije/Dash.wav");
    buffer[KUPLJENOSHOPSOUND].loadFromFile("Zvocni efekti/Akcije/Kupljeno_shop.wav");
    buffer[POBIRANJECOINOVSOUND].loadFromFile("Zvocni efekti/Akcije/Pobiranje_coinov.wav");
    buffer[HOJAPOTRAVISOUND].loadFromFile("Zvocni efekti/Hoja/HojaPoTravi.wav");
    buffer[HOJAPOMOKREMPESKUSOUND].loadFromFile("Zvocni efekti/Hoja/HojaPoMokremPesku.wav");
    buffer[HOJAPOKAMENJUSOUND].loadFromFile("Zvocni efekti/Hoja/HojaPoKamenju.wav");
    buffer[LEDSOUND].loadFromFile("Zvocni efekti/Napad/Led.wav");
    buffer[NALAGANJESTRELESOUND].loadFromFile("Zvocni efekti/Napad/Nalaganje strele.wav");
    buffer[NEVIHTASOUND].loadFromFile("Zvocni efekti/Napad/Nevihta.wav");
    buffer[OGENJSOUND].loadFromFile("Zvocni efekti/Napad/Ogenj.wav");
    buffer[PSIHOKINEZASOUND].loadFromFile("Zvocni efekti/Napad/Psihokineza.wav");
    buffer[TEMASOUND].loadFromFile("Zvocni efekti/Napad/Tema.wav");
    buffer[UDARSTRELESOUND].loadFromFile("Zvocni efekti/Napad/Udar_strele.wav");
    buffer[VETERSOUND].loadFromFile("Zvocni efekti/Napad/Veter.wav");
    buffer[VODASOUND].loadFromFile("Zvocni efekti/Napad/Voda.wav");
    buffer[PREJEMUDARCASOUND].loadFromFile("Zvocni efekti/Prejem_udarca/Prejem_udarca.wav");
    buffer[PRIKAZNASPROTNIKA01SOUND].loadFromFile("Zvocni efekti/Prikaz nasprotnika/Prikaz_nasprotnika001.wav");
    buffer[PRIKAZNASPROTNIKA02SOUND].loadFromFile("Zvocni efekti/Prikaz nasprotnika/Prikaz_nasprotnika002.wav");
    buffer[PRIKAZNASPROTNIKA03SOUND].loadFromFile("Zvocni efekti/Prikaz nasprotnika/Prikaz_nasprotnika003.wav");
    buffer[PRIKAZNASPROTNIKA04SOUND].loadFromFile("Zvocni efekti/Prikaz nasprotnika/Prikaz_nasprotnika004.wav");
    buffer[PRIKAZNASPROTNIKA05SOUND].loadFromFile("Zvocni efekti/Prikaz nasprotnika/Prikaz_nasprotnika005.wav");
    buffer[PRIKAZNASPROTNIKA06SOUND].loadFromFile("Zvocni efekti/Prikaz nasprotnika/Prikaz_nasprotnika006.wav");
    buffer[PRIKAZNASPROTNIKA07SOUND].loadFromFile("Zvocni efekti/Prikaz nasprotnika/Prikaz_nasprotnika007.wav");
    buffer[PRIKAZNASPROTNIKA08SOUND].loadFromFile("Zvocni efekti/Prikaz nasprotnika/Prikaz_nasprotnika008.wav");
    //sound.setBuffer(buffer[DASHSOUND]);
}

void Map::playSound(int i){
    sf::Sound *tmp = new sf::Sound();
    tmp->setBuffer(buffer[i]);
    tmp->play();
}
