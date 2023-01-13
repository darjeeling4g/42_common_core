/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 20:31:33 by siyang            #+#    #+#             */
/*   Updated: 2023/01/13 21:04:17 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H

#define MOVE_VALUE 3
#define RADIAN 0.017

#define UP 126
#define DOWN 125
#define RIGHT 124
#define LEFT 123
#define ZOOM_IN 24
#define ZOOM_OUT 27
#define EXIT 53
#define KEY_W 13
#define KEY_S 1
#define KEY_A 0
#define KEY_D 2
#define KEY_Q 12
#define KEY_E 14

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
	double	x;
	double	y;
	double	z;
	char	a;
	char	r;
	char	g;
	char	b;
	int		init_x;
	int		init_y;
	int		init_z;
}	t_pixel;

typedef struct s_palette
{
	double	m;
	double	W;
	double	H;
	double	F;
	double	x1;
	double	y1;
	double	x2;
	double	y2;
	char	a;
	char	r;
	char	g;
	char	b;

}	t_palette;

typedef struct s_vars
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_list	*model;
	t_image	img;
}	t_vars;

// fdf_parsing.c
void	model_parser(int fd, t_list **model);
void	decide_img_size(t_list *model, t_image *img);

// fdf_rotation.c
void	isometric_projection(t_list *model, t_image *img);
void	rotate_x(t_pixel *pixel, double theta);
void	rotate_y(t_pixel *pixel, double theta);
void	rotate_z(t_pixel *pixel, double theta);

// fdf_drawing.c
void	image_generator(t_list *model, t_image *img);
void	draw_pixel(t_image *img, t_palette *p, int x, int y);
void	draw_line(t_list *model, t_image *img, t_pixel *pixel);
void	bresenham(t_image *img, t_pixel *pixel, t_pixel *next);
double	bresenham_init(double *x1, double *y1, double *x2, double *y2);
void	make_palette(t_palette *p, t_pixel *pixel, t_pixel *next);

// fdf_handling.c
int		key_hook(int keycode, t_vars *vars);
void	clear_image(t_vars *vars);
int	render(t_vars *vars);

#endif
