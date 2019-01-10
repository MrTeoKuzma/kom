#include "map.h"
#include "creature.h"
#include "player.h"
#include "enemy01.h"
#include "projectile.h"
#include <algorithm>

Map::Map(string bgImage): x(0), y(0){
    image.loadFromFile(bgImage);
    background.setTexture(image, true);
    addPlayer(new Player(500, 500, "earth"));
    addCreature(new Enemy01(800, 600));
}

void Map::draw(sf::RenderWindow *window){
    window->draw(background);
    unsigned int i;
    for(i = 0; i < creatures.size(); i++){
        (creatures[i])->action(this);
        (creatures[i])->draw(window);
    }

    for(i = 0; i < projectiles.size(); i++){
        (projectiles[i])->action(this);
        (projectiles[i])->draw(window);
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

Level * Map::getLevel(){
    return level;
}

Player * Map::getPlayer(){
    return player;
}
