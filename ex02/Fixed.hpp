#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <iostream>

class Fixed
{
private:
    static const int _fractionalBits = 8;
    int _value;

public:
    Fixed();
    Fixed(const int _value);
    Fixed(const float _value);
    Fixed(const Fixed &other);
    Fixed &operator=(const Fixed &_other);

    ~Fixed();

    int toInt(void) const;
    float toFloat(void) const;
    friend std::ostream &operator<<(std::ostream &out, const Fixed &_fixed);

    static const Fixed &min(Fixed &_fixPoint1, Fixed &_fixPoint2);
    static const Fixed &max(Fixed &_fixPoint1, Fixed &_fixPoint2);
    static const Fixed &min(const Fixed &_fixPoint1, const Fixed &_fixPoint2);
    static const Fixed &max(const Fixed &_fixPoint1, const Fixed &_fixPoint2);

    // Operators.
    friend std::ostream &operator<<(const std::ostream out, const Fixed &other);
    bool operator>(const Fixed &_fixed1) const;
    bool operator>=(const Fixed &_fixed1) const;
    bool operator<(const Fixed &_fixed1) const;
    bool operator<=(const Fixed &_other) const;
};
#endif