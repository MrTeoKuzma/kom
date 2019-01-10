#ifndef WINDOW_H_
#define WINDOW_H_
#include <SFML/Graphics.hpp>
#include "map.h"

#define TITLE "Kind of Magic"
#define WINWIDTH 1408
#define WINHEIGHT 792

#define LOBBY 0
#define WARDROBE 1
#define EARTH 2
#define AIR 3
#define LAVA 4
#define WATER 5
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
        int PlayerType;

    public:
        Window(int place);
        void handleEvents();
        void handleEventsWardrobe();
        void handleEventsLobby();
        void startGame();
        void startWardrobe();
        void startLobby();
        void loadMapImg(string image);
        void loadMapLevel(string fileName, int dotDmg);
        Map * getMap();
        void changePlace(int place);
        int getPlayerType();
        void setPlayerType(int t);
};
#endif
