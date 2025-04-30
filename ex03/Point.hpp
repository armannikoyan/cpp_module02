/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 23:10:59 by anikoyan          #+#    #+#             */
/*   Updated: 2025/04/30 23:59:45 by anikoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Fixed.hpp"

class Point
{
  private:
    const Fixed x_;
    const Fixed y_;

  public:
    Point();
    Point(const Fixed&, const Fixed&);
    ~Point();
    Point(const Point&);
    Point& operator=(const Point&);

    const Fixed& getX() const;
    const Fixed& getY() const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);
