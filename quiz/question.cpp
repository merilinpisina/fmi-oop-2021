#include "question.h"

Question::Question(std::string question, std::vector<std::string> answers, const uint right_answer, const uint points) : question(question), answers(answers), right_answer(right_answer), points(points)
{
}

void Question::ask() const
{
    std::cout << question << "\n";

    int size = answers.size();
    for (int i = 0; i < size; ++i)
    {
        std::cout << answers[i] << "\n";
    }
    //    std::cout << *this;
}

bool Question::check(const uint answer) const
{
    return (answer == right_answer);
}

uint Question::getAnswer() const
{
    return right_answer;
}

// friend std::istream &operator>>(std::istream &in, Question &element) {
//     std::string firstLine;
//     getline(in, firstLine);
//     element.question = firstLine;

//     int numberOfAnswers;
//     in >> numberOfAnswers;
//     int copy = numberOfAnswers;

//     for (std::string line; (copy > 0 && getline(in, line)); copy--) {
//         element.answers.push_back(line);
//     }

//     int rightAnswer;
//     in >> rightAnswer;
//     if (!(rightAnswer >= 0 && rightAnswer < numberOfAnswers)) {
//         throw std::runtime_error("Invalid answer");
//     }

//     element.right_answer = rightAnswer;
// }

std::ostream &operator<<(std::ostream &out, const Question &element)
{
    out << element.question << "\n"
        << element.answers.size() << "\n";

    int size = element.answers.size();
    for (int i = 0; i < size; ++i)
    {
        out << element.answers[i] << "\n";
    }
    out << element.right_answer << "\n"
        << element.points << "\n";
}