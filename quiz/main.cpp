#include <iostream>

#include "id.h"
#include "questionnaire.h"

using uint = unsigned int;

void testID()
{
    data::initialize();
    uint id = data::getAndIncrease();
    std::cout << id << std::endl;
    id = data::getAndIncrease();
    std::cout << id << std::endl;
}

void testQuestionnaire()
{
    std::ifstream qFile("questionnaire.txt");
    Questionnaire q(qFile);
    std::cout << q.welcome_msg;
    q.askNext();
    std::cout << "Your answer: ";
    unsigned int a;
    std::cin >> a;
    if (!q.check(a))
    {
        std::cout << q.incorrect_msg << q.getAnswer() << std::endl;
        return;
    }
    std::cout << q.correct_msg;
}

int main()
{

    try
    {
        testQuestionnaire();
    }
    catch (std::bad_alloc &e)
    {
        std::cout << "Bad allocation exception occured" << std::endl;
        // handle exception
    }
    catch (std::invalid_argument &e)
    {
        std::cout << "Invalid argument: " << e.what() << std::endl;
        // handle exception
    }
    catch (std::exception &e) // any type exception
    {
        std::cout << e.what() << std::endl;
        // handle exception
    }
    catch (...) // any type exception
    {
        std::cout << "An exception occured" << std::endl;
        // handle exception
    }
    return 0;
}