#include "skill.h"

Skill::Skill(): ready(-1){
}

void Skill::setCooldown(int cooldown){
    Skill::cooldown = cooldown;
}

bool Skill::isReady(){
    ready = (clock.getElapsedTime().asMilliseconds() >= cooldown || ready == -1);
    return ready;
} 

void Skill::use(){
    clock.restart();
    ready = false;
}
