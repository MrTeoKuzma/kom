#include "enemy01.h"
#include "creature.h"
#include "skill.h"
#include "player.h"

Enemy01::Enemy01(int x, int y){
    Enemy01::direction = RIGHT;
    Enemy01::x = x;
    Enemy01::y = y;
    Enemy01::width = 128;
    Enemy01::height = 128;
    Enemy01::step = 4;
    Enemy01::startX = x;
    Enemy01::endX = x+100;
    loadImg();
}

void Enemy01::loadImg(){
    sf::IntRect firstOnly(128, 0, 128, 128);
    sprite[UP][NORMAL][NOTHING][0].loadFromFile("img/enemy/schooler/mv/front.png", firstOnly);
    sprite[RIGHT][NORMAL][NOTHING][0].loadFromFile("img/enemy/schooler/mv/right.png", firstOnly);
    sprite[DOWN][NORMAL][NOTHING][0].loadFromFile("img/enemy/schooler/mv/back.png", firstOnly);
    sprite[LEFT][NORMAL][NOTHING][0].loadFromFile("img/enemy/schooler/mv/left.png", firstOnly);
 
    sprite[UP][RUNNING][NOTHING][0].loadFromFile("img/enemy/schooler/mv/front.png");
    sprite[RIGHT][RUNNING][NOTHING][0].loadFromFile("img/enemy/schooler/mv/right.png");
    sprite[DOWN][RUNNING][NOTHING][0].loadFromFile("img/enemy/schooler/mv/back.png");
    sprite[LEFT][RUNNING][NOTHING][0].loadFromFile("img/enemy/schooler/mv/left.png");
    animation = new Animation(200);
}

void Enemy01::attack(int mX, int mY){
}

void Enemy01::action(Map *map){
    Creature::action(map);
    if(x > endX || x < startX){
        direction = (direction == RIGHT) ? LEFT: RIGHT; //obrni smer
    }
    //sf::err() se uporabi enako kot cout
    sf::err()<<"("<<map->getPlayer()->getX()<<","<<map->getPlayer()->getY()<<")"; //primer pridobitve koordinat igralca
    move(direction, map->getLevel());
}
