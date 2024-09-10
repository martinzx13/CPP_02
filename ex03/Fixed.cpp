#include "Fixed.hpp"

// Constructors.

Fixed::Fixed() : _value(0)
{
    // std::cout << "Standart constructor called" << std::endl;
}

Fixed::Fixed(const int _value)
{
    // std::cout << "Integer constructor called" << std::endl;
    this->_value = _value << _fractionalBits;
}

Fixed::Fixed(const float _value)
{
    // std::cout << "Float constructor called" << std::endl;
    this->_value = roundf(_value * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed &_other)
{
    // std::cout << "Copy constructor Called " << std::endl;
    this->_value = _other._value;
}

Fixed &Fixed::operator=(const Fixed &_other)
{
    if (this != &_other)
        this->_value = _other._value;
    return (*this);
}

// Destructor.
Fixed::~Fixed()
{
    // std::cout << "Default destructor called" << std::endl;
}

// Conversors.
float Fixed::toFloat(void) const
{
    return (static_cast<float>(_value) / (1 << _fractionalBits));
}

int Fixed::toInt(void) const
{
    return (_value >> _fractionalBits);
}

// Calculation Functions.
const Fixed &Fixed::min(const Fixed &_fixPoint1, const Fixed &_fixPoint2)
{
    std::cout << "The min comparison is called" << std::endl;
    return (_fixPoint1 < _fixPoint2) ? _fixPoint1 : _fixPoint1;
}
const Fixed &Fixed::max(const Fixed &_fixPoint1, const Fixed &_fixPoint2)
{
    std::cout << "This is the max const comparison" << std::endl;
    return (_fixPoint1 > _fixPoint2) ? _fixPoint1 : _fixPoint2;
}
// Operators of comparison.

std::ostream &operator<<(std::ostream &out, const Fixed &_fixed)
{
    out << _fixed.toFloat();
    return out;
}
bool Fixed::operator==(const Fixed &_other) const
{
    return(this->_value == _other._value);
}

bool Fixed::operator||(const Fixed &_other) const
{
    return (this->_value || _other._value);
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

// Aritmetic Operators.
Fixed Fixed::operator+(const Fixed &_other) const
{
    Fixed result;

    result._value = this->_value + _other._value;
    return (result);
}

Fixed Fixed::operator-(const Fixed &_other) const
{
    Fixed result;
    result._value = this->_value - _other._value;
    return (result);
}

Fixed Fixed::operator*(const Fixed &_other) const
{
    Fixed result;
    result._value = (this->_value * _other._value) >> _fractionalBits;
    return (result);
}

Fixed Fixed::operator/(const Fixed &_other) const
{
    Fixed result;

    result._value = (this->_value<< _fractionalBits) / _other._value;
    return (result);
}

// Increment operators.

Fixed Fixed::operator++( void )
{
    this->_value++;
    return (*this);
}

Fixed Fixed::operator++( int )
{
    Fixed temp;
    temp = *this;
    ++(*this);
    return(temp);
}

Fixed Fixed::operator--( void )
{
    this->_value--;
    return (*this);
}

Fixed Fixed::operator--( int )
{
    Fixed temp;

    temp = *this;
    --(*this);
    return (temp);
}