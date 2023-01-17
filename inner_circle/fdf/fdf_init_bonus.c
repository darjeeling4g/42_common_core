/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 21:29:10 by siyang            #+#    #+#             */
/*   Updated: 2023/01/17 09:50:13 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	image_setup(t_list *model, t_image *img)
{
	t_pixel	*pixel;

	img->center_x = WIDTH / 2;
	img->center_y = HEIGHT / 2;
	img->angle_x = 55;
	img->angle_y = 0;
	img->angle_z = -45;
	img->bending = 0;
	replace_origin(model);
	while (model)
	{
		pixel = model->content;
		find_next(model, pixel);
		model = model->next;
	}
	decide_scale_depth(pixel, img);
}

void	isometric_projection(t_list *model, t_image *img)
{
	t_pixel	*pixel;

	while (model)
	{
		pixel = model->content;
		pixel->x = pixel->init_x * img->scale;
		pixel->y = pixel->init_y * img->scale;
		pixel->z = pixel->init_z * img->depth;
		if (img->bending)
		{
			pixel->z += pixel->init_x * pixel->init_x * img->bending / 100;
			pixel->z += pixel->init_y * pixel->init_y * img->bending / 100;
		}
		rotate_z(pixel, img->angle_z);
		rotate_x(pixel, img->angle_x);
		rotate_y(pixel, img->angle_y);
		pixel->x += img->center_x;
		pixel->y += img->center_y;
		model = model->next;
	}
}

void	decide_scale_depth(t_pixel *pixel, t_image *img)
{
	int	x;
	int	y;

	x = pixel->init_x;
	y = pixel->init_y;
	img->scale = 0;
	while (1)
	{
		img->scale++;
		if (x * img->scale + img->center_x > 1280
			|| y * img->scale + img->center_y > 720)
			break ;
	}
	img->depth = img->scale;
}

void	replace_origin(t_list *model)
{
	t_list	*temp;
	t_pixel	*pixel;
	int		x_max;
	int		y_max;

	x_max = 0;
	y_max = 0;
	temp = model;
	while (temp)
	{
		pixel = temp->content;
		if (x_max < pixel->init_x)
			x_max = pixel->init_x;
		if (y_max < pixel->init_y)
			y_max = pixel->init_y;
		temp = temp->next;
	}
	while (model)
	{
		pixel = model->content;
		pixel->init_x -= x_max / 2;
		pixel->init_y -= y_max / 2;
		model = model->next;
	}
}

void	find_next(t_list *model, t_pixel *pixel)
{
	t_pixel	*next_x;
	t_pixel	*next_y;

	if (model->next == NULL)
	{
		pixel->next_x = NULL;
		pixel->next_y = NULL;
		return ;
	}
	model = model->next;
	pixel->next_x = model->content;
	next_x = pixel->next_x;
	if (pixel->init_y != next_x->init_y)
		pixel->next_x = NULL;
	while (model)
	{
		pixel->next_y = model->content;
		next_y = pixel->next_y;
		if (pixel->init_x == next_y->init_x)
			break ;
		model = model->next;
	}
	if (model == NULL)
		pixel->next_y = NULL;
}
