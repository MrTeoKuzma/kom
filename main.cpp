#include <SFML/Graphics.hpp>
#include "window.h"

using namespace std;

int main()
{
    Window * window = new Window();    
    string mapImg = "img/bg.png";
    window->loadMapImg(mapImg);
    window->loadMapLevel("levels/level01", 60);
    window->startGame();
    return 0;
}
