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

    int px=map->getPlayer()->getX();
    int py=map->getPlayer()->getY();

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

    if(px<571 && px>99 && py<390 && py>342 && sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
        changePlace(ARENASELECT);
    }
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){

    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::I)){
        changePlace(WARDROBE);
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

void Window::handleEventsArenaSelect(){
    while (window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window->close();
    }
    //IZHOD IZ MENIJA
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
        changePlace(LOBBY);
    }

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        sf::Vector2i pos = sf::Mouse::getPosition(*((sf::Window*)window));
        sf::err()<<"X: "<<pos.x<<" Y: "<<pos.y<<"\n";
        if(pos.x>152 && pos.x<373 && pos.y>184 && pos.y<484)
            changePlace(EARTH);

        if(pos.x>424 && pos.x<637 && pos.y>192 && pos.y<484)
            changePlace(FIRE);

        if(pos.x>701 && pos.x<920 && pos.y>192 && pos.y<484)
            changePlace(WATER);

        if(pos.x>982 && pos.x<1199 && pos.y>192 && pos.y<484)
            changePlace(AIR);

        if(pos.x>1037 && pos.x<1184 && pos.y>720 && pos.y<782)
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
        map->action(newplace);
        window->display();
        checkNewplace();
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

void Window::startArenaSelect(){
    while (window->isOpen()){
        window->clear(sf::Color::Black);
        handleEventsArenaSelect();
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

void Window::checkNewplace(){
    if(place != newplace){
        changePlace(newplace);
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
    Window::newplace = place;
    Window::place = place;
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
        case ARENASELECT:
            map=new Map();
            map->loadBackground("img/bg/arenaselect.png");
            startArenaSelect();
            break;
        case EARTH:
            map = new Map();
            map->loadBackground("img/arena/earth_BG.png");
            map->loadForeground("img/arena/earth_FG.png");
            loadMapLevel("levels/level01", 60);
            map->loadEarth();
            map->changeType(PlayerType);
            map->setPlace(EARTH);
            startGame();
            break;
        case FIRE:
            map = new Map();
            map->loadBackground("img/arena/lav_BG.png");
            loadMapLevel("levels/level01", 60);
            map->loadFire();
            map->changeType(PlayerType);
            map->setPlace(FIRE);
            startGame();
            break;
        case WATER:
            map = new Map();
            map->loadBackground("img/arena/water_BG.png");
            map->loadForeground("img/arena/water_FG.png");
            loadMapLevel("levels/level01", 60);
            map->loadEarth();
            map->changeType(PlayerType);
            map->setPlace(WATER);
            startGame();
            break;
        case AIR:
            map = new Map();
            map->loadBackground("img/arena/air_BG.png");
            map->loadForeground("img/arena/air_FG.png");
            loadMapLevel("levels/level01", 60);
            map->loadEarth();
            map->changeType(PlayerType);
            map->setPlace(AIR);
            startGame();
            break;
    }
}
