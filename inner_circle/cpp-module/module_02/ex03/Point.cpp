/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 20:36:03 by siyang            #+#    #+#             */
/*   Updated: 2023/08/17 14:48:00 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.h"

Point::Point()
  : x(0), y(0) {}

Point::Point(const Point& copy)
  : x(copy.x), y(copy.y) {}

Point::Point(const float x, const float y)
  : x(x), y(y) {}

Point& Point::operator=(const Point& copy)
{
    if (this != &copy)
    {
        const_cast<Fixed&>(this->x) = copy.getX();
        const_cast<Fixed&>(this->y) = copy.getY();
    }
    return (*this);
}

const Fixed& Point::getX() const
{
    return (x);
}

const Fixed& Point::getY() const
{
    return (y);
}

Point::~Point() {}

Vec operator-(const Vec& lhs, const Vec& rhs)
{
    Fixed x(lhs.getX() - rhs.getY());
    Fixed y(lhs.getY() - rhs.getY());

    return (Vec(x.toFloat(), y.toFloat()));
}

Fixed operator*(const Vec& lhs, const Vec& rhs)
{
	  Fixed res(lhs.getX() * rhs.getY() - lhs.getY() * rhs.getX());

    return (res);
}
