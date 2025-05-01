/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 18:26:14 by anikoyan          #+#    #+#             */
/*   Updated: 2025/05/01 18:38:36 by anikoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::fp_fraction_ = 8;

Fixed::Fixed()
{
  fp_value_ = 0;
}

Fixed::Fixed(const int value)
{
  fp_value_ = value << fp_fraction_;
}

Fixed::Fixed(const float value)
{
  fp_value_ = roundf(value * (1 << fp_fraction_));
}

Fixed::~Fixed() {}

Fixed::Fixed(const Fixed& other)
{
  *this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
  if (this != &other)
    this->fp_value_ = other.getRawBits();
  return *this;
}

bool Fixed::operator<(const Fixed& other)
{
  return this->toFloat() < other.toFloat();
}

bool Fixed::operator>(const Fixed& other)
{
  return this->toFloat() > other.toFloat();
}

bool Fixed::operator<=(const Fixed& other)
{
  return this->toFloat() <= other.toFloat();
}

bool Fixed::operator>=(const Fixed& other)
{
  return this->toFloat() >= other.toFloat();
}

bool Fixed::operator==(const Fixed& other)
{
  return this->toFloat() == other.toFloat();
}

bool Fixed::operator!=(const Fixed& other)
{
  return this->toFloat() != other.toFloat();
}

bool Fixed::operator<(const Fixed& other) const
{
  return this->toFloat() < other.toFloat();
}

bool Fixed::operator>(const Fixed& other) const
{
  return this->toFloat() > other.toFloat();
}

bool Fixed::operator<=(const Fixed& other) const
{
  return this->toFloat() <= other.toFloat();
}

bool Fixed::operator>=(const Fixed& other) const
{
  return this->toFloat() >= other.toFloat();
}

bool Fixed::operator==(const Fixed& other) const
{
  return this->toFloat() == other.toFloat();
}

bool Fixed::operator!=(const Fixed& other) const
{
  return this->toFloat() != other.toFloat();
}

Fixed Fixed::operator+(const Fixed& other)
{
  Fixed fp(this->toFloat() + other.toFloat());

  return fp;
}

Fixed Fixed::operator-(const Fixed& other)
{
  Fixed fp(this->toFloat() - other.toFloat());

  return fp;
}

Fixed Fixed::operator*(const Fixed& other)
{
  Fixed fp(this->toFloat() * other.toFloat());

  return fp;
}

Fixed Fixed::operator/(const Fixed& other)
{
  float divisor = other.toFloat();
  
  if (divisor == 0.f)
  {
    throw std::runtime_error("Math error: Attempted to divide by Zero\n");
  }
  Fixed fp(this->toFloat() / divisor);

  return fp;
}

Fixed Fixed::operator+(const Fixed& other) const
{
  Fixed fp(this->toFloat() + other.toFloat());

  return fp;
}

Fixed Fixed::operator-(const Fixed& other) const
{
  Fixed fp(this->toFloat() - other.toFloat());

  return fp;
}

Fixed Fixed::operator*(const Fixed& other) const
{
  Fixed fp(this->toFloat() * other.toFloat());

  return fp;
}

Fixed Fixed::operator/(const Fixed& other) const
{
  float divisor = other.toFloat();
  
  if (divisor == 0.f)
  {
    throw std::runtime_error("Math error: Attempted to divide by Zero\n");
  }
  Fixed fp(this->toFloat() / divisor);

  return fp;
}

Fixed& Fixed::operator++()
{
  ++fp_value_;
  return *this;
}

Fixed& Fixed::operator--()
{
  ++fp_value_;
  return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed fp(*this);

    ++(*this);
    return fp;
}

Fixed Fixed::operator--(int)
{
    Fixed fp(*this);

    --(*this);
    return fp;
}

int Fixed::getRawBits() const
{
  return fp_value_;
}

void Fixed::setRawBits( int const raw )
{
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

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
  return (a.toFloat() < b.toFloat()) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
  return (a.toFloat() > b.toFloat()) ? a : b;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
  return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
  return (a > b) ? a : b;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fp)
{
  os << fp.toFloat();
  return os;
}
