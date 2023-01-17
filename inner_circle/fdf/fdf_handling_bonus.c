/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_handling_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:57:15 by siyang            #+#    #+#             */
/*   Updated: 2023/01/17 09:50:05 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == EXIT)
		kill_process(NULL);
	event_resize(keycode, &vars->img);
	event_move(keycode, &vars->img);
	event_rotate(keycode, &vars->img);
	event_projection(keycode, &vars->img);
	clear_image(vars);
	isometric_projection(vars->model, &vars->img);
	draw_line(vars->model, &vars->img);
	mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, vars->img.ptr, 0, 0);
	return (0);
}

void	event_resize(int keycode, t_image *img)
{
	if (keycode == ZOOM_IN)
	{
		img->scale *= 1.2;
		img->depth *= 1.2;
	}
	else if (keycode == ZOOM_OUT)
	{
		img->scale *= 0.8;
		img->depth *= 0.8;
	}
	else if (keycode == DEPTH_PLUS)
		img->depth *= 1.2;
	else if (keycode == DEPTH_MINUS)
		img->depth *= 0.8;
	else if (keycode == BENDING_PLUS)
		img->bending++;
	else if (keycode == BENDING_MINUS)
		img->bending--;
}

void	event_move(int keycode, t_image *img)
{
	if (keycode == UP)
		img->center_y -= MOVE_VALUE;
	else if (keycode == DOWN)
		img->center_y += MOVE_VALUE;
	else if (keycode == RIGHT)
		img->center_x += MOVE_VALUE;
	else if (keycode == LEFT)
		img->center_x -= MOVE_VALUE;
}

void	event_rotate(int keycode, t_image *img)
{
	if (keycode == KEY_W)
		img->angle_x += 5;
	else if (keycode == KEY_S)
		img->angle_x -= 5;
	else if (keycode == KEY_D)
		img->angle_y += 5;
	else if (keycode == KEY_A)
		img->angle_y -= 5;
	else if (keycode == KEY_E)
		img->angle_z += 5;
	else if (keycode == KEY_Q)
		img->angle_z -= 5;
}

void	event_projection(int keycode, t_image *img)
{
	if (keycode == KEY_X || keycode == KEY_Y || keycode == KEY_Z)
	{
		if (keycode == KEY_Y)
			img->angle_x = 90;
		else
			img->angle_x = 0;
		if (keycode == KEY_X)
			img->angle_y = 90;
		else
			img->angle_y = 0;
		img->center_x = WIDTH / 2;
		img->center_y = HEIGHT / 2;
		img->angle_z = 0;
		img->bending = 0;
	}
}
