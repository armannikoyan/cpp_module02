/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 23:10:55 by anikoyan          #+#    #+#             */
/*   Updated: 2025/05/01 00:35:32 by anikoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point()
  : x_(0)
  , y_(0) {}

Point::Point(const Fixed& x, const Fixed& y)
  : x_(x)
  , y_(y) {}

Point::~Point() {}

Point::Point(const Point& other)
  : x_(other.x_)
  , y_(other.y_) {}

Point& Point::operator=(const Point& other)
{
  if (this != &other)
    throw std::runtime_error("WTF are you doing bro, its const!");
  return *this;
}

const Fixed& Point::getX() const { return x_; }
const Fixed& Point::getY() const { return y_; }
