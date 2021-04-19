#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <cstring>
#include <cassert>
#include <fstream>
#include <exception>

using uint = unsigned int;

class Item {
public:
    Item();
    Item(std::string _name, uint _quantity, double _price);
    Item(const Item& other);
    Item& operator=(const Item& other);
    // ~Item(); -> no need (no dynamic memory)

    friend std::istream& operator >> (std::istream& in, Item& item);
    friend std::ostream& operator << (std::ostream& out, const Item& item);

private:
    std::string name;
    uint quantity;
    double price;
};


#endif