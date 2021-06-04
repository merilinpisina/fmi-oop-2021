#ifndef PLAYER_H
#define PLAYER_H

#include "id.h"
#include <cstring>

class Player {
public:
    Player(std::string name = "Unknown", uint age = 1, uint points = 0);
    void addPoints(const uint points);

    // <<
    void saveInfo(std::string fileName);

private:
    uint age;
    uint points;
    uint id;    
    std::string name;
};



#endif