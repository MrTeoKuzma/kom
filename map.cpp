#include "map.h"
#include "creature.h"
#include "player.h"

Map::Map(std::string bgImage): x(0), y(0){
    image.loadFromFile(bgImage);
    background.setTexture(image, true);
    addPlayer(new Player(500, 500));
}

void Map::draw(sf::RenderWindow *window){
    window->draw(background);
    for(unsigned int i = 0; i < creatures.size(); i++){
        (creatures[i])->action(this);
        (creatures[i])->draw(window);
    }
}

void Map::addCreature(Creature *creature){
    creatures.push_back(creature);
}

void Map::addPlayer(Player *player){
    Map::player = player;
    addCreature(player);
}

void Map::movePlayer(int dir){
    player->move(dir);
}

void Map::dashPlayer(){
    player->dash();
}

void Map::doAttackPlayer(int mX, int mY){
    player->attack(mX, mY);
}
