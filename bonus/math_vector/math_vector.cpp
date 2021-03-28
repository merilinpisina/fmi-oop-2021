#include "math_vector.h"
#include <cmath>
#include <cstring>

MathVector::MathVector() : size(0), data(nullptr) {}

MathVector::MathVector(int v_size, double *v_data = nullptr) : size(v_size), data(nullptr)
{
    data = new (std::nothrow) double[v_size];
    if (!data)
    {
        std::cout << "Error: [No memory available]" << std::endl;
        return;
    }

    if (v_data != nullptr)
    {
        for (int i = 0; i < size; ++i)
        {
            data[i] = v_data[i];
        }
    }
    else
    {
        for (int i = 0; i < size; ++i)
        {
            data[i] = 0;
        }
    }
}

void MathVector::copy(const MathVector &other)
{
    this->size = other.size;
    this->data = new (std::nothrow) double[other.size];
    if (!this->data)
    {
        std::cout << "Error: [No memory available]" << std::endl;
        return;
    }

    std::memcpy(this->data, other.data, sizeof(double) * other.size);
}

void MathVector::destroy() {
    if (!data) { // nullptr, 0, false => false
        return;
    }

    delete [] data;
    // optional
    size = 0;
    data = nullptr;
}

void MathVector::resize(int new_size) {
    if (new_size < 0) {
        return;
    }

    if (!data) {
        data = new (std::nothrow) double[new_size];
        if (!this->data)
        {
            std::cout << "Error: [No memory available]" << std::endl;
            return;
        }

        size = new_size;
        std::memset(data, 0, sizeof(double) * new_size);
        return;
    }

    double *temp = new (std::nothrow) double[new_size];
    if (!temp)
    {
        std::cout << "Error: [No memory available]" << std::endl;
        return;
    }

    std::memcpy(temp, data, sizeof(double) * new_size);

    delete [] data;
    data = temp;

    for (int i = size; i < new_size; ++i) {
        data[i] = 0;
    }

    size = new_size;
}

MathVector::MathVector(const MathVector& other) {
    this->copy(other);
}

MathVector& MathVector::operator=(const MathVector& other) {
    if (this != &other) {
        this->destroy();
        this->copy(other);
    }
    return *this;
}

MathVector::~MathVector() {
    this->destroy();
}

const double MathVector::operator[](int index)const {
    if (index >= 0 && index < size) {
        return data[index];
    }
    // error out -> exception
    return 0;
}

double MathVector::operator[](int index) {
    if (index >= 0 && index < size) {
        return data[index];
    }
    // error out -> exception
    return 0;
}

// (*this) += other
MathVector& MathVector::operator+=(const MathVector& other) {
    if (this->size < other.size) {
        this->resize(other.size);
    }

    for(int i = 0; i < other.size; ++i) {
        this->data[i] += other.data[i];
    }

    return *this;
}

MathVector MathVector::operator+(const MathVector& other)const {
    MathVector sum(*this);
    sum += other;
    return sum;
}

MathVector& MathVector::operator-=(const MathVector& other) {
    if (this->size < other.size) {
        this->resize(other.size);
    }

    for(int i = 0; i < other.size; ++i) {
        this->data[i] -= other.data[i];
    }

    return *this;
}

MathVector MathVector::operator-(const MathVector& other)const {
    MathVector diff(*this); // copy constructor
    // int b = 10;
    // int a(b); // a = b = 10;
    diff -= other;
    return diff;
}

MathVector& MathVector::operator*=(const double scalar) {
    for (int i = 0; i < size; ++i) {
        data[i] *= scalar;
    }
    return *this;
}

MathVector MathVector::operator*(const double scalar)const {
    MathVector scal(*this);
    scal *= scalar;
    return scal;
}

MathVector& MathVector::operator/=(const double scalar) {
    if (scalar == 0) {
        // error out
        return *this;
    }

    for (int i = 0; i < size; ++i) {
        data[i] /= scalar;
    }
    return *this;
}

MathVector MathVector::operator/(const double scalar)const {
    MathVector scal(*this);
    scal /= scalar;
    return scal;
}

double MathVector::operator%(const MathVector& other)const {
    // different size => error out / return
    // if (this->size != other.size) {
    //     std::cout << "Error: cannot execute operator% on vectors with different sizes!\n";
    //     return 0;
    // }

    int shorter = (this->size < other.size) ? this->size : other.size;
    double product = 0;
    for (int i = 0; i < shorter; ++i) {
        product += this->data[i] * other.data[i];
    }
    return product;
}

double MathVector::operator~()const {
    return sqrt(operator%(*this));

    // (*this)%(*this)
    // sqrt(this->operator%(*this))
    // or
    // sqrt((*this).operator%(*this))
}

bool MathVector::operator||(const MathVector& other)const {
    if (this->size != other.size) {
        return false;
    }

    double coeff = this->data[0] / other.data[0];
    const double eps = 0.00001;

    for (int i = 1; i < this->size; ++i) {
        double currentCoeff = this->data[i] / other.data[i];
        if (abs(coeff - currentCoeff) > eps) {
            return false;
        }
    }
    return true;
}

bool MathVector::operator|=(const MathVector& other)const {
    return (this->operator%(other) == 0);
}

void MathVector::print()const {
    if (!size || !data) {
        return;
    }

    std::cout << "(";
    for(int i = 0; i < size - 1; ++i) {
        std::cout << data[i] << ", ";
    }
    std::cout << data[size-1] <<  ")\n";
}

std::ostream& operator<<(std::ostream& out, const MathVector& vect) {
    if (!vect.size || !vect.data) {
        return out;
    }

    out << "(";
    for(int i = 0; i < vect.size - 1; ++i) {
        out << vect[i] << ", ";
    }
    out << vect[vect.size-1] <<  ")\n";
    return out;
}

std::istream& operator>>(std::istream& in, MathVector& vect) {
    std::cout << "Enter " << vect.size << " values:\n"; // memory leak
    // resize if we are entering size

    for (int i = 0; i < vect.size; ++i) {
        in >> vect.data[i];
    }

    std::cout << "Result: \n" << vect;
    return in;
}