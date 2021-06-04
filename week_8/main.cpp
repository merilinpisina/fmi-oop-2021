#include "person.h"
#include "student.h"
#include "teacher.h"
#include "teaching_assistant.h"

void testInheritance() {
    Person person("Pesho", 20);
    person.sayHello();

    Student student("Iliya", 20, 45);
    student.sayHello();

    // Person* studentToPerson = static_cast<Person*>(&student);

    Teacher teacher("Vlado R", 45);
    teacher.sayHello();

    TeachingAssistant ta("Merilin", 21, 45);
    ta.sayHello();
}

int main() {

    testInheritance();
    return 0;
}