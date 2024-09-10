#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"
#include <iostream>

class Point
{
private:
    Fixed const x;
    Fixed const y;

public:
    Point();
    Point(const float float1, const float float2);
    Point(const Point &_other);
    ~Point();
    Fixed getPointX() const;
    Fixed getPointY() const;
    static Fixed AreaCalculation(Point A, Point B, Point C);
};

#endif