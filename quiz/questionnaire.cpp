#include "questionnaire.h"

Questionnaire::Questionnaire(std::ifstream &content)
{
    if (!content)
    {
        throw std::runtime_error("No questions to read!");
    }

    while (!content.eof())
    {
        std::string firstLine;
        getline(content, firstLine);

        int numberOfAnswers;
        content >> numberOfAnswers;

        std::string newline;
        getline(content, newline);

        int copy = numberOfAnswers;
        // std::vector<std::string> answers(numberOfAnswers);
        std::vector<std::string> answers;

        // int index = 0;
        for (std::string line; (copy > 0 && !content.eof() && getline(content, line)); copy--)
        {
            answers.push_back(line);
            // answers[index++] = line;
        }

        int rightAnswer;
        content >> rightAnswer;
        if (!(rightAnswer >= 0 && rightAnswer < numberOfAnswers))
        {
            throw std::runtime_error("Invalid answer");
        }

        int points;
        content >> points;

        Question *new_question = new (std::nothrow) Question(firstLine, answers, rightAnswer, points);
        if (new_question == nullptr)
        {
            throw std::bad_alloc();
        }

        questions.push_back(new_question);
    }
}

Questionnaire::~Questionnaire()
{
    while (!questions.empty())
    {
        delete questions.at(questions.size() - 1);
        questions.pop_back();
    }
}

void Questionnaire::askNext()
{
    if (current_question == questions.size())
    {
        throw std::runtime_error("No more questions to ask!");
    }
    return questions[current_question++]->ask();
}

uint Questionnaire::getAnswer() const
{
    if (current_question == 0)
    {
        return 1000000;
    }
    return questions[current_question - 1]->getAnswer();
}

bool Questionnaire::check(uint answer) const
{
    if (current_question == 0)
    {
        return false;
    }
    return questions[current_question - 1]->check(answer);
}

bool Questionnaire::end() const
{
    return (current_question == questions.size() - 1);
}

// // random access
// a[n]
// i+=n i-=n
// i+n i-n
// > < <= >=

// // bidirectional
// --i i-- *i--

// // forward
// {
//     ii = i;
//     *i++;
//     *ii;
// }

// It i;
// It i();

// // output
// *i = a;
// *i++ = a;

// // input
// *i
// i->n
// i == ii
// i != ii

// // all
// It i(ii);
// i = ii;