#ifndef PROJECTILE_H_
#define PROJECTILE_H_
#include <SFML/Graphics.hpp>
#include "map.h"
#include "animation.h"

#define PLAYER 0
#define ENEMY 1

class Map;
class Projectile{
    private:

        int dmg;
        int mpCost; // koliko skill ponuca mp
        double radius;
        double stepX;
        double k;
        double x;
        double y;
        double pX;
        double pY;
        double speed;
        int left;
        int top;
        sf::IntRect hitbox;
        string type;
        int target;
        sf::Texture *sprite;
        Animation * animation;

    public:
        Projectile(int dmg, double x, double y, double mX, double mY, double speed, string type, int target);
        void draw(sf::RenderWindow * window);
        void action(Map *map);
        void loadImg();
        sf::IntRect * getHitbox();
        int getDmg();
        int getTarget();

};

#endif
