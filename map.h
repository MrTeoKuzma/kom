#ifndef MAP_H_
#define MAP_H_
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "creature.h"

class Creature;
class Player;

class Map{
    private:
        sf::Texture image;
        sf::Sprite background;
        sf::View view;
        std::vector <Creature *> creatures;
        Player *player;
        int x;
        int y;

    public:
        Map(std::string bgImage, sf::View view); 
        void move(int stepX, int stepY);
        void draw(sf::RenderWindow *window);
        void addCreature(Creature *creature);
        void addPlayer(Player *player);
        void movePlayer(int dir);
        void dashPlayer();
        sf::View getView();
        void setView(sf::View view);
};
#endif
