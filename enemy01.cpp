#include "enemy01.h"
#include "creature.h"
#include "skill.h"
#include "player.h"


Enemy01::Enemy01(int x, int y){
    Enemy01::direction = LEFT;
    Enemy01::x = x;
    Enemy01::y = y;
    left = 25;
    top = 4;
    hitbox.width = 76;
    hitbox.height = 116;
    hitbox.left = x + left;
    hitbox.top = y + top;
    Enemy01::width = hitbox.width;;
    Enemy01::height = hitbox.height;
    Enemy01::step = 4;
    Enemy01::startX = x;
    Enemy01::endX = x+100;
    Enemy01::tick=true;
    Enemy01::hp = 100;
    Enemy01::category = ENEMY;

    skills[SHOOT_E].setCooldown(3000);
    movement.setCooldown(300);
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


    sprite[UP][ATTACK][NOTHING][0].loadFromFile("img/enemy/schooler/atck/front.png");
    sprite[RIGHT][ATTACK][NOTHING][0].loadFromFile("img/enemy/schooler/atck/right.png");
    sprite[DOWN][ATTACK][NOTHING][0].loadFromFile("img/enemy/schooler/atck/back.png");
    sprite[LEFT][ATTACK][NOTHING][0].loadFromFile("img/enemy/schooler/atck/left.png");
    animation = new Animation(200, top, left, hitbox.width, hitbox.height);
}

void Enemy01::attack(Map * map, int pX, int pY){
    if(skills[SHOOT_E].isReady()){
        setState(ATTACK, 800);
        skills[SHOOT_E].use();
        map->addProjectile(new Projectile(10, x, y, pX, pY, 4, "1lvl/storm/1lvl_storm.png", PLAYER));
    }
}

void Enemy01::action(Map *map){
    Creature::action(map);
    sf::err()<<state<<endl;
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
    if(!(abs(px-x)<200 && abs(py-y)<200))
        move(direction, map->getLevel());
    //else
        //setState(NORMAL, 50);
    attack(map, map->getPlayer()->getX(), map->getPlayer()->getY());
    //sf::err() se uporabi enako kot cout
    //sf::err()<<"("<<map->getPlayer()->getX()<<","<<map->getPlayer()->getY()<<")"; //primer pridobitve koordinat igralca
}

void Enemy01::die(Map * map){
    map->removeCreature(this);
}
