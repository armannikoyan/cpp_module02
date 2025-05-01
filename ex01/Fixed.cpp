/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 18:26:14 by anikoyan          #+#    #+#             */
/*   Updated: 2025/05/01 18:37:45 by anikoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::fp_fraction_ = 8;

Fixed::Fixed()
{
  std::cout << "Default constructor called\n";
  fp_value_ = 0;
}

Fixed::Fixed(const int value)
{
  std::cout << "Int constructor called\n";
  fp_value_ = value << fp_fraction_;
}

Fixed::Fixed(const float value)
{
  std::cout << "Float constructor called\n";
  fp_value_ = roundf(value * (1 << fp_fraction_));
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

std::ostream& operator<<(std::ostream& os, const Fixed& fp)
{
  os << fp.toFloat();
  return os;
}

int Fixed::getRawBits() const
{
  std::cout << "getRawBits member function called\n";
  return fp_value_;
}

void Fixed::setRawBits( int const raw )
{
  std::cout << "setRawBits member function called\n";
  this->fp_value_ = raw;
}

float Fixed::toFloat() const
{
  return (float)fp_value_ / (float)(1 << fp_fraction_);
}

int Fixed::toInt() const
{
  return fp_value_ >> fp_fraction_;
}
