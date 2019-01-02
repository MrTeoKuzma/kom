#ifndef WINDOW_H_
#define WINDOW_H_
#include <SFML/Graphics.hpp>
#include "map.h"

#define TITLE "Kind of magic"
#define WINWIDTH 1408
#define WINHEIGHT 792

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
