/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_drawing_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:02:47 by siyang            #+#    #+#             */
/*   Updated: 2023/01/17 07:52:45 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	make_palette(t_palette *p, t_pixel *pixel, t_pixel *next)
{
	p->x1 = pixel->x;
	p->y1 = pixel->y;
	p->x2 = next->x;
	p->y2 = next->y;
	p->m = coordinate_init(&p->x1, &p->y1, &p->x2, &p->y2);
	p->w = p->x2 - p->x1;
	p->h = p->y2 - p->y1;
	p->f = 2 * p->h - p->w;
	p->r = pixel->r;
	p->g = pixel->g;
	p->b = pixel->b;
	p->n_r = next->r;
	p->n_g = next->g;
	p->n_b = next->b;
}

double	coordinate_init(double *x1, double *y1, double *x2, double *y2)
{
	double	m;

	if (*x2 < *x1)
		swap_coordinate(x1, x2, y1, y2);
	if (*x2 == *x1 && *y2 > *y1)
		m = 2;
	else if (*x2 == *x1 && *y2 < *y1)
		m = -2;
	else if (*y2 == *y1)
		m = 0;
	else
		m = (*y2 - *y1) / (*x2 - *x1);
	if (m > 1)
		y_equal_x_symmetry(x1, x2, y1, y2);
	else if (m < 0)
	{
		x_axis_symmetry(y1, y2);
		if (m < -1)
			y_equal_x_symmetry(x1, x2, y1, y2);
	}
	return (m);
}

void	swap_coordinate(double *x1, double *x2, double *y1, double *y2)
{
	double	temp;

	temp = *x1;
	*x1 = *x2;
	*x2 = temp;
	temp = *y1;
	*y1 = *y2;
	*y2 = temp;
}

void	x_axis_symmetry(double *y1, double *y2)
{
	*y1 *= -1;
	*y2 *= -1;
}

void	y_equal_x_symmetry(double *x1, double *x2, double *y1, double *y2)
{
	double	temp;

	temp = *x1;
	*x1 = *y1;
	*y1 = temp;
	temp = *x2;
	*x2 = *y2;
	*y2 = temp;
}
