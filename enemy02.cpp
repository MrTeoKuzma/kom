#include "enemy02.h"
#include "creature.h"
#include "skill.h"
#include "player.h"

Enemy02::Enemy02(int x, int y){
    Enemy02::direction = LEFT;
    Enemy02::x = x;
    Enemy02::y = y;
    left = 25;
    top = 4;
    hitbox.width = 76;
    hitbox.height = 116;
    hitbox.left = x + left;
    hitbox.top = y + top;
    Enemy02::width = hitbox.width;;
    Enemy02::height = hitbox.height;
    Enemy02::step = 6;
    Enemy02::startX = x;
    Enemy02::endX = x+100;
    Enemy02::tick=true;
    Enemy02::hp = 110;
    Enemy02::category = ENEMY;

    skills[SHOOT_E].setCooldown(600);
    movement.setCooldown(200);
    loadImg();
}

void Enemy02::loadImg(){
    sf::IntRect firstOnly(128, 0, 128, 128);
    sprite[UP][NORMAL][NOTHING][0].loadFromFile("img/enemy/nejschooler/mv/front.png", firstOnly);
    sprite[RIGHT][NORMAL][NOTHING][0].loadFromFile("img/enemy/nejschooler/mv/right.png", firstOnly);
    sprite[DOWN][NORMAL][NOTHING][0].loadFromFile("img/enemy/nejschooler/mv/back.png", firstOnly);
    sprite[LEFT][NORMAL][NOTHING][0].loadFromFile("img/enemy/nejschooler/mv/left.png", firstOnly);

    sprite[UP][RUNNING][NOTHING][0].loadFromFile("img/enemy/nejschooler/mv/front.png");
    sprite[RIGHT][RUNNING][NOTHING][0].loadFromFile("img/enemy/nejschooler/mv/right.png");
    sprite[DOWN][RUNNING][NOTHING][0].loadFromFile("img/enemy/nejschooler/mv/back.png");
    sprite[LEFT][RUNNING][NOTHING][0].loadFromFile("img/enemy/nejschooler/mv/left.png");
    animation = new Animation(200, top, left, hitbox.width, hitbox.height);
}

void Enemy02::attack(Map * map, int pX, int pY){
    if(skills[SHOOT_E].isReady()){
        setState(ATTACK, 800);
        skills[SHOOT_E].use();
        map->addProjectile(new Projectile(10, x, y, pX, pY, 6, "1lvl/lightning/1lvl_lightning.png", PLAYER));
    }
}

void Enemy02::action(Map *map){
    Creature::action(map);
    int px=map->getPlayer()->getX();
    int py=map->getPlayer()->getY();
    if(movement.isReady())
    {
        if(tick)
        {
            if(px>x)
                direction=RIGHT;
            else if(py> y)
                direction=DOWN;
            tick=false;
        }
        else
        {
            if(px<x)
                direction=LEFT;
            else if(py<y)
                direction=UP;
            tick=true;
        }
        movement.use();
    }
    if(!(abs(px-x)<50 && abs(py-y)<50))
    {
        move(direction, map->getLevel());
        attack(map, map->getPlayer()->getX(), map->getPlayer()->getY());
    }


    //sf::err() se uporabi enako kot cout
    //sf::err()<<"("<<map->getPlayer()->getX()<<","<<map->getPlayer()->getY()<<")"; //primer pridobitve koordinat igralca

}

void Enemy02::die(Map * map){
    map->removeCreature(this);
}
