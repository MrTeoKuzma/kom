#include "level.h"

Level::Level(string fileName, int dotDmg): dotDmg(dotDmg){
    readFile(fileName);
}

void Level::readFile(string fileName){
    ifstream file(fileName);
    int i = 0;
    string line;
    if(file.is_open()){
        while(getline(file, line)){
            line.copy(obstacles[i++], 178);
        }
    }
    file.close();
}
