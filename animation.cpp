#include "animation.h"

Animation::Animation(int spriteTime){
    spriteLeft = 0;
    animation.setCooldown(spriteTime);
    currentSprite.top = 0;
}

void Animation::setSprite(sf::Sprite &sprite){

    sf::Vector2u v = sprite.getTexture()->getSize();
    if(v.x && v.y){
        if(animation.isReady()){
            animation.use();
            spriteLeft += v.x/(v.x/v.y);
        }
        currentSprite.left = spriteLeft%v.x;
        currentSprite.width = v.x/(v.x/v.y);
        currentSprite.height = v.y;
        sprite.setTextureRect(currentSprite);
    }
}
