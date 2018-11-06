#include "creature.h"

Creature::Creature(){
    init();
}

Creature::Creature(int x, int y): x(x), y(y){
    init();
}

void Creature::init(){
    direction = DOWN;
    state = NORMAL;
    status = NOTHING;
    spriteI = 0;
}

void Creature::draw(sf::RenderWindow *window){
    sf::Sprite tmp(sprite[direction][state][status][spriteI]);
    tmp.setPosition(x, y);
    window->draw(tmp);
}

void Creature::setStatus(int status, int duration){
    statusChange.setCooldown(duration);
    statusChange.use();
    Creature::status = status;
}

void Creature::action(Map *map){
    if(statusChange.isReady()){
        status = NORMAL;
    }
}
