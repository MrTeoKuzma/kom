#include "window.h"

Window::Window(int place):title(TITLE), width(WINWIDTH), height(WINHEIGHT), place(place){
    window = new sf::RenderWindow(sf::VideoMode(width, height), title);
    window->setFramerateLimit(60);
    changePlace(place);
}

void Window::handleEvents(){
    while (window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window->close();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        map->movePlayer(LEFT);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        map->movePlayer(RIGHT);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
        map->movePlayer(UP);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        map->movePlayer(DOWN);
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
        map->dashPlayer();
    }

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        sf::Vector2i pos = sf::Mouse::getPosition(*((sf::Window*)window));
        map->doAttackPlayer(pos.x, pos.y);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)){
        //skill 1
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)){
        //skill 2
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)){
        //skill 3
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)){
        //skill 4
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)){
        //skill 5
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)){
        //skill 6
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)){
        //skill 7
    }
    
    if (sf::Mouse::isButtonPressed(sf::Mouse::Right)){
        changePlace(WARDROBE);
        //right
    }
}

void Window::handleEventsWardrobe(){
    while (window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window->close();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
        changePlace(EARTH);
    }

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        sf::Vector2i pos = sf::Mouse::getPosition(*((sf::Window*)window));
        sf::err()<<"X: "<<pos.x<<" Y: "<<pos.y<<"\n";
        if(pos.x>321 && pos.x<449 && pos.y>169 && pos.y<297)
            sf::err()<<"FIRE 1\n";
        if(pos.x>467 && pos.x<599 && pos.y>169 && pos.y<297)
            sf::err()<<"WATER 2\n";
        if(pos.x>617 && pos.x<746 && pos.y>169 && pos.y<297)
            sf::err()<<"AIR 3\n";
        if(pos.x>766 && pos.x<893 && pos.y>169 && pos.y<297)
            sf::err()<<"EARTH 4\n";

        if(pos.x>321 && pos.x<449 && pos.y>316 && pos.y<446)
            sf::err()<<"LIGHTNING 5\n";
        if(pos.x>467 && pos.x<599 && pos.y>316 && pos.y<446)
            sf::err()<<"LAVA 6\n";
        if(pos.x>617 && pos.x<746 && pos.y>316 && pos.y<446)
            sf::err()<<"STORM 7\n";
        if(pos.x>766 && pos.x<893 && pos.y>316 && pos.y<446)
            sf::err()<<"ICE 8\n";
        if(pos.x>912 && pos.x<1043 && pos.y>316 && pos.y<446)
            sf::err()<<"STANDARD 0\n";

        if(pos.x>321 && pos.x<449 && pos.y>464 && pos.y<594)
            sf::err()<<"Light 9\n";
        if(pos.x>467 && pos.x<599 && pos.y>464 && pos.y<594)
            sf::err()<<"DARK 10\n";
        if(pos.x>617 && pos.x<746 && pos.y>464 && pos.y<594)
            sf::err()<<"PSI 11\n";
        if(pos.x>766 && pos.x<893 && pos.y>464 && pos.y<594)
            sf::err()<<"VAKUUM 12\n";

    }

    if (sf::Mouse::isButtonPressed(sf::Mouse::Right)){
        //right
    }
}

void Window::startGame(){
    while (window->isOpen()){
        window->clear(sf::Color::Black);
        handleEvents();
        map->draw(window);
        window->display();
    }
}
void Window::startWardrobe(){
    while (window->isOpen()){
        window->clear(sf::Color::Black);
        handleEventsWardrobe();
        map->draw(window);
        window->display();
    }
}

void Window::loadMapImg(string image){
   // map = new Map(image);
}

Map * Window::getMap(){
    return map;
}

void Window::loadMapLevel(string fileName, int dotDmg){
    map->loadLevel(fileName, dotDmg);
}

void Window::changePlace(int place){

    switch(place){
        case LOBY:
            break;

        case WARDROBE:
            map = new Map();
            map->loadBackground("img/bg/wardrobe.png");
            startWardrobe();
            break;

        case EARTH:
            map = new Map();
            map->loadBackground("img/bg.png");
            loadMapLevel("levels/level01", 60);
            map->loadEarth();
            startGame();
            break;
    }
}
