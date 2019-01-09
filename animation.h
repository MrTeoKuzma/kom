#ifndef ANIMATION_H_
#define ANIMATION_H_

#include <SFML/Graphics.hpp>
#include "skill.h"

class Animation{
    private:
        Skill animation;
        sf::IntRect currentSprite;
        int spriteLeft;

    public:
        Animation(int spriteTime);
        void setSprite(sf::Sprite &sprite);
};
#endif
