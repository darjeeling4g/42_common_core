/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 20:36:09 by siyang            #+#    #+#             */
/*   Updated: 2023/08/17 14:44:39 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODULE02_EX03_POINT_H_
#define MODULE02_EX03_POINT_H_

#include "Fixed.h"

enum eDirection
{
    CW,
    CCW,
    COLLINEAR,
};

class Point
{

public:
    Point();
    Point(const Point& copy);
    Point(const float x, const float y);
    Point& operator=(const Point& copy);
    ~Point();
    const Fixed& getX() const;
    const Fixed& getY() const;

private:
    const Fixed x;
    const Fixed y;

};

typedef Point Vec;

Vec operator-(const Vec& lhs, const Vec& rhs);
Fixed operator*(const Vec& lhs, const Vec& rhs);

bool bsp(Point const a, Point const b, Point const c, Point const point);
eDirection getDirection(Vec u, Vec v);

#endif
