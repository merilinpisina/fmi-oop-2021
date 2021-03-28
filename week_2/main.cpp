#define DOCTEST_CONFIG_IMPLEMENT
#include "../doctest.h"
#include "rational.cpp"
#include <iostream>

TEST_CASE("Operator ==") {
    Rational r1(1, 1), r2(1, 1);
    CHECK(r1 == r2);
    r1++;
    CHECK(!(r1 == r2));
}

TEST_CASE("Default constructor") {
    Rational expected(0, 1);
    Rational actual;
    CHECK(expected == actual);

    Rational expectedPartial(2, 1);
    Rational actualPartial(2);
    CHECK(expectedPartial == actualPartial);
}

int main() {

    doctest::Context().run();
    return 0;
}