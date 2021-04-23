#include "teaching_assistant.h"

TeachingAssistant::TeachingAssistant() {}
// Teacher(), Student(), Person()

TeachingAssistant::TeachingAssistant(const char* _name, uint _age, uint _major_ID) :
    Student(_name, _age, _major_ID), Person(_name, _age) {} // explicitly call Person(...)
// Teacher(), Student(), Person(), Student(_name, _age, _major_ID), Person(_name, _age)

TeachingAssistant::TeachingAssistant(const TeachingAssistant& other) :
    Student(other), Teacher(other) {}

TeachingAssistant& TeachingAssistant::operator=(const TeachingAssistant& other) {
    if (this != &other) {
        Teacher::operator=(other);
        Student::operator=(other);
    }
    return *this;
}

TeachingAssistant::~TeachingAssistant() {}