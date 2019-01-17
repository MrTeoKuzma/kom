#include "creature.h"
#include "level.h"
#include "animation.h"

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
    if(animation)
        animation->setSprite(tmp);
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
    if(state == NORMAL || state == RUNNING || state == ATTACK){
        setState(RUNNING, 50);
        direction = dir;
        int tmpStep = step;
        canMove(tmpStep, level);
        x += X_DIFF(tmpStep, dir);
        y += Y_DIFF(tmpStep, dir);
        hitbox.left = x + left;
        hitbox.top = y + top;
    }
}

void Creature::setStatus(int status, int duration){
    statusChange.setCooldown(duration);
    statusChange.use();
    Creature::status = status;
}

void Creature::setState(int state, int duration){
    stateChange.setCooldown(duration);
    stateChange.use();
    Creature::state = state;
}

void Creature::action(Map *map){
    int pY, pX;
    bool isFall = true;

    if(statusChange.isReady()){
        status = NOTHING;
    }

    if(stateChange.isReady() && state != DASHING){
        state = NORMAL;
    }

    for(pY = y/OBSIZE; pY < ((y+height)/OBSIZE); pY++){
        for(pX = x/OBSIZE; pX < ((x+width)/OBSIZE); pX++){
            if(map->getLevel()->obstacles[pY][pX] == HOT){
                setStatus(DOT, 1000);
                pY = (y+height)/OBSIZE+1;
                isFall = false;
                break;
            }

            if(map->getLevel()->obstacles[pY][pX] != FALL){
                isFall = false;
            }
        }
    }
    if(isFall)
        sf::err()<<"Fall\n";

    int dmgDiff = map->isProjectileHit(&hitbox, category);
    if(dmgDiff){
        Creature::hp -= dmgDiff;
    }
    if(hp <= 0){
        die(map);
    }
    sf::err() << hp << "  ;";
}

bool Creature::isHit(sf::IntRect obst){
    return hitbox.intersects(obst);
}
