#include "person.h"

Person::Person(): age(0), name(nullptr) {}

Person::Person(const char* _name, uint age): age(age), name(nullptr) {
    std::cout << "[Person]: whaaaaaat, we are here?\n";
    assert(_name);
    name = new (std::nothrow) char[strlen(_name) + 1];
    if (!name) {
        throw std::bad_alloc();
    }

    strcpy(name, _name);
}

Person::Person(const Person& other) {
    this->copy(other);
}

Person& Person::operator=(const Person& other) {
    if (this != &other) {
        this->destroy();
        this->copy(other);
    }
    return *this;
}

Person::~Person() {
    destroy();
}

uint Person::getAge()const {
    return age;
}

const char* Person::getName()const {
    return name;
}