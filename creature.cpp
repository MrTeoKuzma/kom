#include "creature.h"
#include "level.h"

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

void Creature::canMove(int &step, Level * level){
    int oX, oY;
    if(direction == UP || direction == DOWN){
        oX = x/OBSIZE +1;
        oY = (direction == UP ? (y-step) : (y+step+height))/OBSIZE +1;       
        while(oX*OBSIZE <= x+width ){
            if(level->obstacles[oY][oX++] == WALL){
                step = 0;
                break;
            }
        }
    }

    if(direction == RIGHT || direction == LEFT){
        oX = ((direction == LEFT ? (x-step) : (x+step+width))/OBSIZE)+1;
        oY = y/OBSIZE +1;
        while(oY*OBSIZE <= y+height){
            if(level->obstacles[oY++][oX] == WALL){
                step = 0;
                break;
            }
        }
    }
}

void Creature::move(int dir, Level * level){
    if(state == NORMAL){
        direction = dir;
        int tmpStep = step;
        canMove(tmpStep, level);
        x += X_DIFF(tmpStep, dir);
        y += Y_DIFF(tmpStep, dir);
    }
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
