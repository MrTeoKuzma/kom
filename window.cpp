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

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::I)){
        changePlace(WARDROBE);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)){
            map->changeType(1);
        //skill 1
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)){
        map->changeType(2);
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

        //right
    }
}
void Window::handleEventsLobby(){
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

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::I)){
        changePlace(WARDROBE);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)){
            map->changeType(1);
        //skill 1
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)){
        map->changeType(2);
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

        //right
    }
}
void Window::handleEventsWardrobe(){
    while (window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window->close();
    }
    //IZHOD IZ MENIJA
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
        changePlace(LOBBY);
    }

    //ZA DEJANSKE OBLEKE
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        sf::Vector2i pos = sf::Mouse::getPosition(*((sf::Window*)window));
        //sf::err()<<"X: "<<pos.x<<" Y: "<<pos.y<<"\n";
        if(pos.x>321 && pos.x<449 && pos.y>169 && pos.y<297)
            PlayerType=1;
        if(pos.x>467 && pos.x<599 && pos.y>169 && pos.y<297)
            PlayerType=2;
        if(pos.x>617 && pos.x<746 && pos.y>169 && pos.y<297)
            PlayerType=3;
        if(pos.x>766 && pos.x<893 && pos.y>169 && pos.y<297)
            PlayerType=4;

        if(pos.x>321 && pos.x<449 && pos.y>316 && pos.y<446)
            PlayerType=5;
        if(pos.x>467 && pos.x<599 && pos.y>316 && pos.y<446)
            PlayerType=6;
        if(pos.x>617 && pos.x<746 && pos.y>316 && pos.y<446)
            PlayerType=7;
        if(pos.x>766 && pos.x<893 && pos.y>316 && pos.y<446)
            PlayerType=8;
        if(pos.x>912 && pos.x<1043 && pos.y>316 && pos.y<446)
            PlayerType=0;

        if(pos.x>321 && pos.x<449 && pos.y>464 && pos.y<594)
            PlayerType=9;
        if(pos.x>467 && pos.x<599 && pos.y>464 && pos.y<594)
            PlayerType=10;
        if(pos.x>617 && pos.x<746 && pos.y>464 && pos.y<594)
            PlayerType=11;
        if(pos.x>766 && pos.x<893 && pos.y>464 && pos.y<594)
            PlayerType=12;
        if(pos.x>1170 && pos.x<1320 && pos.y>640 && pos.y<702)
            changePlace(LOBBY);

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

void Window::startLobby(){
    while (window->isOpen()){
        window->clear(sf::Color::Black);
        handleEventsLobby();
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
int Window::getPlayerType()
{
    return PlayerType;
}
void Window::setPlayerType(int t)
{
    PlayerType=t;
}
void Window::changePlace(int place){

    switch(place){
        case LOBBY:
            map=new Map();
            map->loadBackground("img/arena/lobby.png");
            loadMapLevel("levels/level01", 60);
            map->loadLobby();
            map->changeType(PlayerType);
            startLobby();
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
