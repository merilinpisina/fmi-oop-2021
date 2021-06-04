#ifndef QUESTIONNATRE
#define QUESTIONNATRE

#include "question.h"

constexpr char *CORRECT_MSG = "Correct!\n";
constexpr char *INCORRECT_MSG = "Incorrect answer! The correct answer was: ";
constexpr char *WELCOME_MSG = "Welcome to the quiz!\n";

class Questionnaire
{
public:
    Questionnaire(std::ifstream &content);
    ~Questionnaire();

    void askNext();
    uint getAnswer() const;
    bool check(uint answer) const;

    bool end() const;

    static constexpr char *correct_msg = CORRECT_MSG;
    static constexpr char *incorrect_msg = INCORRECT_MSG;
    static constexpr char *welcome_msg = WELCOME_MSG;

private:
    std::vector<Question *> questions;
    uint current_question = 0;
};

#endif