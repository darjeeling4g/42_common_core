/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_drawing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:54:36 by siyang            #+#    #+#             */
/*   Updated: 2023/01/12 16:40:54 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	image_generator(t_list *model, t_image *img)
{
	t_pixel *pixel;

	while (model)
	{
		pixel = model->content;
		draw_line(model, img, pixel);
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
	*(img->addr + 3 + (img->bpp * x / 8) + (img->size_line * y)) = p->a;
}

void	draw_line(t_list *model, t_image *img, t_pixel *pixel)
{
	t_pixel	*next_x;
	t_pixel	*next_y;

	if (model->next == NULL)
		return ;
	model = model->next;
	next_x = model->content;
	if (pixel->init_y != next_x->init_y)
		next_x = NULL;
	while (model)
	{
		next_y = model->content;
		if (pixel->init_x == next_y->init_x)
			break ;
		model = model->next;
	}
	if (model == NULL)
		next_y = NULL;
	if (next_x != NULL)
		bresenham(img, pixel, next_x);
	if (next_y != NULL)
		bresenham(img, pixel, next_y);
}
