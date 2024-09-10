#include "Fixed.hpp"
#include "Point.hpp"

void printTriangle(Point const A, Point const B, Point const C, Point const P, bool i)
{
    std::cout << "Input: P(" << P.getPointX() << ", " << P.getPointY() << ")" << std::endl;
    std::cout << "A = (" << A.getPointX() << ", " << A.getPointY() << "), "
              << "B = (" << B.getPointX() << ", " << B.getPointY() << "), "
              << "C = (" << C.getPointX() << ", " << C.getPointY() << ")" << std::endl;

    std::cout << "Output: " << (i ? "inside" : "outside") << std::endl;

    std::cout << "Explanation:\n\n";
    std::cout << "              B(" << B.getPointX() << "," << B.getPointY() << ")\n";
    std::cout << "                / \\\n";
    std::cout << "               /   \\\n";
    std::cout << "              /     \\\n";
    std::cout << "             /       \\      P(" << P.getPointX() << "," << P.getPointY() << ")\n";
    std::cout << "            /         \\\n";
    std::cout << "     A(" << A.getPointX() << "," << A.getPointY() << ") ----------- C(" << C.getPointX() << "," << C.getPointY() << ")\n\n";
}
// Function to calculate the main Area.

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed AreaTotal;
    Fixed AreaPoint;
    Fixed AreaTotal1;
    Fixed AreaTotal2;
    Fixed AreaTotal3;

    AreaTotal = Point::AreaCalculation(a, b, c);
    AreaTotal1 = Point::AreaCalculation(point, b, c);
    AreaTotal2 = Point::AreaCalculation(point, c, a);
    AreaTotal3 = Point::AreaCalculation(point, a, b);

    AreaPoint = AreaTotal1 + AreaTotal2 + AreaTotal3;

    if (AreaTotal1 == Fixed(0) ||
        AreaTotal2 == Fixed(0) ||
        AreaTotal3 == Fixed(0))
    {
        printTriangle(a, b, c, point, false);
        return (false);
    }
    else if (AreaPoint == AreaTotal)
    {
        printTriangle(a, b, c, point, true);
        return (true);
    }
    printTriangle(a, b, c, point, false);
    return (false);
}