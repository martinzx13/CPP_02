#include "Point.hpp"

// Constructor, to initialze the structure.

// the calculation will follow this formula.

// A = 1/2(x1(y2 - y3) + x2(y3 - y1) + x3(y1 - y2))

Point::Point() : x(0), y(0)
{
    // std::cout << "Default constructor called " << std::endl;
}
Point::Point(const float float1, const float float2) : x(float1), y(float2)
{
    // std::cout << "Parameterized constructor called " << std::endl;
}

Point::Point(const Point &_other) : x(_other.x), y(_other.y)
{
    // std::cout << "copy  called" << std::endl;
}
Point::~Point()
{
    // std::cout << "Destructor called " << std::endl;
}

Fixed Point::getPointX() const
{
    return (x);
}

Fixed Point::getPointY() const
{
    return (y);
}

Fixed Point::AreaCalculation(Point A, Point B, Point C)
{
    Fixed Area;
    Fixed const absolut(-1);
    Fixed half(0.5f);

    Fixed val1;
    Fixed val2;
    Fixed val3;

    val1 = A.getPointX() * (B.getPointY() - C.getPointY());
    val2 = B.getPointX() * (C.getPointY() - A.getPointY());
    val3 = C.getPointX() * (A.getPointY() - B.getPointY());

    Area = half * (val1 + val2 + val3);
    if (Area < 0)
        Area = absolut * Area;

    return (Area);
}