#include "clock.h"

Clock::Clock() : hours(0), minutes(0), seconds(0) {}

Clock::Clock(const unsigned int h, const unsigned int m, const unsigned int s) {
    setHours(h);
    setMinutes(m);
    setSeconds(s);
}

unsigned int Clock::getHours()const {
    return hours;
}

void Clock::setHours(const unsigned int h) {
    if (h > MAX_HOURS) {
        // throw exception
        // error out
        hours = 0;
        return;
    }
    hours = h;
}

unsigned int Clock::getMinutes()const {
    return minutes;
}

void Clock::setMinutes(const unsigned int m) {
    if (m > MAX_MINUTES) {
        // throw exception
        // error out
        minutes = 0;
        return;
    }
    minutes = m;
}

unsigned int Clock::getSeconds()const {
    return seconds;
}

void Clock::setSeconds(const unsigned int s) {
    if (s > MAX_SECONDS) {
        // throw exception
        // error out
        seconds = 0;
        return;
    }
    seconds = s;
}

void Clock::printTime() const {
    std::cout << "Time: " <<
                hours << ":" <<
                minutes << ":" <<
                seconds << std::endl;
}

void Clock::nextTick() {
    ++seconds;
    if (seconds > MAX_SECONDS) {
        seconds = 0;
        ++minutes;
    }

    if (minutes > MAX_MINUTES) {
        minutes = 0;
        ++hours;
    }

    if (hours > MAX_HOURS) {
        hours = 0;
    }
}

void Clock::sync() {
    time_t currentTime;
    time(&currentTime);

    tm* timeInfo;
    timeInfo = localtime(&currentTime);

    setHours(timeInfo->tm_hour);
    setMinutes(timeInfo->tm_min);
    setSeconds(timeInfo->tm_sec);
}

void Clock::operator+(const unsigned int s) {
    seconds += s;
    if (seconds > MAX_SECONDS) {
        unsigned int over = seconds % (MAX_SECONDS + 1);
        unsigned int minutesPassed = seconds / (MAX_SECONDS + 1);

        seconds = over;
        minutes += minutesPassed;
    }

    if (minutes > MAX_MINUTES) {
        unsigned int over = minutes % (MAX_MINUTES + 1);
        unsigned int hoursPassed = minutes / (MAX_MINUTES + 1);

        minutes = over;
        hours += hoursPassed;
    }

    if (hours > MAX_HOURS) {
        unsigned int over = hours % (MAX_HOURS + 1);
        hours = over;
    }
}