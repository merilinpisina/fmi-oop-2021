#ifndef LINKED_LIST_EXAMPLE
#define LINKED_LIST_EXAMPLE

#include <iostream>
#include <cstring>
#include <exception>
#include <fstream>
#include <cassert>

int size(const char *arr)
{
    // if (*arr == '\0') -> return
    // -> 1 + size(++arr)
    int s = 0;
    if (arr == nullptr)
        return s;

    for (int i = 0; arr[i] != '\0'; ++i)
    {
        ++s;
    }
    return s;
}

class Contact
{
public:
    Contact(const char *_name = "", const char *_phone = "", Contact *_next = nullptr) : next(_next) {
        setName(_name); 
        setPhone(_phone);
    }

    ~Contact()
    {
        destroy();
    }

    Contact &operator=(const Contact &other)
    {
        if (this != &other)
        {
            destroy();
            copy(other);
        }
        return *this;
    }

    Contact(const Contact &other)
    {
        copy(other);
    }

    void setName(const char *_name)
    {
        this->name = new (std::nothrow) char[size(_name) + 1];
        if (this->name == nullptr)
        {
            throw std::bad_alloc();
        }

        std::memcpy(this->name, _name, size(_name) + 1);
    }

    void setPhone(const char *_phone)
    {
        this->phone = new (std::nothrow) char[size(_phone) + 1];
        if (this->phone == nullptr)
        {
            throw std::bad_alloc();
        }

        std::memcpy(this->phone, _phone, size(_phone) + 1);
    }

	friend std::istream& operator>>(std::istream& in, Contact& element);
	friend std::ostream& operator<<(std::ostream& out, const Contact& element);

public: 
    Contact *next;

private:
    char *name;
    char *phone;

    void copy(const Contact &other)
    {
        setName(other.name);
        setPhone(other.phone);
    }

    void destroy()
    {
        delete[] name;
        delete[] phone;
        // next = nullptr;
    }
};

std::istream& operator>>(std::istream& in, Contact& element) {
    char from_file[128], from_file_2[128];
    in >> from_file;
    std::cout << from_file <<std::endl;
    element.setName(from_file);

    in >> from_file_2;
    std::cout << from_file_2 <<std::endl;
    element.setPhone(from_file_2);
    return in;
}

class PhoneBook
{
public:
    PhoneBook(): head(nullptr), end(nullptr), size(0) {}

    PhoneBook(const PhoneBook &);
    PhoneBook &operator=(const PhoneBook &);

    ~PhoneBook()
    {
        if (size > 0)
        {
            Contact *temp = nullptr;
            while (size && head)
            {
                temp = head->next;
                delete head;
                head = temp;
                --size;
            }
        }
    }

    void push_front(Contact *new_node)
    {
        // Contact* temp = new (std::nothrow) Contact(new_node);
        // if (temp == nullptr) {
        //     throw std::bad_alloc();
        // }
        // temp->next = head;
        // head = temp;
        // ++size;

        new_node->next = head;
        head = new_node;
        ++size;
    }

    void push_front(const char *name, const char *phone)
    {
        Contact *new_node = new (std::nothrow) Contact(name, phone, head);
        if (new_node == nullptr)
        {
            throw std::bad_alloc();
        }
        head = new_node;
        ++size;
    }

    void push_back(Contact *new_node)
    {
        std::cout << "Pushing..\n";
        if (size == 0) {
            head = end = new_node;
        } else if (size == 1){
            head->next = new_node;
            end = new_node;
        } else {
            end->next = new_node;
            end = new_node;
        }
        ++size;
        std::cout << "Pushed\n";
    }

    void push_back(const char *name, const char *phone)
    {
        Contact *new_node = new (std::nothrow) Contact(name, phone);
        if (new_node == nullptr)
        {
            throw std::bad_alloc();
        }
        push_back(new_node);
        // end->next = new_node;
        // end = new_node;
        // ++size;
    }

    void pop_front()
    {
        if (size > 0)
        {
            Contact *temp = head->next;
            delete head;
            head = temp;
            --size;
        }

        // Contact *temp = head;
        // head = head->next;
        // delete temp;
    }

    void pop_back()
    {
        if (size > 0)
        {
            Contact *temp = head;
            while (temp->next != end)
            {
                temp = temp->next;
            }

            delete end; // nullptr
            end = temp;
            end->next = nullptr; // optional
            --size;
        }
    }

    // insert
    // []
    // at

    void read(const char* file_name) {
        assert(file_name != nullptr);

        std::ifstream in(file_name, std::ios::in);
        if (!in.good()) {
            throw std::invalid_argument("Could not open file!");
        }

        while(!in.eof()) {
            Contact *new_node = new (std::nothrow) Contact();
            in >> (*new_node);
            this->push_back(new_node);
        }
    }

private:
    Contact *head, *end;
    size_t size;
};

#endif