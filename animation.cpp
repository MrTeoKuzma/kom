#include "animation.h"

Animation::Animation(int spriteTime){
    init(spriteTime);
}

Animation::Animation(int spriteTime, int top, int left, int width, int height){
    init(spriteTime);
    padding[0] = top;
    padding[1] = width;
    padding[2] = height;
    padding[3] = left;
}

void Animation::init(int spriteTime){
    spriteLeft = 0;
    animation.setCooldown(spriteTime);
    padding[0] = 0;
    padding[1] = 0;
    padding[2] = 0;
    padding[3] = 0;
}

void Animation::setSprite(sf::Sprite &sprite){

    sf::Vector2u v = sprite.getTexture()->getSize();
    if(v.x && v.y){
        if(animation.isReady()){
            animation.use();
            spriteLeft += v.x/(v.x/v.y);
        }
        currentSprite.top = padding[0];
        currentSprite.left = (spriteLeft%v.x) + padding[3];
        currentSprite.width =  padding[1] ?: (v.x/(v.x/v.y));
        currentSprite.height = padding[2] ?: v.y;
        sprite.setTextureRect(currentSprite);
    }
}
