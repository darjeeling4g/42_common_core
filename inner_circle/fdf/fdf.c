/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 20:30:00 by siyang            #+#    #+#             */
/*   Updated: 2023/01/13 15:59:29 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char *argv[])
{
	int		fd;
	t_vars	vars;

	// exception
	if (argc != 2)
		return (0);

	// parse model
	vars.model = NULL;
	fd = open(argv[1], O_RDONLY);
	model_parser(fd, &vars.model);
	close(fd);

	// dicide scale
	decide_img_size(vars.model, &vars.img);

	// isomatric projection
	isometric_projection(vars.model, &vars.img);

	// mlx setup
	vars.mlx_ptr = mlx_init();
	vars.win_ptr = mlx_new_window(vars.mlx_ptr, 1920, 1080, "fdf");
	vars.img.ptr = mlx_new_image(vars.mlx_ptr, 1920, 1080);
	vars.img.addr = mlx_get_data_addr(vars.img.ptr, &vars.img.bpp, &vars.img.size_line, &vars.img.endian);

	// create image
	image_generator(vars.model, &vars.img);

	// show image
	mlx_put_image_to_window(vars.mlx_ptr, vars.win_ptr, vars.img.ptr, 0, 0);

	// handle image
	mlx_hook(vars.win_ptr, 2, 0, &key_hook, &vars);
	mlx_loop(vars.mlx_ptr);
}

void	clear_image(t_vars *vars)
{
	t_image	img;
	int		i;
	int		end;

	img = vars->img;
	i = 0;
	end = 1920 * 1080 * 4;
	while (i < end)
	{
		img.addr[i] = 0x00;
		i++;
	}
}
