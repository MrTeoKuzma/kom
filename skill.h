#ifndef SKILL_H_
#define SKILL_H_
#include <SFML/System.hpp>

class Skill{
    private:
        int ready;
        int cooldown;
        sf::Clock clock;

    public:
        int data[4];

    public:

        Skill();
        void setCooldown(int cooldown);
        bool isReady();
        void use();
};
#endif
