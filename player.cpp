#include "player.h"
#include "creature.h"
#include "projectile.h"

Player::Player(int x, int y){
    Player::x = x;
    Player::y = y;
    Player::width = 128;
    Player::height = 128;
    Player::step = 4;
    loadImg();
    skills[DASH].setCooldown(1000);
    skills[DASH].data[0] = 200; //dashLength
    skills[DASH].data[1] = 10; //dashStep
    skills[DASH].data[2] = 0; //current

    skills[SHOOT].setCooldown(500);
}

void Player::loadImg(){
    sprite[UP][NORMAL][NORMAL][0].loadFromFile("img/cU.png");
    sprite[RIGHT][NORMAL][NOTHING][0].loadFromFile("img/cR.png");
    sprite[DOWN][NORMAL][NOTHING][0].loadFromFile("img/cD.png");
    sprite[LEFT][NORMAL][NOTHING][0].loadFromFile("img/cL.png");
    sprite[UP][DASHING][NOTHING][0].loadFromFile("img/cU.png");
    sprite[RIGHT][DASHING][NOTHING][0].loadFromFile("img/cR.png");
    sprite[DOWN][DASHING][NOTHING][0].loadFromFile("img/cD.png");
    sprite[LEFT][DASHING][NOTHING][0].loadFromFile("img/cL.png");

}

void Player::dash(){
    if(skills[DASH].isReady()){
        skills[DASH].use();
        state = DASHING;
    }
}

void Player::turn(int mX, int mY){
    int deltaX = mX - x;
    int deltaY = mY - y;
    direction = abs(deltaX) > abs(deltaY) ? (deltaX < 0) * 2 +1 : (deltaY > 0) * 2;
}

void Player::attack(Map * map, int mX, int mY){
    turn(mX, mY);
    if(skills[SHOOT].isReady()){
        skills[SHOOT].use();
        map->addProjectile(new Projectile(10, x, y, mX, mY, 8));
    }
}

void Player::action(Map *map){
    Creature::action(map);
    if(state == DASHING){
        if(skills[DASH].data[2] > skills[DASH].data[0]){
            state = NORMAL;
            skills[DASH].data[2] = 0;
        }else{
            skills[DASH].data[2] += skills[DASH].data[1];
            int tmpStep = skills[DASH].data[1];
            canMove(tmpStep, map->getLevel());
            x += X_DIFF(tmpStep, direction);
            y += Y_DIFF(tmpStep, direction);
        }
    }
}

int Player::getX(){
    return x;
}

int Player::getY(){
    return y;
}
