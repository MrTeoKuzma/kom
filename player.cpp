#include "player.h"
#include "creature.h"

Player::Player(int x, int y){
    Player::x = x;
    Player::y = y;
    Player::width = 128;
    Player::height = 128;
    Player::step = 5;
    loadImg();
    skills[DASH].setCooldown(1000);
    skills[DASH].data[0] = 200; //dashLength
    skills[DASH].data[1] = 10; //dashStep
    skills[DASH].data[2] = 0; //current
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

void Player::move(int dir){
    if(state == NORMAL){
        direction = dir;
        x += X_DIFF(step, dir);
        y += Y_DIFF(step, dir);
    }
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

void Player::attack(int mX, int mY){
    turn(mX, mY);    
}

void Player::action(Map *map){
    Creature::action(map);
    if(state == DASHING){
        if(skills[DASH].data[2] > skills[DASH].data[0]){
            state = NORMAL;
            skills[DASH].data[2] = 0;
        }else{
            skills[DASH].data[2] += skills[DASH].data[1];
            x += X_DIFF(skills[DASH].data[1], direction);
            y += Y_DIFF(skills[DASH].data[1], direction);
        }
    }
}
