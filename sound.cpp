#include "sound.h"

Sound::Sound(string filename){
    buffer = new sf::SoundBuffer();
    buffer->loadFromFile(filename);
    sound = new sf::Sound();
    sound->setBuffer(*buffer);
    soundTimer.setCooldown(buffer->getDuration().asMilliseconds());
}

void Sound::play(){
    if(soundTimer.isReady()){
        soundTimer.use();
        sound->play();
        sound->setVolume(100);
    }
}

void Sound::playOnce(){
    sound->play();
    sound->setVolume(100);
}

void Sound::stop(){
    sound->stop();
    soundTimer.setCooldown(-1);
}

void Sound::pause(){
    sound->setVolume(0);
}
void Sound::resume(){
    sound->setVolume(100);
}

