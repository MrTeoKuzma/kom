#include "projectile.h"
#include <iostream>
#include <cmath>
#include "map.h"
#include "window.h"

Projectile::Projectile(int dmg, double x, double y, double mX, double mY, double speed, string type, int target): dmg(dmg), x(x), y(y), pX(x), pY(y), speed(speed), type(type), target(target){
    left = 52;
    top = 52;
    hitbox.width = 20;
    hitbox.height = 20;
    if(mX > x){
        k =  (mY - y) / (mX - x);
        stepX = speed;
    }

    if(x > mX){
        k = (y - mY)  / (x - mX) *-1;
        stepX = -speed;
    }

    if(x == mX){
        stepX = 0;
        k = y > mX ? -1 : 1;
    }
    loadImg();
}

void Projectile::draw(sf::RenderWindow * window){
    sf::Sprite tmp(*sprite);
    tmp.setPosition(x, y);
    if(animation)
        animation->setSprite(tmp);
    window->draw(tmp);
}

void Projectile::action(Map *map){
    x += stepX / (sqrt(1+k*k));
    y = stepX ? k*abs(x-pX)+pY : y + k;

    hitbox.left = x + left;
    hitbox.top = y + top;

    if(x < 0 || x > WINWIDTH || y < 0 || y > WINHEIGHT)
        map->removeProjectile(this);
}

void Projectile::loadImg(){
    sprite = new sf::Texture();
    sprite->loadFromFile("img/skill/"+type);
    animation = new Animation(200);
}

sf::IntRect * Projectile::getHitbox(){
    return &hitbox;
}

int Projectile::getDmg(){
    return dmg;
}

int Projectile::getTarget(){
    return target;
}

