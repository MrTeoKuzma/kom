#include "window.h"

Window::Window():title("Kind of magic"), width(1200), height(768){
    window = new sf::RenderWindow(sf::VideoMode(width, height), title);
    window->setFramerateLimit(60);
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
    map = new Map(image, window->getView());
}

Map * Window::getMap(){
    return map;
}
