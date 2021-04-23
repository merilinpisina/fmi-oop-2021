#ifndef TEACHER_H
#define TEACHER_H

#include "person.h"

class Teacher : virtual public Person {
public:
    Teacher();
    Teacher(const char* _name, uint _age);
    Teacher(const Teacher& other);
    Teacher& operator=(const Teacher& other);
    virtual ~Teacher() override {}

    virtual void sayHello()const override {
        std::cout << "[class Teacher]: ";
        std::cout << "Hello, I am " << 
            getName() << 
            " and I am " << 
            getAge() << 
            " years old.\n";
    }

public:
};

#endif