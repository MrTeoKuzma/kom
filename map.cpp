#include "map.h"
#include "creature.h"
#include "player.h"

Map::Map(std::string bgImage, sf::View view): x(0), y(0){
    image.loadFromFile(bgImage);
    background.setTexture(image, true);
    Map::view = view;
    addPlayer(new Player(view.getCenter()));
}

void Map::move(int stepX, int stepY){
    x += stepX;
    y += stepY;
    background.move(x, y);
}

void Map::draw(sf::RenderWindow *window){

    window->setView(view);
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
    player->move(view, dir);
}

void Map::dashPlayer(){
    player->dash(view);
}

sf::View Map::getView(){
    return view;
}

void Map::setView(sf::View view){
    Map::view = view;
}
