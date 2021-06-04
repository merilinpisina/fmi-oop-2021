#include <iostream>

void testConstCast(int *what)
{
    if (what != nullptr)
        std::cout << *what << std::endl;
}

int main()
{

    // Implicit conversion
    int varInt = 10;
    double varDouble = varInt;

    // Explicit conversion
    int varInt2 = 10;
    double varDouble2 = (double)varInt2;

    // -> static_cast
    // -> const_cast
    // -> reinterpret_cast
    // -> dynamic_cast

    double varDouble3 = static_cast<double>(varInt);
    // error
    double *varDoublePtr = static_cast<double *>(&varInt); // doesn't work for primitive types

    int varInt3 = 5;
    const int *constInt = &varInt3;
    testConstCast(const_cast<int *>(constInt));

    double *varDoublePtr2 = reinterpret_cast<double *>(&varInt);

    
    return 0;
}