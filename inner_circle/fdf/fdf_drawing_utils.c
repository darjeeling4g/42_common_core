/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_drawing_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:02:47 by siyang            #+#    #+#             */
/*   Updated: 2023/01/11 21:28:11 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	bresenham(t_image *img, int x1, int y1, int x2, int y2)
{
	int	m;
	int	W;
	int	H;
	int	F;

	m = bresenham_init(&x1, &y1, &x2, &y2);
	W = x2 - x1;
	H = y2 - y1;
	F = 2 * H - W;
	while (x1 != x2)
	{
		x1++;
		if (F < 0)
			F += 2 * H;
		else if (F > 0)
		{
			y1++;
			F += 2 * (H - W);
		}
		if (m >= 0 && m <= 1)
			draw_pixel(img, x1, y1);
		else if (m > 1)
			draw_pixel(img, y1, x1);
		else if (m >= -1 && m < 0)
			draw_pixel(img, x1, -1 * y1);
		else if (m < -1)
			draw_pixel(img, y1, -1 * x1);
	}
}

int	bresenham_init(int *x1, int *y1, int *x2, int *y2)
{
	int	temp;
	int	m;

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
