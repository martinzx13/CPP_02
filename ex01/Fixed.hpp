#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{

private:
    const static int _fractionalBits = 8;

public:
    Fixed();
    Fixed(const int _value);
    Fixed(const float _value);
    Fixed(const Fixed &_other);
    Fixed& operator=(const Fixed &_other);
    float toFloat(void) const;
    int toInt(void) const;
    ~Fixed();
    friend std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

private:
    int _value;
};

#endif // FIXED_HPP