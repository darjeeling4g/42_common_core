/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:57:15 by siyang            #+#    #+#             */
/*   Updated: 2023/01/13 20:21:09 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_hook(int keycode, t_vars *vars)
{
	t_list	*model;
	t_pixel	*pixel;

	clear_image(vars);
	model = vars->model;
	while (model)
	{
		pixel = model->content;
		if (keycode == UP)
			pixel->y -= MOVE_VALUE;
		else if (keycode == DOWN)
			pixel->y += MOVE_VALUE;
		else if (keycode == RIGHT)
			pixel->x += MOVE_VALUE;
		else if (keycode == LEFT)
			pixel->x -= MOVE_VALUE;
		else if (keycode == ZOOM_IN)
		{
			pixel->x *= 1.1;
			pixel->y *= 1.1;
		}
		else if (keycode == ZOOM_OUT)
		{
			pixel->x *= 0.9;
			pixel->y *= 0.9;
		}
		else if(keycode == KEY_W)
		{
			pixel->x -= 960;
			pixel->y -= 540;
			rotate_x(pixel, 5);
			pixel->x += 960;
			pixel->y += 540;
		}
		else if(keycode == KEY_S)
		{
			pixel->x -= 960;
			pixel->y -= 540;
			rotate_x(pixel, -5);
			pixel->x += 960;
			pixel->y += 540;
		}
		else if(keycode == KEY_A)
		{
			pixel->x -= 960;
			pixel->y -= 540;
			rotate_y(pixel, 5);
			pixel->x += 960;
			pixel->y += 540;
		}
		else if(keycode == KEY_D)
		{
			pixel->x -= 960;
			pixel->y -= 540;
			rotate_y(pixel, -5);
			pixel->x += 960;
			pixel->y += 540;
		}
		else if(keycode == KEY_Q)
		{
			pixel->x -= 960;
			pixel->y -= 540;
			rotate_z(pixel, 5);
			pixel->x += 960;
			pixel->y += 540;
		}
		else if(keycode == KEY_E)
		{
			pixel->x -= 960;
			pixel->y -= 540;
			rotate_z(pixel, -5);
			pixel->x += 960;
			pixel->y += 540;
		}
		model = model->next;
	}
	image_generator(vars->model, &vars->img);
	mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, vars->img.ptr, 0, 0);
	return (1);
}
