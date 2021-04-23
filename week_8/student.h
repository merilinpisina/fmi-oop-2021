#ifndef STUDENT_H
#define STUDENT_H

#include "person.h"

class Student : virtual public Person {
public:
    Student();
    Student(const char* _name, uint _age, uint _major_ID);
    Student(const Student& other);
    Student& operator=(const Student& other);
    virtual ~Student() override {}

    uint getMajorID()const {
        return majorID;
    }

    virtual void sayHello()const override {
        std::cout << "[class Student]: ";
        std::cout << "Hello, I am " << 
            getName() << 
            " and I am " << 
            getAge() << 
            " years old. My major ID is: " <<
            majorID << ".\n";
    }

private:
    uint majorID;
};

#endif