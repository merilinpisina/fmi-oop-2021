#include <iostream>

template <typename T = int>
T gcd(T a, T b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a%b);
}

class Rational {
public:
    // default constructor + constructor with parameters
    Rational(int n = 0, int d = 1): nominator(n), denominator(d) {
        simplify();
    }

    // for non-simplified rational numbers
    bool operator==(Rational& other);

    bool operator==(const Rational& other) const;
    bool operator!=(const Rational& other) const;
    bool operator>(const Rational& other) const;
    bool operator<(const Rational& other) const;
    bool operator>=(const Rational& other) const;
    bool operator<=(const Rational& other) const;

    Rational operator+(const Rational& other);
    Rational operator-(const Rational& other);
    Rational operator*(const Rational& other);
    Rational operator/(const Rational& other);

    Rational& operator+=(const Rational& other);
    Rational& operator-=(const Rational& other);
    Rational& operator*=(const Rational& other);
    Rational& operator/=(const Rational& other);

    Rational operator++(int); // postfix
    Rational operator--(int); // postfix

    Rational& operator++(); // prefix
    Rational& operator--(); // prefix

    // Friend functions in C++
    // - defined outside of the class definition
    // - declared inside the class
    // - have access to private members & functions of the class
    // - can be basic functions, template functions, member functions, class template, etc.
    // - declaration starts with the 'friend'

    // - cout is a member of the class ostream (output stream)
    // - when we write: cout << <object>:
    // -> compiler looks for a definition for this operator in ostream class
    // -> compiler looks for a global function
    friend std::ostream& operator<< (std::ostream& out, const Rational& item);
    friend std::istream& operator>> (std::istream& in, Rational& item);

private:
    int nominator, denominator;

    void simplify() {
        if (denominator < 0) {
            nominator *= -1;
            denominator *= -1;
        }

        int div = gcd(nominator, denominator);
        nominator/=div;
        denominator/=div;
    }
};



int main() {

    return 0;
}

// <return_type> <class_name>::<function_name> (<function_parameters>) {<function_body>}
// Rational& Rational::operator++() {}

bool Rational::operator==(Rational& other){
    this->simplify();
    other.simplify();
    return (this->nominator == other.nominator && this->denominator == other.denominator);
}

bool Rational::operator==(const Rational& other) const {
    return (this->nominator == other.nominator && this->denominator == other.denominator);
}

bool Rational::operator!=(const Rational& other) const {
    // return !(*this == other); // -> using ==
    return (this->nominator != other.nominator || this->denominator != other.denominator);
}

bool Rational::operator>(const Rational& other) const {
    return (double(this->nominator) / double(this->denominator) > double(other.nominator) / double(other.denominator));
}

bool Rational::operator>=(const Rational& other)const {
    return (*this > other || *this == other);
}

bool Rational::operator<(const Rational& other) const {
    return (double(this->nominator) / double(this->denominator) < double(other.nominator) / double(other.denominator));
}

bool Rational::operator<=(const Rational& other)const {
    return (*this < other || *this == other);
}

Rational Rational::operator+(const Rational& other) {
    Rational result(this->nominator * other.denominator + this->denominator * other.nominator,
                    this->denominator * other.denominator);
    result.simplify();
    return result;
}

Rational Rational::operator-(const Rational& other) {
    Rational result(this->nominator * other.denominator - this->denominator * other.nominator,
                    this->denominator * other.denominator);
    result.simplify();
    return result;
}

Rational Rational::operator*(const Rational& other) {
    Rational result(this->nominator * other.nominator, this->denominator * other.denominator);
    result.simplify();
    return result;
}

Rational Rational::operator/(const Rational& other) {
    Rational result(this->nominator * other.denominator, this->denominator * other.nominator);
    result.simplify();
    return result;
}

Rational& Rational::operator+=(const Rational& other) {
    *this = *this + other;
    return *this;
}

Rational& Rational::operator-=(const Rational& other) {
    *this = *this - other;
    return *this;
}

Rational& Rational::operator*=(const Rational& other) {
    *this = *this * other;
    return *this;
}

Rational& Rational::operator/=(const Rational& other) {
    *this = *this / other;
    return *this;
}

Rational Rational::operator++(int) {
    Rational temp(*this);
    this->nominator += this->denominator;
    return temp;
}

Rational Rational::operator--(int) {
    Rational temp(*this);
    this->nominator -= this->denominator;
    return temp;
}

Rational& Rational::operator++() {
    this->nominator += this->denominator;
    return *this;
}

Rational& Rational::operator--() {
    this->nominator -= this->denominator;
    return *this;
}

std::ostream& operator<< (std::ostream& out, const Rational& item) {
    out << item.nominator << "/" << item.denominator << std::endl;
    return out;
}

std::istream& operator>> (std::istream& in, Rational& item) {
    in >> item.nominator >> item.denominator;
    return in;
}