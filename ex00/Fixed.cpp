/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 18:26:14 by anikoyan          #+#    #+#             */
/*   Updated: 2025/04/30 18:34:46 by anikoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::fp_fraction_ = 8;

Fixed::Fixed()
{
  std::cout << "Default constructor called\n";
  fp_value_ = 0;
}
Fixed::~Fixed()
{
  std::cout << "Destructor called\n";
}
Fixed::Fixed(const Fixed& other)
{
  std::cout << "Copy constructor called\n";
  *this = other;
}
Fixed& Fixed::operator=(const Fixed& other)
{
  std::cout << "Copy assignment operator called\n";
  if (this != &other)
    this->fp_value_ = other.getRawBits();
  return *this;
}

int Fixed::getRawBits() const
{
  std::cout << "getRawBits member function called\n";
  return fp_value_;
}

void Fixed::setRawBits( int const raw )
{
  this->fp_value_ = raw;
}
