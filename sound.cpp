#include "sound.h"

Sound::Sound(string filename){
    buffer.loadFromFile(filename);
    sound.setBuffer(buffer);
    soundTimer.setCooldown(buffer.getDuration().asMilliseconds());
}

void Sound::play(){
    if(soundTimer.isReady()){
        soundTimer.use();
        sound.play();
    }
}
