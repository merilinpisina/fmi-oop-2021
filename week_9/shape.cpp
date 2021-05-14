#include <iostream>
#include <exception>
#include <vector>
#include <fstream>

const unsigned int SQUARE_ID = 1;
const unsigned int TRIANGLE_ID = 2;

class Shape
{
public:
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual void log() const = 0;
    virtual void print() const = 0;

    virtual unsigned int id() const = 0;

    virtual ~Shape() {}

    virtual Shape *clone() const = 0;
};

class Square : public Shape
{
public:
    Square(double side) : a(side) {}
    Square(const Square &other) = default;

    double area() const
    {
        // log();
        return a * a;
    }

    double perimeter() const
    {
        // log();
        return 4 * a;
    }

    void log() const
    {
        std::cout << "using class square..." << std::endl;
    }

    void print() const
    {
        std::cout << "Square: [area] - " << area() << ", [perimeter] - " << perimeter() << std::endl;
    }

    ~Square() {}

    unsigned int id() const
    {
        return ID;
    }

    static unsigned int ID;

    virtual Square *clone() const
    {
        return new (std::nothrow) Square(*this);
    }

private:
    double a;
};

class Triangle : public Shape
{
public:
    Triangle(double side_a, double side_b, double side_c, double height_a) : a(side_a), b(side_b), c(side_c), h_a(height_a) {}
    Triangle(const Triangle &other) = default;

    double area() const
    {
        // log();
        return a * h_a / 2;
    }

    double perimeter() const
    {
        // log();
        return a + b + c;
    }

    void log() const
    {
        std::cout << "using class triangle..." << std::endl;
    }

    void print() const
    {
        std::cout << "Triangle: [area] - " << area() << ", [perimeter] - " << perimeter() << std::endl;
    }

    ~Triangle() {}

    unsigned int id() const
    {
        return ID;
    }

    static unsigned int ID;

    virtual Triangle *clone() const
    {
        return new (std::nothrow) Triangle(*this);
    }

private:
    double a, b, c, h_a;
};

unsigned int Square::ID = SQUARE_ID;
unsigned int Triangle::ID = TRIANGLE_ID;

const unsigned int DEFAULT_CAPACITY = 8;

class ShapeVec
{
public:
    // ShapeVec(unsigned int capacity = DEFAULT_CAPACITY) {}

    ShapeVec(const char *fileName)
    {
        if (!fileName)
        {
            throw std::invalid_argument("empty file name");
        }

        std::ifstream in(fileName);
        if (!in.good())
        {
            throw std::invalid_argument("could not open file");
        }

        size_t size;
        in >> size;

        for (size_t i = 0; i < size; ++i)
        {
            unsigned int currentID;
            in >> currentID;

            const unsigned int helper = currentID;
            switch (currentID)
            {
            case SQUARE_ID:
            {
                double side;
                in >> side;

                Square *new_square = new (std::nothrow) Square(side);
                if (new_square)
                    this->shapes.push_back(new_square);

                break;
            }
            case TRIANGLE_ID:
            {
                double a, b, c, h;
                in >> a >> b >> c >> h;

                Triangle *new_triangle = new (std::nothrow) Triangle(a, b, c, h);
                if (new_triangle)
                {
                    this->shapes.push_back(new_triangle);
                }
                break;
            }
            default:
                throw std::invalid_argument("shape out of scope");
                break;
            }
        }
    }

    ShapeVec(const ShapeVec &other)
    {
        copy(other);
    }

    ShapeVec &operator=(const ShapeVec &other)
    {
        if (this != &other)
        {
            destroy();
            copy(other);
        }
        return *this;
    }

    ~ShapeVec()
    {
        destroy();
    }

    void print() const
    {
        size_t n = shapes.size();
        for (size_t i = 0; i < n; ++i)
        {
            shapes[i]->print();
        }
    }

private:
    unsigned int size, capacity;
    std::vector<Shape *> shapes;

    void copy(const ShapeVec &other)
    {
        this->size = other.size;
        this->capacity = other.capacity;

        size_t n = other.shapes.size();
        for (size_t i = 0; i < n; ++i)
        {
            switch (other.shapes[i]->id())
            {
            case SQUARE_ID:
            {
                Square *new_square = dynamic_cast<Square *>(other.shapes[i]->clone());
                // Square *new_square = new (std::nothrow) Square(Square(*other.shapes[i]));
                if (new_square)
                {
                    this->shapes.push_back(new_square);
                }
                break;
            }
            case TRIANGLE_ID:
            {
                Triangle *new_triangle = dynamic_cast<Triangle *>(other.shapes[i]->clone());
                if (new_triangle)
                {
                    this->shapes.push_back(new_triangle);
                }
                break;
            }
            default:
                throw std::invalid_argument("shape out of scope");
                break;
            }
        }
    }

    void destroy()
    {
        size_t n = shapes.size();
        for (size_t i = 0; i < n; ++i)
        {
            delete shapes[i];
        }
        shapes.clear();
    }
};

void testInterface()
{
    // Shape what; -> error: cannot declare variable ‘what’ to be of abstract type ‘Shape’

    Square square = Square(5);
    Triangle triangle = Triangle(5, 4, 3, 4);

    std::cout << "square area: " << square.area() << std::endl;
    std::cout << "triangle area: " << triangle.area() << std::endl;
}

void testShapeVector()
{
    ShapeVec vec("test_data.txt");
    vec.print();
}

int main()
{

    // testInterface();
    testShapeVector();

    return 0;
}