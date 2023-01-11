/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rotation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:54:46 by siyang            #+#    #+#             */
/*   Updated: 2023/01/11 17:13:03 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric_projection(t_list *model, t_image *img)
{
	t_pixel *pixel;

	while (model)
	{
		pixel = model->content;
		pixel->x = pixel->init_x * img->scale;
		pixel->y = pixel->init_y * img->scale;
		pixel->z = pixel->init_z;
		pixel->x -= img->width / 2;
		pixel->y -= img->height / 2;
		rotate_x(pixel, 0);
		rotate_y(pixel, 0);
		rotate_z(pixel, 0);
		pixel->x += 960;
		pixel->y += 540;
		model = model->next;
	}
}

void	rotate_x(t_pixel *pixel, double theta)
{
	double pre_x;
	double pre_y;
	double pre_z;

	pre_x = pixel->x;
	pre_y = pixel->y;
	pre_z = pixel->z;
	pixel->x = pre_x;
	pixel->y = pre_y * cos(theta) - pre_z * sin(theta);
	pixel->z = pre_y * sin(theta) + pre_z * cos(theta);
}

void	rotate_y(t_pixel *pixel, double theta)
{
	double pre_x;
	double pre_y;
	double pre_z;

	pre_x = pixel->x;
	pre_y = pixel->y;
	pre_z = pixel->z;
	pixel->x = pre_x * cos(theta) + pre_z * sin(theta);
	pixel->y = pre_y;
	pixel->z = pre_z * cos(theta) - pre_x * sin(theta);
}

void	rotate_z(t_pixel *pixel, double theta)
{
	double pre_x;
	double pre_y;
	double pre_z;

	pre_x = pixel->x;
	pre_y = pixel->y;
	pre_z = pixel->z;
	pixel->x = pre_x * cos(theta) - pre_y * sin(theta);
	pixel->y = pre_x * sin(theta) + pre_y * cos(theta);
	pixel->z = pre_z;
}
