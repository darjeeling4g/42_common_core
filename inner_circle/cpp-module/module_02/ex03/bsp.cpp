/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 20:40:23 by siyang            #+#    #+#             */
/*   Updated: 2023/08/17 18:10:45 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.h"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    eDirection direction = getDirection(Vec(a - b), Vec(a - point));
    if (direction == COLLINEAR)
    {
        return (false);
    }
    if (direction != getDirection(Vec(a - point), Vec(a - c)))
    {
        return (false);
    }
    if (direction != getDirection(Vec(b - c), Vec(b - point)))
    {
        return (false);
    }
    if (direction != getDirection(Vec(b - point), Vec(b - a)))
    {
        return (false);
    }
    return (true);
}

eDirection getDirection(Vec u, Vec v)
{
    Fixed discriminant = u * v;

    if (discriminant > 0)
    {
        return (CW);
    }
    else if (discriminant < 0)
    {
        return (CCW);
    }
    return (COLLINEAR);
}
