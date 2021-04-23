#include "item.h"

Item::Item(): name(""), quantity(0), price(0.0) {}

Item::Item(std::string _name, uint _quantity, double _price): 
    name(_name), quantity(_quantity), price(_price) {}

Item::Item(const Item& other) {
    name = other.name;
    quantity = other.quantity;
    price = other.price;
}

Item& Item::operator=(const Item& other) {
    if (this != &other) {
        name = other.name;
        quantity = other.quantity;
        price = other.price;
    }

    return *this;
}

std::istream& operator >> (std::istream& in, Item& item) {
    //in >> item.name >> item.quantity >> item.price;
    assert(!in.eof()); // assert fails => bug in code
    in.ignore();
    std::getline(in, item.name);

    in >> item.quantity >> item.price;
    return in;
}

std::ostream& operator << (std::ostream& out, const Item& item) {
    out << item.name << "\n" << item.quantity << "\n" << item.price;
    return out;
}