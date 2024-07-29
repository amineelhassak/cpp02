/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amel-has <amel-has@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 06:12:58 by amel-has          #+#    #+#             */
/*   Updated: 2024/07/16 03:50:59 by amel-has         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed():RawBits(0) {
            std::cout << "Default constructor called" << std::endl;
            }

Fixed &Fixed::operator=(const Fixed &fixed)   {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &fixed)
        this->RawBits = fixed.getRawBits();
    return (*this);
        }
Fixed::Fixed(const Fixed& fixed)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = fixed;
}

int Fixed::getRawBits( void ) const {
    std::cout << "getRawBits member function called" << std::endl;
    return (this->RawBits) ;
}

void Fixed::setRawBits( int const raw ) {
    this->RawBits = raw ;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
            }
