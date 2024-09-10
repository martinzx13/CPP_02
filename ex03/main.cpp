#include "Point.hpp"
/*
Input: 1

A = (0, 0), B = (10, 30), C = (20, 0), P(10, 15)
Output: Inside

Input: 2

A = (0, 0), B = (10, 30), C = (20, 0), P(30, 15)
Output: Outside

*/
bool bsp(Point const a, Point const b, Point const c, Point const point);

//  (A(1, 2)), (B(4, 6)), and (C(5, 3)):
int main()
{
    Point A(0, 0);
    Point B(10, 30);
    Point C(20, 0);
    Point P(10.0f, 15.0f);

    // Point is inside
    std::cout << "Point P1 : " << bsp(A, B, C, P) << std::endl; // Expected false

    // Point is on edge AB
    Point P4(5.0f, 15.0f);
    std::cout << "Point P4 on edge AB: " << bsp(A, B, C, P4) << std::endl; // Expected false

    // Point is on edge BC
    Point P5(15.0f, 15.0f);
    std::cout << "Point P5 on edge BC: " << bsp(A, B, C, P5) << std::endl; // Expected false

    // Point is on edge CA
    Point P6(10.0f, 0.0f);
    std::cout << "Point P6 on edge CA: " << bsp(A, B, C, P6) << std::endl; // Expected false

    // bsp(A, B, C, P);

    // Point is exactly at vertex A
    Point P1(0.0f, 0.0f);
    std::cout << "Point P1 at vertex A: " << bsp(A, B, C, P1) << std::endl; // Expected false

    // Point is exactly at vertex B
    Point P2(10.0f, 30.0f);
    std::cout << "Point P2 at vertex B: " << bsp(A, B, C, P2) << std::endl; // Expected false

    // Point is exactly at vertex C
    Point P3(20.0f, 0.0f);
    std::cout << "Point P3 at vertex C: " << bsp(A, B, C, P3) << std::endl; // Expected false

    return (0);
}