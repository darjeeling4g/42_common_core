/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:57:15 by siyang            #+#    #+#             */
/*   Updated: 2023/01/11 20:57:50 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_hook(int keycode, t_vars *vars)
{
	t_list	*model;
	t_pixel	*pixel;
	t_image	img;

	model = vars->model;
	while (model)
	{
		pixel = model->content;
		if (keycode == UP)
			pixel->y += 10;
		else if (keycode == DOWN)
			pixel->y -= 10;
		else if (keycode == RIGHT)
			pixel->x += 10;
		else if (keycode == LEFT)
			pixel->x -= 10;
		model = model->next;
	}
	img = vars->img;
	mlx_destroy_image(vars->mlx_ptr, img.ptr);
	image_generator(vars->mlx_ptr, model, &img);
	mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, img.ptr, 0, 0);
	return (1);
}
