#ifndef TEACHING_ASSISTANT_H
#define TEACHING_ASSISTANT_H

#include "student.h"
#include "teacher.h"

class TeachingAssistant : public Teacher, public Student {
public:
    TeachingAssistant();
    TeachingAssistant(const char* _name, uint _age, uint _major_ID);
    TeachingAssistant(const TeachingAssistant& other);
    TeachingAssistant& operator=(const TeachingAssistant& other);
    virtual ~TeachingAssistant() override;

    virtual void sayHello()const override {
        std::cout << "[class TeachingAssistant]: ";
        std::cout << "Hello, I am " << 
            getName() << 
            " and I am " << 
            getAge() << 
            " years old. My major ID is: " <<
            getMajorID() << ".\n";
    }

private:
};

#endif