/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 18:22:52 by anikoyan          #+#    #+#             */
/*   Updated: 2025/04/30 23:59:36 by anikoyan         ###   ########.fr       */
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

    bool operator<(const Fixed&);
    bool operator>(const Fixed&);
    bool operator<=(const Fixed&);
    bool operator>=(const Fixed&);
    bool operator==(const Fixed&);
    bool operator!=(const Fixed&);

    bool operator<(const Fixed& other) const;
    bool operator>(const Fixed& other) const;
    bool operator<=(const Fixed& other) const;
    bool operator>=(const Fixed& other) const;
    bool operator==(const Fixed& other) const;
    bool operator!=(const Fixed& other) const;

    Fixed operator+(const Fixed&);
    Fixed operator-(const Fixed&);
    Fixed operator*(const Fixed&);
    Fixed operator/(const Fixed&);

    Fixed operator+(const Fixed&) const;
    Fixed operator-(const Fixed&) const;
    Fixed operator*(const Fixed&) const;
    Fixed operator/(const Fixed&) const;

    Fixed& operator++();
    Fixed& operator--();
    Fixed operator++(int);
    Fixed operator--(int);

    static const Fixed& min(const Fixed&, const Fixed&);
    static const Fixed& max(const Fixed&, const Fixed&);

    static Fixed& min(Fixed&, Fixed&);
    static Fixed& max(Fixed&, Fixed&);
};

std::ostream& operator<<(std::ostream& os, const Fixed&);
