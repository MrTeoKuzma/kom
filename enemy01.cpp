#include "enemy01.h"
#include "creature.h"

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
    sprite[UP][NORMAL][NORMAL][0].loadFromFile("img/cU.png");
    sprite[RIGHT][NORMAL][NOTHING][0].loadFromFile("img/cR.png");
    sprite[DOWN][NORMAL][NOTHING][0].loadFromFile("img/cD.png");
    sprite[LEFT][NORMAL][NOTHING][0].loadFromFile("img/cL.png");
    sprite[UP][DASHING][NOTHING][0].loadFromFile("img/cU.png");
    sprite[RIGHT][DASHING][NOTHING][0].loadFromFile("img/cR.png");
    sprite[DOWN][DASHING][NOTHING][0].loadFromFile("img/cD.png");
    sprite[LEFT][DASHING][NOTHING][0].loadFromFile("img/cL.png");

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
