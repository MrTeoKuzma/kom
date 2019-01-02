#ifndef PROJECTILE_H_
#define PROJECTILE_H_
#include <SFML/Graphics.hpp>
#include "map.h"
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

    public:
        Projectile(double radius, double x, double y, double mX, double mY, double speed);
        void draw(sf::RenderWindow * window);
        void action(Map *map);
};

#endif
