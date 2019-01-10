#ifndef SOUND_H_
#define SOUND_H_
#include "skill.h"
#include <SFML/Audio.hpp>
#include <string>

using namespace std;

class Sound{
    private:
        sf::SoundBuffer buffer;
        sf::Sound sound;
        Skill soundTimer;
        
    public:
        Sound(string filename);
        void play();
};

#endif
