/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_drawing_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:02:47 by siyang            #+#    #+#             */
/*   Updated: 2023/01/13 21:01:17 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	bresenham(t_image *img, t_pixel *pixel, t_pixel *next)
{
	t_palette	p;

	make_palette(&p, pixel, next);
	while (p.x1 <= p.x2)
	{
		if (p.F < 0)
			p.F += 2 * p.H;
		else if (p.F > 0)
		{
			p.y1++;
			p.F += 2 * (p.H - p.W);
		}
		if (p.m >= 0 && p.m <= 1)
			draw_pixel(img, &p, p.x1, p.y1);
		else if (p.m > 1)
			draw_pixel(img, &p, p.y1, p.x1);
		else if (p.m >= -1 && p.m < 0)
			draw_pixel(img, &p, p.x1, -1 * p.y1);
		else if (p.m < -1)
			draw_pixel(img, &p, p.y1, -1 * p.x1);
		p.x1++;
	}
}

void	make_palette(t_palette *p, t_pixel *pixel, t_pixel *next)
{
	p->x1 = pixel->x;
	p->y1 = pixel->y;
	p->x2 = next->x;
	p->y2 = next->y;
	p->a = pixel->a;
	p->r = pixel->r;
	p->g = pixel->g;
	p->b = pixel->b;
	p->m = bresenham_init(&p->x1, &p->y1, &p->x2, &p->y2);
	p->W = p->x2 - p->x1;
	p->H = p->y2 - p->y1;
	p->F = 2 * p->H - p->W;

}

double	bresenham_init(double *x1, double *y1, double *x2, double *y2)
{
	double	temp;
	double	m;

	if (*x2 < *x1)
	{
		temp = *x1;
		*x1 = *x2;
		*x2 = temp;
		temp = *y1;
		*y1 = *y2;
		*y2 = temp;
	}
	if (*x2 == *x1 && *y2 > *y1)
		m = 2;
	else if (*x2 == *x1 && *y2 < *y1)
		m = -2;
	else if (*y2 == *y1)
		m = 0;
	else
		m = (*y2 - *y1) / (*x2 - *x1);
	if (m > 1)
	{
		temp = *x1;
		*x1 = *y1;
		*y1 = temp;
		temp = *x2;
		*x2 = *y2;
		*y2 = temp;
	}
	else if (m >= -1 && m < 0)
	{
		*y1 *= -1;
		*y2 *= -1;
	}
	else if (m < -1)
	{
		*y1 *= -1;
		*y2 *= -1;
		temp = *x1;
		*x1 = *y1;
		*y1 = temp;
		temp = *x2;
		*x2 = *y2;
		*y2 = temp;
	}
	return (m);
}
