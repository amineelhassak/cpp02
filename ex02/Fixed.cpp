#include "Fixed.hpp"

Fixed::Fixed():RawBits(0) {
            }
            
Fixed::Fixed(const int integerValue):RawBits(integerValue << Fixed::fractionalBits) {
            }

Fixed::Fixed(const float floatValue):RawBits(roundf(floatValue * (1 << Fixed::fractionalBits))) {
            }

Fixed::Fixed(const Fixed& fixed)    {
    *this = fixed;
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
    if (this != &fixed)
        this->RawBits = fixed.getRawBits();
    return (*this);
        }

float Fixed::toFloat( void ) const  {
    return ((float)this->RawBits / (1 << Fixed::fractionalBits));
}

int Fixed::toInt( void ) const  {
    return (this->RawBits >> Fixed::fractionalBits);
}

int Fixed::getRawBits( void ) const {
    return (this->RawBits) ;
}

void Fixed::setRawBits( int const raw ) {
    this->RawBits = raw ;
}

std::ostream & operator<<( std::ostream & o, Fixed const & i ) {
    return (o << i.toFloat() ,o);
}

Fixed::~Fixed() {
            }

bool Fixed::operator>(const Fixed & fixed) const {
    return (this->getRawBits() > fixed.getRawBits());
}

bool Fixed::operator<(const Fixed &fixed) const {
        return (this->getRawBits() < fixed.getRawBits());
}

bool Fixed::operator<=(const Fixed &fixed) const {
        return (this->getRawBits() <= fixed.getRawBits());        
}

bool Fixed::operator>=(const Fixed &fixed) const {
    return (this->getRawBits() >= fixed.getRawBits());
}

bool Fixed::operator==(const Fixed &fixed) const {
    return (this->getRawBits() == fixed.getRawBits());
}
bool Fixed::operator!=(const Fixed &fixed) const {
    return (this->getRawBits() != fixed.getRawBits());
}

Fixed Fixed::operator+(const Fixed &fixed)  const{
    return Fixed(this->toFloat() + fixed.toFloat());
}

Fixed Fixed::operator-(const Fixed &fixed)  const{
    return Fixed(this->toFloat() - fixed.toFloat());
}

Fixed Fixed::operator*(const Fixed &fixed)  const{
    return Fixed(this->toFloat() * fixed.toFloat());
}

Fixed Fixed::operator/(const Fixed &fixed)  const{
    return Fixed(this->toFloat() / fixed.toFloat());
}

Fixed &Fixed::operator++( void )    {
    return ((this->RawBits)++, *this);
}

Fixed Fixed::operator++( int )  {
    Fixed tmp(*this);
    return ((this->RawBits)++, tmp);
}

Fixed &Fixed::operator--( void )    {
    return ((this->RawBits)--, *this);
}

Fixed Fixed::operator--( int )  {
    Fixed tmp(*this);
    return ((this->RawBits)--, tmp);
}

Fixed &Fixed::min(Fixed &fixe_a,Fixed &fixe_b)  {
    return (fixe_a < fixe_b ? fixe_a : fixe_b);
}

Fixed &Fixed::max(Fixed &fixe_a,Fixed &fixe_b)  {
    return (fixe_a > fixe_b ? fixe_a : fixe_b);
}

Fixed &Fixed::min(const Fixed &fixe_a, const Fixed &fixe_b) {
    return (Fixed &)(fixe_a < fixe_b ? fixe_a : fixe_b);
}

Fixed &Fixed::max(const Fixed &fixe_a, const Fixed &fixe_b) {
    return (Fixed &)(fixe_a > fixe_b ? fixe_a : fixe_b);
}