/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikoyan <anikoyan@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 23:11:08 by anikoyan          #+#    #+#             */
/*   Updated: 2025/04/30 23:54:03 by anikoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed crossProduct(const Point& a, const Point& b, const Point& p)
{
    Fixed v1x = b.getX() - a.getX();
    Fixed v1y = b.getY() - a.getY();
    Fixed v2x = p.getX() - a.getX();
    Fixed v2y = p.getY() - a.getY();

    return v1x * v2y - v1y * v2x;
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed c1 = crossProduct(a, b, point);
    Fixed c2 = crossProduct(b, c, point);
    Fixed c3 = crossProduct(c, a, point);

    if (c1 == Fixed(0) || c2 == Fixed(0) || c3 == Fixed(0))
        return false;

    bool all_positive = (c1 > Fixed(0)) && (c2 > Fixed(0)) && (c3 > Fixed(0));
    bool all_negative = (c1 < Fixed(0)) && (c2 < Fixed(0)) && (c3 < Fixed(0));

    return all_positive || all_negative;
}
