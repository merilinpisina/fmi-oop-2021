#include "gossip.h"

Gossip::Gossip() {
    std::cout << "Default constructor called...\n";
}

Gossip::Gossip(const Gossip& other) {
    std::cout << "Copy constructor called...\n";
}

Gossip& Gossip::operator=(const Gossip& other) {
    std::cout << "Assignment operator called...\n";
}

Gossip::~Gossip() {
    std::cout << "Destructor called...\n";
}