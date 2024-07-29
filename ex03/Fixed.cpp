/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amel-has <amel-has@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 06:12:58 by amel-has          #+#    #+#             */
/*   Updated: 2024/07/17 09:58:52 by amel-has         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed():RawBits(0) {
            // std::cout << "Default constructor called" << std::endl;
            }
            
Fixed::Fixed(const int integerValue):RawBits(integerValue << Fixed::fractionalBits) {
            // std::cout << "Int constructor called" << std::endl;
            }

Fixed::Fixed(const float floatValue):RawBits(roundf(floatValue * (1 << Fixed::fractionalBits))){
            // std::cout << "Float constructor called" << std::endl;
            }

Fixed::Fixed(const Fixed& fixed)
{
    // std::cout << "Copy constructor called" << std::endl;
    *this = fixed;
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
    // std::cout << "Copy assignment operator called" << std::endl;
    if (this != &fixed)
        this->RawBits = fixed.getRawBits();
    return (*this);
        }

float Fixed::toFloat( void ) const
{
    return ((float)this->RawBits / (1 << Fixed::fractionalBits));
    
}

int Fixed::toInt( void ) const
{
    return (this->RawBits >> Fixed::fractionalBits);
}

int Fixed::getRawBits( void ) const {
    return (this->RawBits) ;
}

void Fixed::setRawBits( int const raw ) {
    this->RawBits = raw ;
}

std::ostream & operator<<( std::ostream & o, Fixed const & i ) {
    o << i.toFloat();
    return o;
}

Fixed::~Fixed() {
    // std::cout << "Destructor called" << std::endl;
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
// l'opérateur ternaire
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

int Fixed::getFractionalBits() const
{
    return (Fixed::fractionalBits);
}