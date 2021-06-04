#ifndef UNIQUE_ID
#define UNIQUE_ID

#include <iostream>
#include <fstream>
#include <sstream>
#include <exception>

using uint = unsigned int;

namespace data {
    static uint id = 0;
    void initialize();
    uint getAndIncrease();
    void save();
}

//const char* dataFile = "id.dat";
const uint ADMIN_ID = INT16_MAX;

#endif