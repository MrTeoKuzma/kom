#ifndef WINDOW_H_
#define WINDOW_H_
#include <SFML/Graphics.hpp>
#include "map.h"

using namespace std;

class Window{
    private:
        sf::RenderWindow * window;
        sf::Event event;
        string title;
        int width;
        int height;
        Map * map;
    public:
        Window(); 
        void handleEvents();
        void startGame();
        void loadMapImg(string image);
        void loadMapLevel(string fileName, int dotDmg);
        Map * getMap();
};
#endif
