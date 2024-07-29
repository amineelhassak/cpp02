/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amel-has <amel-has@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 06:13:02 by amel-has          #+#    #+#             */
/*   Updated: 2024/07/15 22:41:05 by amel-has         ###   ########.fr       */
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
    Fixed &operator=(const Fixed &);
    int getRawBits( void ) const;
    void setRawBits(int const raw );
    float toFloat( void ) const;
    int toInt( void ) const;
    ~Fixed();
};

std::ostream & operator<<( std::ostream & o, Fixed const & i );

#endif