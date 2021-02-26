#include <iostream>
#include <exception>

// Dynamic memory in 4 steps:
// 1. new <type> [[]] -> Request a new variable
// 2. if -> Check if we are given the requested memory
// 3. Use that memory
// 4. Destroy that dynamic variable

int main()
{
    // A SINGLE INT
    // new returns a pointer
    // -> 1. the requested resource, 2. exception - nothrow, 3. nullptr
    int *dynamic = new (std::nothrow) int;
    // check if the memory is returned to us
    if (dynamic == nullptr)
    { // if the memory is unavailable
        std::cout << "Memory is unavailable / full. Try again with a 'smaller' variable.\n";
        // return, throw, ...
    }
    // use the memory
    *dynamic = 10;
    // int a  = 10;
    // dynamic = &a;

    // delete the variable / free memory
    delete dynamic;


    // INT ARRAY
    int length;
    std::cout << "Enter length of array: ";
    std::cin >> length;

    int *array = new (std::nothrow) int[length + 1];
    if (array == nullptr)
    {
        std::cout << "Memory is unavailable / full. Try again with a 'smaller' variable.\n";
        return -1;
    }

    for (int i = 0; i < length; ++i)
    {
        std::cin >> *(array + i);
    }

    for (int i = 0; i < length; ++i)
    {
        std::cout << *(array + i);
    }

    delete[] array;

    // INT MATRIX
    int rows, cols;
    std::cout << "Enter number of rows: ";
    std::cin >> rows;

    std::cout << "Enter number of columns: ";
    std::cin >> cols;

    int **matrix = new (std::nothrow) int*[rows]; // allocate memory for rows
    if (matrix == nullptr) {
        std::cout << "Memory is unavailable / full. Try again with a 'smaller' variable.\n";
        return -1;
    }

    for (int i = 0; i < rows; ++i) {
        matrix[i] = new (std::nothrow) int[cols];
        if (matrix[i] == nullptr) {
            std::cout << "Memory is unavailable / full. Try again with a 'smaller' variable.\n";
            return -1;
        }
    }

    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    // another implementation - not the best
    int **matrix2 = new (std::nothrow) int*[rows];
    if (matrix2 == nullptr) {
        std::cout << "Memory is unavailable / full. Try again with a 'smaller' variable.\n";
        return -1;
    }

    matrix2[0] = new (std::nothrow) int[rows*cols];
    for (int i = 0; i < rows; ++i) {
            matrix2[i] = matrix2[0] + i * cols;
    }

    delete[] matrix2[0];
    delete[] matrix2;

    return 0;
}