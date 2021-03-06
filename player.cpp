#include "player.h"
#include "creature.h"
#include "projectile.h"

Player::Player(int x, int y, string type){
    Player::x = x;
    Player::y = y;
    left = 10;
    top = 25;
    hitbox.width = 75;
    hitbox.height = 105;
    hitbox.left = x + left;
    hitbox.top = y + top;
    Player::width = hitbox.width;
    Player::height = hitbox.height;
    Player::step = 5;
    Player::type = type;
    Player::hp = 228;
    Player::mp = 176; // nastavimo mp za playera
    Player::mpMax = 176;
    Player::hpuse=5;
    Player::hpMax=228;
    Player::category = PLAYER;
    loadImg();
    skills[DASH].setCooldown(1000);
    skills[DASH].data[0] = 200; //dashLength
    skills[DASH].data[1] = 10; //dashStep
    skills[DASH].data[2] = 0; //current
    currentSkill = SHOOT;
    skills[SHOOT].setCooldown(500);
    skills[FIRE1].setCooldown(500);
    skills[WATER1].setCooldown(500);
    skills[MPREGEN].setCooldown(1000);
    skills[ADDHP].setCooldown(500);
}

void Player::loadImg(){
    sf::IntRect firstOnly(0, 0, 128, 128);
    sprite[UP][NORMAL][NOTHING][0].loadFromFile("img/character/"+type+"/mv/front.png", firstOnly);
    sprite[RIGHT][NORMAL][NOTHING][0].loadFromFile("img/character/"+type+"/mv/right.png", firstOnly);
    sprite[DOWN][NORMAL][NOTHING][0].loadFromFile("img/character/"+type+"/mv/back.png", firstOnly);
    sprite[LEFT][NORMAL][NOTHING][0].loadFromFile("img/character/"+type+"/mv/left.png", firstOnly);
    sprite[UP][DASHING][NOTHING][0].loadFromFile("img/character/"+type+"/mv/front.png", firstOnly);
    sprite[RIGHT][DASHING][NOTHING][0].loadFromFile("img/character/"+type+"/mv/right.png", firstOnly);
    sprite[DOWN][DASHING][NOTHING][0].loadFromFile("img/character/"+type+"/mv/back.png", firstOnly);
    sprite[LEFT][DASHING][NOTHING][0].loadFromFile("img/character/"+type+"/mv/left.png", firstOnly);
    sprite[UP][RUNNING][NOTHING][0].loadFromFile("img/character/"+type+"/mv/front.png");
    sprite[RIGHT][RUNNING][NOTHING][0].loadFromFile("img/character/"+type+"/mv/right.png");
    sprite[LEFT][RUNNING][NOTHING][0].loadFromFile("img/character/"+type+"/mv/left.png");
    sprite[DOWN][RUNNING][NOTHING][0].loadFromFile("img/character/"+type+"/mv/back.png");
    sprite[UP][ATTACK][NOTHING][0].loadFromFile("img/character/"+type+"/atck/front.png");
    sprite[RIGHT][ATTACK][NOTHING][0].loadFromFile("img/character/"+type+"/atck/right.png");
    sprite[DOWN][ATTACK][NOTHING][0].loadFromFile("img/character/"+type+"/atck/back.png");
    sprite[LEFT][ATTACK][NOTHING][0].loadFromFile("img/character/"+type+"/atck/left.png");

    animation = new Animation(200, left, top, hitbox.width, hitbox.height);
}

int Player::dash(){
    if(skills[DASH].isReady()){
        skills[DASH].use();
        state = DASHING;
        return 1;
    }
    return 0;
}
void Player::addHP()
{
    if(hpuse>0)
        if(skills[ADDHP].isReady()){
            if((hp+25)<hpMax)
                hp=hp+25;
            else
                hp=hpMax;

            skills[ADDHP].use();
            hpuse--;
            }
}
void Player::turn(int mX, int mY){
    int deltaX = mX - x;
    int deltaY = mY - y;
    direction = abs(deltaX) > abs(deltaY) ? (deltaX < 0) * 2 +1 : (deltaY > 0) * 2;
}

int Player::attack(Map * map, int mX, int mY){
    turn(mX, mY);
    if(skills[currentSkill].isReady()){
        setState(ATTACK, 800);
        skills[currentSkill].use();

        switch(currentSkill)
        {
            case SHOOT:

                map->addProjectile(new Projectile(5, x, y, mX, mY, 8, "1lvl/standard/1lvl_standard.png", ENEMY));
                return 1;
                break;

            case FIRE1:
                if (mp - 20 >= 0)
                {
                    mp -= 20;
                    map->addProjectile(new Projectile(10, x, y, mX, mY, 10, "1lvl/fire/1lvl_fire.png", ENEMY));
                    return 1;
                }
                break;



            case WATER1:
                if (mp - 20 >= 0)
                {
                    mp -= 20;
                    map->addProjectile(new Projectile(10, x, y, mX, mY, 10, "1lvl/water/1lvl_water.png", ENEMY));
                    return 1;
                }
                break;
        }
    }
    return 0;
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
    if (skills[MPREGEN].isReady())
    {
        if (mp < mpMax)
        {
            skills[MPREGEN].use();
            mp += 10;
        }

        if (mp >= mpMax) mp = mpMax;
    }
}

int Player::getX(){
    return x;
}

int Player::getY(){
    return y;
}

void Player::setType(string type){
    Player::type = type;
}

void Player::die(Map *map){
    map->setPlace(8);
}

void Player::drawHp(sf::RenderWindow * window){
    sf::RectangleShape rect;
    rect.setSize(sf::Vector2f(hp, 16));
    sf::Color color(142, 0, 0);
    rect.setFillColor(color);
    rect.setPosition(52, 8);
    window->draw(rect);
}

void Player::drawMP(sf::RenderWindow * window){
    sf::RectangleShape rect;
    rect.setSize(sf::Vector2f(mp, 16));
    sf::Color color(0, 34, 165);
    rect.setFillColor(color);
    rect.setPosition(59, 32);
    window->draw(rect);
}

void Player::drawCurrentSkill(sf::RenderWindow * window){
    sf::RectangleShape rect;
    rect.setSize(sf::Vector2f(52, 52));
    sf::Color color(200, 200, 200);
    rect.setFillColor(sf::Color::Transparent);
    rect.setOutlineColor(color);
    rect.setOutlineThickness(4);
    rect.setPosition(508+currentSkill*68, 732);
    window->draw(rect);
}

void Player::setAttackSpeed(int i){
    skills[SHOOT].setCooldown(i);
}

void Player::setSkill(int skill){
    currentSkill = skill;
}

