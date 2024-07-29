/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amel-has <amel-has@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 06:13:02 by amel-has          #+#    #+#             */
/*   Updated: 2024/07/16 03:51:09 by amel-has         ###   ########.fr       */
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
    Fixed &operator=(const Fixed &);
    int getRawBits( void ) const;
    void setRawBits(int const raw );
    ~Fixed();
};

#endif