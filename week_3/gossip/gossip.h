// #pragma once - 99% compilers
// 100% of compilers:
#ifndef GOSSIP_H
#define GOSSIP_H

#include <iostream>

class Gossip {
public:
    // Big 4:
    Gossip();
    Gossip(const Gossip&);
    Gossip& operator=(const Gossip&);
    ~Gossip();
};

#endif