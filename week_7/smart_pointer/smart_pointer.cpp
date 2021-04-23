#include "smart_pointer.h"

void test1() {
    Ptr<int> int_ptr(new (std::nothrow) int(5));
    std::cout << *int_ptr << std::endl;
}

int main() {

    test1();

    return 0;
}