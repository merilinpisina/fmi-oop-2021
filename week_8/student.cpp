#include "student.h"

Student::Student() : majorID(0) {} // Student() : Person(), majorID(0){}

Student::Student(const char* _name, uint _age, uint _major_ID) :
    Person(_name, _age), majorID(_major_ID) {
        std::cout << "[Student]: whaaaaaat, we are here?\n";
    }
// Student(const char* _name, uint _age, uint _major_ID) : 
//   Person(), Person(_name, _age), majorID(_major_ID) {}

// Person()
Student::Student(const Student& other) : Person(other), majorID(other.majorID) {}

Student& Student::operator=(const Student& other) {
    if(this != &other) {
        Person::operator=(other);
        majorID = other.majorID;
    }
    return *this;
}
