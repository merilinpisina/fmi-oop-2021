#include "gossip.h"

void test() {
    Gossip a; // default constructor
    Gossip b(a); // copy constructor
    Gossip c = b; // copy constructor

    c = a; // assignment operator
} // destructor

int main() {

    test();
    return 0;
}