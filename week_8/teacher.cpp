#include "teacher.h"

Teacher::Teacher() {} // Teacher() : Person() {}

Teacher::Teacher(const char* _name, uint _age) :
    Person(_name, _age) {}
// Teacher(const char* _name, uint _age) : 
//   Person(), Person(_name, _age) {}

// Person()
Teacher::Teacher(const Teacher& other) : Person(other) {}

Teacher& Teacher::operator=(const Teacher& other) {
    if(this != &other) {
        Person::operator=(other);
    }
    return *this;
}