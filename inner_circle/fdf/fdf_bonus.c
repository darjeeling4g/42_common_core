/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 20:30:00 by siyang            #+#    #+#             */
/*   Updated: 2023/01/17 09:49:39 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	main(int argc, char *argv[])
{
	int		fd;
	t_vars	vars;

	if (argc != 2)
		kill_process("Error : Wrong arguments");
	if (valid_file_name(argv[1]))
		kill_process("Error : Invalied file");
	vars.model = NULL;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		kill_process("Error : File open failed");
	model_parser(fd, &vars.model);
	close(fd);
	image_setup(vars.model, &vars.img);
	isometric_projection(vars.model, &vars.img);
	vars.mlx_ptr = mlx_init();
	vars.win_ptr = mlx_new_window(vars.mlx_ptr, WIDTH, HEIGHT, "fdf");
	vars.img.ptr = mlx_new_image(vars.mlx_ptr, WIDTH, HEIGHT);
	vars.img.addr = mlx_get_data_addr(vars.img.ptr, &vars.img.bpp,
			&vars.img.size_line, &vars.img.endian);
	draw_line(vars.model, &vars.img);
	mlx_put_image_to_window(vars.mlx_ptr, vars.win_ptr, vars.img.ptr, 0, 0);
	mlx_hook(vars.win_ptr, 2, 0, key_hook, &vars);
	mlx_hook(vars.win_ptr, 17, 0, kill_process, NULL);
	mlx_loop(vars.mlx_ptr);
}

int	valid_file_name(char *str)
{
	int	len;

	while (*str)
	{
		if (*str == '.')
			break ;
		str++;
	}
	if (*str == '.')
	{
		str++;
		len = ft_strlen(str);
		if (len != 3)
			return (1);
		return (ft_memcmp(str, "fdf", 3));
	}
	return (1);
}

int	kill_process(char *str)
{
	if (str == NULL)
		exit(EXIT_SUCCESS);
	else if (str)
	{
		perror(str);
		exit(EXIT_FAILURE);
	}
	return (0);
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
		img.addr[i] = 0;
		i++;
	}
}
