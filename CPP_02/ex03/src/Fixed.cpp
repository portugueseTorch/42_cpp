#include "../inc/Fixed.hpp"

////// CONSTRUCTORS //////
Fixed::Fixed() {
	_fixed_point = 0;
}

Fixed::Fixed(const int num) {
	_fixed_point = num << _fractional_bits;
}

Fixed::Fixed(const float num) {
	_fixed_point = roundf(num * (1 << _fractional_bits));
}

Fixed::Fixed(const Fixed &obj) {
	_fixed_point = obj.getRawBits();
}

////// DESTRUCTORS //////
Fixed::~Fixed() {
}

////// OPERATOR OVERLOAD //////
Fixed &Fixed::operator=(const Fixed &obj) {
	_fixed_point = obj.getRawBits();
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

////// COMPARISON OPERATORS //////
bool Fixed::operator> (const Fixed &obj) const {
	return _fixed_point > obj.getRawBits();
}

bool Fixed::operator< (const Fixed &obj) const {
	return _fixed_point < obj.getRawBits();
}

bool Fixed::operator>= (const Fixed &obj) const {
	return _fixed_point >= obj.getRawBits();
}

bool Fixed::operator<= (const Fixed &obj) const {
	return _fixed_point <= obj.getRawBits();
}

bool Fixed::operator== (const Fixed &obj) const {
	return _fixed_point == obj.getRawBits();
}

bool Fixed::operator!= (const Fixed &obj) const {
	return _fixed_point != obj.getRawBits();
}

////// ARITHMETIC OPERATORS //////
Fixed Fixed::operator+ (const Fixed &obj) const {
	return Fixed(this->toFloat() + obj.toFloat());
}

Fixed Fixed::operator- (const Fixed &obj) const {
	return Fixed(this->toFloat() - obj.toFloat());
}

Fixed Fixed::operator* (const Fixed &obj) const {
	return Fixed(this->toFloat() * obj.toFloat());
}

Fixed Fixed::operator/ (const Fixed &obj) const {
	return Fixed(this->toFloat() / obj.toFloat());
}

////// INCREMENT OPERATORS //////
Fixed &Fixed::operator++ () {
	_fixed_point++;
	return *this;
}

Fixed Fixed::operator++ (int) {
	Fixed	stash(*this);
	_fixed_point++;
	return stash;
}

Fixed &Fixed::operator--() {
	_fixed_point--;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed	stash(*this);
	_fixed_point--;
	return stash;
}

////// MIN & MAX OPERATORS //////
Fixed &Fixed::min(Fixed &a, Fixed &b) {
	return (b < a ? b : a);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
	return (b < a ? b : a);
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	return (a < b ? b : a);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
	return (a < b ? b : a);
}

