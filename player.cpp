#include "player.h"
#include "creature.h"

Player::Player(sf::Vector2f center){
    Player::x = center.x;
    Player::y = center.y;
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

void Player::move(sf::View &view, int dir){
    if(state == NORMAL){
        direction = dir;

        view.move(Y_DIFF(step, dir), X_DIFF(step, dir));
        sf::Vector2f center = view.getCenter();
        x = center.x;
        y = center.y;
    }
}

void Player::dash(sf::View &view){
    if(skills[DASH].isReady()){
        skills[DASH].use();
        state = DASHING;
        setStatus(INVUNERABLE, 1000);
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
            sf::View view = map->getView();
            view.move(Y_DIFF(skills[DASH].data[1], direction), X_DIFF(skills[DASH].data[1], direction));
            sf::Vector2f center = view.getCenter();
            map->setView(view);
            x = center.x;
            y = center.y;
        }
    }
}
