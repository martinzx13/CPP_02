#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
    std::cout << "Standart constructor called" << std::endl;
}

Fixed::Fixed(const int _value)
{
    std::cout << "Integer constructor called" << std::endl;
    this->_value = _value << _fractionalBits;
}

Fixed::Fixed(const float _value)
{
    std::cout << "Float constructor called" << std::endl;
    this->_value = roundf(_value * (1 << _fractionalBits));
}
const Fixed &Fixed::min(const Fixed &_fixPoint1, const Fixed &_fixPoint2)
{
    std::cout << "The min comparison is called" << std::endl;
    return (_fixPoint1 < _fixPoint2) ? _fixPoint1 : _fixPoint1;
}

std::ostream &operator<<(const std::ostream &out, const Fixed &_other)
{
    out<<_other._value;
}

bool Fixed::operator>(const Fixed &_other) const
{
    return (this->_value > _other._value);
}

bool Fixed::operator<(const Fixed &_other) const
{
    return (this->_value < _other._value);
}

bool Fixed::operator>=(const Fixed &_other) const
{
    return (this->_value >= _other._value);
}

bool Fixed::operator<=(const Fixed &_other) const
{
    return (this->_value <= _other._value);
}
const Fixed &Fixed::max(const Fixed &_fixPoint1, const Fixed &_fixPoint2)
{
    std::cout << "This is the max const comparison" << std::endl;
    return (_fixPoint1 > _fixPoint2) ? _fixPoint1 : _fixPoint2;
}
Fixed::~Fixed()
{
    std::cout << "Default destructor called" << std::endl;
}
