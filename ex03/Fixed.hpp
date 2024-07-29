/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amel-has <amel-has@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 09:25:57 by amel-has          #+#    #+#             */
/*   Updated: 2024/07/17 09:58:40 by amel-has         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>

class Fixed
{
private:
    int RawBits;
    static const int  fractionalBits = 8;
public:
    Fixed();
    Fixed(const Fixed&);
    Fixed(const int);
    Fixed(const float);
    Fixed   &operator=(const Fixed &);
    bool operator>(const Fixed &)  const;
    bool operator<(const Fixed &)  const;
    bool operator<=(const Fixed &) const;
    bool operator>=(const Fixed &) const;
    bool operator==(const Fixed &) const;
    bool operator!=(const Fixed &) const;
    Fixed operator+(const Fixed &) const;
    Fixed operator-(const Fixed &) const;
    Fixed operator*(const Fixed &) const;
    Fixed operator/(const Fixed &) const;
    Fixed operator++(int);
    Fixed &operator++();
    static Fixed &min(Fixed &,Fixed &);
    static Fixed &max(Fixed &,Fixed &fixe_b);
    static Fixed &min(const Fixed &,const Fixed &);
    static Fixed &max(const Fixed &,const Fixed &);
    Fixed operator--(int);
    Fixed &operator--();
    int getRawBits( void ) const;
    void setRawBits(int const raw );
    float toFloat( void ) const;
    int toInt( void ) const;
    int getFractionalBits() const;
    ~Fixed();
};

std::ostream & operator<<( std::ostream & o, Fixed const & i );

#endif