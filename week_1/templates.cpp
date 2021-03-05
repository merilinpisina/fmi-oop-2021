#include <iostream>

template <typename T>
T max(T a, T b)
{
    return a > b ? a : b;
}

template <typename T>
void print_fmt(char* msg, T value) {
    if (msg != nullptr) {
        std::cout << *msg << " ";
    }
    std::cout << value <<std::endl;
}

int main()
{

    int a, b;
    std::cin >> a >> b;
    std::cout << max<int>(a, b) << std::endl;

    float a1, b1;
    std::cin >> a1 >> b1;
    std::cout << max<float>(a1, b1) << std::endl;

    return 0;
}