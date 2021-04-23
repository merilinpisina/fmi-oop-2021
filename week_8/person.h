#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <cstring>
#include <cassert>
#include <exception>

using uint = unsigned int;

class Person {
public:
    Person();
    Person(const char* _name, uint age);
    Person(const Person& other);
    Person& operator=(const Person& other);
    virtual ~Person();

    uint getAge()const;
    const char* getName()const;

    virtual void sayHello()const {
        std::cout << "[class Person]: ";
        std::cout << "Hello, I am " << name << " and I am " << age << " years old\n";
    }

private:
    uint age;
    char* name;

    void destroy() {
        if (name) {
            delete [] name;
            name = nullptr;
            age = 0;
        }
    }

    void copy(const Person& other) {
        this->age = other.age;
        if (!other.name) {
            return;
        }

        this->name = new (std::nothrow) char[strlen(other.name) + 1];
        if (!this->name) {
            throw std::bad_alloc();
        }

        strcpy(this->name, other.name);
    }
};

#endif