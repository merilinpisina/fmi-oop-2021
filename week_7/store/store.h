#ifndef STORE_H
#define STORE_H

#include "item.h"

const uint DEFAULT_CAPACITY = 8;

class Store{
public:
    Store(const uint _capacity = DEFAULT_CAPACITY);
    Store(const Store& other);
    Store& operator=(const Store& other);
    ~Store();

    void add(const Item& new_item);
    friend std::ostream& operator << (std::ostream& out, const Store& store);

private:
    uint capacity, size;
    Item* items;

    void copy(const Store& other) {
        size = other.size;
        capacity = other.capacity;
        items = new (std::nothrow) Item[capacity];
        if (!items) {
            throw std::bad_alloc();
        }

        for (uint i = 0; i < size; ++i) {
            this->items[i] = other.items[i];
        }
    }

    void resize() {
        Item *temp = items;
        capacity *= 2;
        items = new (std::nothrow) Item[capacity];
        if (!items) {
            throw std::bad_alloc();
        }

        for (uint i = 0; i < size; ++i) {
            items[i] = temp[i];
        }
        delete [] temp;
    }

    void destroy() {
        if (!items) return;
        delete [] items;

        // optional
        size = 0;
        capacity = 0;
        items = nullptr;
    }
};

#endif