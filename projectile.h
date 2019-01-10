#ifndef PROJECTILE_H_
#define PROJECTILE_H_
#include <SFML/Graphics.hpp>
#include "map.h"
#include "animation.h"

class Map;
class Projectile{
    private:
        double radius;
        double stepX;
        double k;
        double x;
        double y;
        double pX;
        double pY;
        double speed;
        string type;
        sf::Texture *sprite;
        Animation * animation;

    public:
        Projectile(double radius, double x, double y, double mX, double mY, double speed, string type);
        void draw(sf::RenderWindow * window);
        void action(Map *map);
        void loadImg();
};

#endif
