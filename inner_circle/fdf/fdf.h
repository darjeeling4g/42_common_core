/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 20:31:33 by siyang            #+#    #+#             */
/*   Updated: 2023/01/10 17:21:20 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <math.h>
#include "mlx/mlx.h"
#include "libft/libft.h"
#include "libft/get_next_line.h"
#include "libft/ft_printf.h"

typedef struct s_image
{
	void	*ptr;
	int		bpp;
	int		size_line;
	int		endian;
	char	*addr;
	int		width;
	int		height;
	int		scale;
}	t_image;

typedef struct s_pixel
{
	double		x;
	double		y;
	double		z;
	char		a;
	char		r;
	char		g;
	char		b;
	int	initial_x;
	int	initial_y;
}	t_pixel;

void	model_parser(int fd, t_list **model);
void	image_generator(void *mlx_ptr, t_list *model, t_image *img);
void	decide_img_size(t_list *model, t_image *img);
void	draw_pixel(t_image *img, int x, int y);
void	draw_line(t_list *model, t_pixel *pixel);

#endif
