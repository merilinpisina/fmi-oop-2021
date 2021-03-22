#ifndef CLOCK_H
#define CLOCK_H

#include <iostream>
#include <time.h>

const unsigned int MAX_HOURS = 23;
const unsigned int MAX_MINUTES = 59;
const unsigned int MAX_SECONDS = 59;

class Clock {
public:
    Clock();
    Clock(const unsigned int, const unsigned int, const unsigned int);

    unsigned int getHours()const;
    void setHours(const unsigned int);

    unsigned int getMinutes()const;
    void setMinutes(const unsigned int);

    unsigned int getSeconds()const;
    void setSeconds(const unsigned int);

    void printTime()const;

    void nextTick();

    void sync();

    void operator+(const unsigned int);

private:
    unsigned int hours, minutes, seconds;
};

#endif