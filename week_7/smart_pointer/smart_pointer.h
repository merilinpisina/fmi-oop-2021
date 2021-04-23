#ifndef SMART_POINTER_H
#define SMART_POINTER_H

#include <iostream>
#include <cassert>

using uint = unsigned int;

class RefCounter {
public:
    void add() {
        ++count;
    }

    uint release() {
        return --count;
    }

private:
    uint count;
};

template <typename T>
class Ptr {
public:
    Ptr(T* _data): data(_data), ref() {
        // ref = RefCounter();
        ref.add();
        std::cout << "Constructor...\n";
    }

    ~Ptr(){
        std::cout << "Destructor...\n";

        if (!ref.release() && data) {
            delete data;
            // optional
            ref = RefCounter(0);
        }
    }

    Ptr(const Ptr<T> &other): data(other.data), ref(other.ref) {}

    Ptr& operator=(const Ptr<T> &other) {
        if (this != &other) { // to avoid self assignment

            if (!ref.release()) {
                delete data;
            }

            data = other.data;
            ref = other.ref;
            ref.add();
        }
        return *this;
    }

    T* operator->() {
        assert(data);
        return data;
    }

    T& operator*() {
        assert(data);
        return *data;
    }

private:
    T* data;
    RefCounter ref;
};

#endif