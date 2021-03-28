#include <iostream>
#include <functional>

using ll = long long;
// #define 

template <typename T = int> // class
void print_array(T arr[], size_t arr_size) {
    for (size_t i = 0; i < arr_size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T = int>
using fn = T(*) (T); // <return_type> (*) = <function_name> (<parameter_types>)

template <typename T = int>
using void_fn = void(*) (T&);

template <typename T = int>
T add_one(T a) { // fn
    return ++a;
}

template <typename T = int>
T reduce_one(T a) { // fn
    return --a;
}

template <typename T = int>
void add_one_v(T& a) {
    ++a;
}

template <typename T = int>
void fill_value(T& in) {
    std::cin >> in;
}

template <typename T = int>
void print_value(T& out) {
    std::cout << out;
}

template <typename T = int>
void map(T arr[], size_t arr_size, fn<T> func) {
    for(size_t i = 0; i < arr_size; ++i) {
        arr[i] = func(arr[i]);
    }
}

template <typename T = int>
void map(T arr[], size_t arr_size, void_fn<T> func) {
    for(size_t i = 0; i < arr_size; ++i) {
        func(arr[i]);
    }
}

struct S {
	int a, b, c;

	S() :a(0), b(0), c(0) {}
	S(int a_, int b_, int c_) :a(a_), b(b_), c(c_){}

	friend std::istream& operator>>(std::istream& in, S& element);
	friend std::ostream& operator<<(std::ostream& out, const S& element);

	// prefix ++a
	// b = ++a
	// a = a + 1;
	// b = a;

	// a = 6
	// b = a++ -> b = 6, a = 7
	// b = ++a -> b = 7, a = 7
	S operator++() {
		++(this->a);
		++(this->b);
		++(this->c);
		return *this;
	}

	// postfix a++
	// b = a++
	// b = a;
	// a = a + 1;

	S operator++(int) {
		S tmp{ this->a, this->b, this->c };
		++(*this);
		return tmp;
	}

	void swap() {
		int t = this->a;
		this->a = this->b;
		this->b = t;
	}

};

int main() {

    // int arr[5];
    // map(arr, 5, fill_value);
    // map(arr, 5, print_value);
    // std::cout << std::endl;

    // map(arr, 5, add_one);
    // map(arr, 5, print_value);
    // std::cout << std::endl;

    // std::function<int(int)> sq = [](int val)->int {return val * val;};

    S example[3];
    map(example, 3, fill_value);
    map(example, 3, print_value);
    std::cout << std::endl;

    map(example, 3, add_one);
    map(example, 3, print_value);
    std::cout << std::endl;

    return 0;
}

std::istream & operator>>(std::istream & in, S& element)
{
	std::cout << "Enter values for a, b, c: ";
	in >> element.a >> element.b >> element.c;
	return in;
}

std::ostream & operator<<(std::ostream & out, S& element)
{
	std::cout << element.a << " " << element.b << " " << element.c << std::endl;
	return out;
}