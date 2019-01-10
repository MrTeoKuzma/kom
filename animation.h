#ifndef ANIMATION_H_
#define ANIMATION_H_

#include <SFML/Graphics.hpp>
#include "skill.h"

class Animation{
    private:
        Skill animation;
        sf::IntRect currentSprite;
        int spriteLeft;
        int padding[4];

    public:
        Animation(int spriteTime);
        Animation(int spriteTime, int top, int left, int width, int height);
        void init(int spriteTime);
        void setSprite(sf::Sprite &sprite);
};
#endif
