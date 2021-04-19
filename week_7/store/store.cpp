#include "store.h"

Store::Store(const uint _capacity): capacity(_capacity), size(0), items(nullptr) {
    items = new (std::nothrow) Item[capacity];
    if (!items) {
        throw std::bad_alloc();
    }
}

Store::Store(const Store& other) {
    this->copy(other);
}

Store& Store::operator=(const Store& other) {
    if (this != &other) {
        this->destroy();
        this->copy(other);
    }
    return *this;
}

Store::~Store() {
    destroy();
}

void Store::add(const Item& new_item) {
    if (size >= capacity) {
        resize();
    }
    items[size++] = new_item;
}

std::ostream& operator << (std::ostream& out, const Store& store) {
    // cout:
    out << "Number of items: " << store.size << std::endl;
    for(uint i = 0; i < store.size; ++i) {
        out << store.items[i] << std::endl;
    }
    return out;

    // in file:
    // out << store.size << std::endl;
    // for(uint i = 0; i < size; ++i) {
    //     out << store.items[i] << std::endl;
    // }
    // return out;
}