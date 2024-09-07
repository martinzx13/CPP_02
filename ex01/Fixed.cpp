#include "Fixed.hpp"

Fixed::Fixed(void) : _value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int _value)
{
    std::cout << "Int constructor called" << std::endl;
    this->_value = _value << _fractionalBits;
}

Fixed::Fixed(const float _value)
{
    std::cout << "Float constructor called" << std::endl;
    this->_value = roundf(_value * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed &_other)
{
    std::cout << "Copy constructor called" << std::endl;
    this->_value = _other._value;
}

Fixed &Fixed::operator=(const Fixed &_other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &_other)
        this->_value = _other._value;
    return (*this);
}
int Fixed::toInt(void) const
{
    return (_value >> this->_fractionalBits);
}

float Fixed::toFloat(void) const
{
    return (static_cast<float>(_value) / (1 << _fractionalBits));
}
std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return (out);
}
Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}