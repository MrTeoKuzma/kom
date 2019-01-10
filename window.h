#ifndef WINDOW_H_
#define WINDOW_H_
#include <SFML/Graphics.hpp>
#include "map.h"

#define TITLE "Kind of magic"
#define WINWIDTH 1408
#define WINHEIGHT 792

#define LOBY 0
#define WARDROBE 1
#define EARTH 2
using namespace std;

class Window{
    private:
        sf::RenderWindow * window;
        sf::Event event;
        string title;
        int width;
        int height;
        Map * map;
        int place;

    public:
        Window(int place);
        void handleEvents();
        void handleEventsWardrobe();
        void startGame();
        void startWardrobe();
        void loadMapImg(string image);
        void loadMapLevel(string fileName, int dotDmg);
        Map * getMap();
        void changePlace(int place);
};
#endif
