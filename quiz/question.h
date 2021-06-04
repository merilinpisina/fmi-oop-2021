#ifndef QUESTION_H
#define QUESTION_H

#include <cstring>
#include <vector>
#include <iostream>
#include <fstream>

using uint = unsigned int;

class Question
{
public:
    Question(std::string, std::vector<std::string>, const uint, const uint);

    void ask() const;
    bool check(const uint answer) const;
    uint getAnswer() const;

    // friend std::istream &operator>>(std::istream &in, Question &element);
    friend std::ostream &operator<<(std::ostream &out, const Question &element);

private:
    std::string question;
    std::vector<std::string> answers;
    const uint right_answer;
    const uint points;
};

#endif