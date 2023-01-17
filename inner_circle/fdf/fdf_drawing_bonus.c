/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_drawing_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:54:36 by siyang            #+#    #+#             */
/*   Updated: 2023/01/17 09:49:49 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	draw_line(t_list *model, t_image *img)
{
	t_pixel	*pixel;

	while (model)
	{
		pixel = model->content;
		if (pixel->next_x != NULL)
			bresenham(img, pixel, (t_pixel *)pixel->next_x);
		if (pixel->next_y != NULL)
			bresenham(img, pixel, (t_pixel *)pixel->next_y);
		model = model->next;
	}
}

void	draw_pixel(t_image *img, t_palette *p, int x, int y)
{
	if (x < 0 || x >= 1920 || y < 0 || y >= 1080)
		return ;
	*(img->addr + (img->bpp * x / 8) + (img->size_line * y)) = p->b;
	*(img->addr + 1 + (img->bpp * x / 8) + (img->size_line * y)) = p->g;
	*(img->addr + 2 + (img->bpp * x / 8) + (img->size_line * y)) = p->r;
	*(img->addr + 3 + (img->bpp * x / 8) + (img->size_line * y)) = 0;
}

void	bresenham(t_image *img, t_pixel *pixel, t_pixel *next)
{
	t_palette	p;

	make_palette(&p, pixel, next);
	while (p.x1 <= p.x2)
	{
		if (p.f < 0)
			p.f += 2 * p.h;
		else if (p.f > 0)
		{
			p.y1++;
			p.f += 2 * (p.h - p.w);
		}
		if (p.m >= 0 && p.m <= 1)
			draw_pixel(img, &p, p.x1, p.y1);
		else if (p.m > 1)
			draw_pixel(img, &p, p.y1, p.x1);
		else if (p.m >= -1 && p.m < 0)
			draw_pixel(img, &p, p.x1, -1 * p.y1);
		else if (p.m < -1)
			draw_pixel(img, &p, p.y1, -1 * p.x1);
		color_gradation(&p);
		p.x1++;
	}
}

void	color_gradation(t_palette *p)
{
	if (p->r > p->n_r)
		p->r--;
	else if (p->r < p->n_r)
		p->r++;
	if (p->g > p->n_g)
		p->g--;
	else if (p->g < p->n_g)
		p->g++;
	if (p->b > p->n_b)
		p->b--;
	else if (p->b < p->n_b)
		p->b++;
}
