#include <iostream>
#include <cstring>

template <typename T>
class MaxValue {
public:
    MaxValue(T a_, T b_, T c_): a(a_), b(b_), c(c_) {}
    bool operator>(MaxValue& other) {
        return this->a > other.a && this->b > other.b && this->c > other.c;
    }
    bool operator==(MaxValue& other) {
        return this->a == other.a && this->b == other.b && this->c == other.c;
    }
private:
    T a, b, c;
};

template <typename T>
T max(T a, T b)
{
    return a > b ? a : b;
}

class Student {
public:

    // BIG 4
    // constructor
    // destructor
    // operator=
    // copy constructor

    Student(unsigned int fn_, unsigned int age_, char* name_) : fn(fn_), age(age_) {
        if (name_ != nullptr) {
            int length = std::strlen(name_);
            name = new (std::nothrow) char[length+1];
            if (name == nullptr) {
                std::cout << "Could not allocate memory for student name." << std::endl;
            }
            else {
                std::strcpy(name, name_);
            }
        }
    }

    Student(const Student& other) {
        this->copy(other);
    }
    
    Student& operator=(const Student& other) {
        if (this->name != nullptr) {
            delete [] this->name;
            this->name  = nullptr;
        }
        this->copy(other);
        return *this;
    }

    ~Student() {
        if (name != nullptr) {
            delete [] name;
        }
    }

    void print() const {
        std::cout << "FN: " << fn << "; AGE: " << age << "; NAME: "<< (name != nullptr ? name : "Unknown") << std::endl; 
    }

private:
    unsigned int fn, age;
    char* name;

    void copy(const Student& other) {
        this->fn = other.fn;
        this->age = other.age;

        if (other.name != nullptr) {
            int length = std::strlen(other.name);
            name = new (std::nothrow) char[length+1];
            if (name == nullptr) {
                std::cout << "Could not allocate memory for student name." << std::endl;
            }
            else {
                std::strcpy(name, other.name);
            }
        }  
    }
};

template <typename T = Student, typename S = int>
class DynamicArray {
public:
    DynamicArray(S capacity_ = 8) : capacity(capacity_), size(0) {
        data = new(std::nothrow) T[capacity];
        if (data == nullptr) {
            std::cout << "Could not allocate memory for dynamic array." << std::endl;
        }
    }

    DynamicArray(const DynamicArray& other) {
        this->copy(other);
    }

    DynamicArray& operator=(const DynamicArray& other) {
        if (this->data != nullptr) {
            this->destroy();
        }
        this->copy(other);
    }

    ~DynamicArray() {
        this->destroy();
    }

    void addElement(T& newElement) {
        if (size == capacity) {
            resize(capacity*2);
        }

        this->data[size++] = newElement; // operator = of T
    }

    S getSize() const {
        return this->size;
    }

    // void print() const {
    //     for (int i = 0; i < size; ++i) {
    //         this->data[i].print(); // all classes that have the function void print()
    //     }
    // }

private:
    S size, capacity;
    T* data;

    void resize(S newCapacity) {
        T* temp = this->data;
        S oldCapacity = this->capacity;
        this->data = new(std::nothrow) T[newCapacity];
        if (this->data == nullptr) {
            std::cout << "Could not allocate memory for dynamic array." << std::endl;
            return;
        }
        
        for(int i = 0; i < oldCapacity; ++i) {
            this->data[i] = temp[i]; // operator =
        }

        this->size = oldCapacity;

        delete [] temp;
        // resized array with capacity *= 2
    }

    void copy(const DynamicArray& other) {
        this->size = other.size;
        this->capacity = other.capacity;

        this->data = new(std::nothrow) T[capacity];
        if (this->data == nullptr) {
            std::cout << "Could not allocate memory for dynamic array." << std::endl;
            return;
        }

        for(int i = 0; i < size; ++i) {
            this->data[i] = other.data[i]; // operator =
        }
    }

    void destroy() {
        delete [] data;
        size = 0;
        capacity = 0;
    }

};

bool exampleCopy(Student a) {

    Student test(10000, 9, nullptr);

    // use test

    return true; // Destructor for test
}

// return value is a copy -> copy constructor
Student exampleCopy2() {
    Student ex = Student(1000, 10, nullptr);
    return ex; 
}

int main() {

    // MaxValue<int> first = MaxValue<int>(1, 2, 3), second = MaxValue<int>(2,3,4);
    // if (max<MaxValue<int>>(first, second) == first) {
    //     std::cout << "max = first" << std::endl;
    // } 
    // else {
    //     std::cout << "max = second" << std::endl;
    // }

    Student st1(10000, 20, nullptr);
    Student st2(st1); // copy constructor
    Student st3 = st1; // copy constructor
    exampleCopy(st1); // copy constructor

    Student st4(1000, 25, nullptr);
    Student st5(1000000, 23, nullptr);
    st4 = st5; // operator =


    DynamicArray<Student, short> group(20);
    group.addElement(st1);
    group.addElement(st2);
    std::cout << group.getSize() <<std::endl;
    //group.print();

    DynamicArray<> defaultArray; // default dynamic array

    DynamicArray<int, short> intArray(10);
    int a = 10, b = 100;
    intArray.addElement(a);
    intArray.addElement(b);

    return 0; // Destructor for st*
}