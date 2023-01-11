/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_drawing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:54:36 by siyang            #+#    #+#             */
/*   Updated: 2023/01/11 20:55:18 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	image_generator(void *mlx_ptr, t_list *model, t_image *img)
{
	t_pixel *pixel;
	int	x;
	int	y;

	img->ptr = mlx_new_image(mlx_ptr, 1920, 1080);
	img->addr = mlx_get_data_addr(img->ptr, &img->bpp, &img->size_line, &img->endian);
	while (model)
	{
		pixel = model->content;
		x = pixel->x;
		y = pixel->y;
//		draw_pixel(img, x, y);
		draw_line(model, img, pixel);
		model = model->next;
	}
}

void	draw_pixel(t_image *img, int x, int y)
{
	if (x < 0 || x >= 1920 || y < 0 || y >= 1080)
		return ;
	*(img->addr + (img->bpp * x / 8) + (img->size_line * y)) = 0xFF;
	*(img->addr + 1 + (img->bpp * x / 8) + (img->size_line * y)) = 0xFF;
	*(img->addr + 2 + (img->bpp * x / 8) + (img->size_line * y)) = 0xFF;
	*(img->addr + 3 + (img->bpp * x / 8) + (img->size_line * y)) = 0x00;
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
		bresenham(img, (int)pixel->x, (int)pixel->y, (int)next_x->x, (int)next_x->y);
	if (next_y != NULL)
		bresenham(img, (int)pixel->x, (int)pixel->y, (int)next_y->x, (int)next_y->y);
}
