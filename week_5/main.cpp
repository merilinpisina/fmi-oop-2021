#include <iostream>
#include <functional>

// [] () mutable throw() -> int {}
// [=,&] - capture clause
// [=] / [&]
// [&, x]
// () - parameter list (optional)
// mutable / immutable - optional
// throw() - optional
// -> int: trailing-return-type (optional)
// {} - function body

template <typename T = int>
using fn_ptr = T(*) (T); // <return_type> (*) = <function_name> (<parameter_types>)

// template <typename T>
// using fn_l = [](T a) -> T;

// template <typename T>
// using repeated = [&a](int k, fn_l func) {
//     if (k == 0) return;
//     func(a);
//     repeated(k-1, func);
// }

template <typename T = int>
void map(T arr[], size_t arr_size, fn_ptr<T> func) {
    for(size_t i = 0; i < arr_size; ++i) {
        arr[i] = func(arr[i]);
    }
}

int functionToBind(int x, float& y, const char* text) {
    return 1;
}

__attribute_pure__ int square(int i) {
    return i * i;
}

constexpr int Fibonacci (int k) {
    return (k <= 1) ? k : Fibonacci(k - 1) + Fibonacci(k - 2);
}

int factorial(int x) {
    if (x == 0) return 1;
    return x * factorial(x - 1);
}

int factorial_TR(int x, int acc) {
    if (x == 0) return acc;
    return factorial_TR(x - 1, x*acc);
}

int factorial_update(int x) {
    return factorial_TR(x, 1);
}

void fn_lazy_1() {
    std::cout << "This is an implemented function\n";
}

void fn_lazy_2(); // This is a non-implemented function

int main() {


    int lambda = [=]() -> int {
        std::cout << "Hello, I'm a lambda function!" << std::endl;
        return 0;
    }();

    int a = 5, b = 4;
    std::function<int(int)> square = [&a, b](int value) -> int { return a * b; };

    int result = square(5);
    std::cout << result << std::endl;

    int arr[] = {1, 2, 3, 4, 5, 6, 7};

    std::cout << "Before isEven:\n";

    for(int i= 0; i < 6; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    map<int>(arr, 6, [](int p) -> int {
        return (int)(p % 2 == 0);
    });
    
    std::cout << "After isEven:\n";
    
    for(int i= 0; i < 6; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // []() noexcept { throw 5; }();

    int x = 0, y = 0;
    [&x, b, y] (int number) mutable { x = b + number; y++;} (10);
    std::cout << "x = " << x << "   y = " << y << std::endl;

    // float helper = 4.5;
    // auto testBind = std::bind(&functionToBind, 10, std::cref(helper), _3); // &<class_name>::<member_function_name> , this
    // testBind(4.4, "lalala");
    // auto testBind1 = std::bind(&functionToBind, _3, _1, _2); // &<class_name>::<member_function_name> , this

    // pure functions:
    // pow, sqrt, abs

    const int fib_series = Fibonacci(10);
    std::cout << fib_series << std::endl;

    fn_lazy_1();

    return 0;
}