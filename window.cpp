#include "window.h"

Window::Window():title("Kind of magic"), width(1408), height(792){
    window = new sf::RenderWindow(sf::VideoMode(width, height), title);
    window->setFramerateLimit(60);
}

void Window::handleEvents(){
    while (window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window->close();
        if (event.type == sf::Event::MouseMoved)
            map->setPlayerMouseCoord(sf::Mouse::getPosition(*window));
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
        //left
    }
    if (sf::Mouse::isButtonPressed(sf::Mouse::Right)){
        //right
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
}

void Window::startGame(){
    while (window->isOpen()){
        window->clear(sf::Color::Black);
        handleEvents();
        map->draw(window);
        window->display();
    }
}

void Window::loadMapImg(string image){
    map = new Map(image);
}

Map * Window::getMap(){
    return map;
}
