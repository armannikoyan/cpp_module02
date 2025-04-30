/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 18:22:52 by anikoyan          #+#    #+#             */
/*   Updated: 2025/05/01 00:00:50 by anikoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cmath>

class Fixed
{
  private:
    int fp_value_;
    static const int fp_fraction_;

  public:
    Fixed();
    Fixed(const int);
    Fixed(const float);
    ~Fixed();
    Fixed(const Fixed&);
    Fixed& operator=(const Fixed&);

    int getRawBits( void ) const;
    void setRawBits( int const raw );

    float toFloat( void ) const;
    int toInt( void ) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed&);
