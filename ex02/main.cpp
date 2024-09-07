#include "Fixed.hpp"

int main(void)
{
    Fixed a;
    Fixed const b(10);

    std::cout << "The min is : " << Fixed::min(a, b) << std::endl;
    std::cout << "The max is : " << Fixed::max(a, b) << std::endl;
}