#include "../inc/Fixed.hpp"

////// CONSTRUCTORS //////
Fixed::Fixed() {
	_fixed_point = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num) {
	_fixed_point = num << _fractional_bits;
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float num) {
	_fixed_point = roundf(num * (1 << _fractional_bits));
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &obj) {
	_fixed_point = obj.getRawBits();
	std::cout << "Copy constructor called" << std::endl;
}

////// DESTRUCTORS //////
Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

////// OPERATOR OVERLOAD //////
Fixed &Fixed::operator=(const Fixed &obj) {
	_fixed_point = obj.getRawBits();
	std::cout << "Copy assignment operator called" << std::endl;
	return *this;
}

////// GETTERS AND SETTERS //////
int	Fixed::getRawBits() const {
	return _fixed_point;
}

void Fixed::setRawBits(int const raw) {
	_fixed_point = raw;
}

int Fixed::toInt() const {
	return _fixed_point >> _fractional_bits;
}

float Fixed::toFloat() const {
	return (float)_fixed_point / (1 << _fractional_bits);
}

////// << OVERLOAD //////
std::ostream &operator<<(std::ostream &stream, const Fixed &obj) {
	stream << obj.toFloat();
	return stream;
}
