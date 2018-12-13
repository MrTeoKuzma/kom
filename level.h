#ifndef LEVEL_H_
#define LEVEL_H_
#include <string>
#include <fstream>
#define OBSIZE 8

#define WALL '#'
#define EMPTY '_'
#define HOT 'x'
#define FALL '.'

using namespace std;
class Level{
    public:    
        char obstacles[101][178];
    private:
        int dotDmg;

    public:
        Level(string fileName, int dotDmg);
        void readFile(string fileName);
        int getDotDmg();
};
#endif
