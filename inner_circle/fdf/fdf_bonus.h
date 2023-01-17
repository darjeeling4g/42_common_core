/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 20:31:33 by siyang            #+#    #+#             */
/*   Updated: 2023/01/17 09:51:25 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H

# define WIDTH 1920
# define HEIGHT 1080
# define MOVE_VALUE 3
# define RADIAN 0.017

# define EXIT 53

# define ZOOM_IN 24
# define ZOOM_OUT 27
# define DEPTH_PLUS 30
# define DEPTH_MINUS 33
# define BENDING_PLUS 39
# define BENDING_MINUS 41

# define UP 126
# define DOWN 125
# define RIGHT 124
# define LEFT 123

# define KEY_W 13
# define KEY_S 1
# define KEY_A 0
# define KEY_D 2
# define KEY_Q 12
# define KEY_E 14

# define KEY_X 7
# define KEY_Y 16
# define KEY_Z 6

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include "mlx/mlx.h"
# include "libft/libft.h"
# include "libft/get_next_line.h"
# include "libft/ft_printf.h"

typedef struct s_image
{
	void	*ptr;
	char	*addr;
	int		bpp;
	int		size_line;
	int		endian;
	int		center_x;
	int		center_y;
	int		bending;
	int		angle_x;
	int		angle_y;
	int		angle_z;
	double	scale;
	double	depth;
}	t_image;

typedef struct s_pixel
{
	double	x;
	double	y;
	double	z;
	char	r;
	char	g;
	char	b;
	int		init_x;
	int		init_y;
	int		init_z;
	void	*next_x;
	void	*next_y;
}	t_pixel;

typedef struct s_palette
{
	double			m;
	double			w;
	double			h;
	double			f;
	double			x1;
	double			y1;
	double			x2;
	double			y2;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned char	n_r;
	unsigned char	n_g;
	unsigned char	n_b;

}	t_palette;

typedef struct s_vars
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_list	*model;
	t_image	img;
}	t_vars;

// fdf_bonus.c
int		valid_file_name(char *str);
int		kill_process(char *str);
void	clear_image(t_vars *vars);

// fdf_init_bonus.c
void	image_setup(t_list *model, t_image *img);
void	isometric_projection(t_list *model, t_image *img);
void	decide_scale_depth(t_pixel *pixel, t_image *img);
void	replace_origin(t_list *model);
void	find_next(t_list *model, t_pixel *pixel);

// fdf_parsing_bonus.c
void	model_parser(int fd, t_list **model);
int		generate_new_pixel(t_list **model, char *pixel_group, int x, int y);
void	parse_color(char *pixel_group, t_pixel *pixel);
int		hex_to_int(char *str);

// fdf_rotation_bonus.c
void	rotate_x(t_pixel *pixel, double theta);
void	rotate_y(t_pixel *pixel, double theta);
void	rotate_z(t_pixel *pixel, double theta);

// fdf_drawing_bonus.c
void	draw_line(t_list *model, t_image *img);
void	draw_pixel(t_image *img, t_palette *p, int x, int y);
void	bresenham(t_image *img, t_pixel *pixel, t_pixel *next);
void	color_gradation(t_palette *p);

// fdf_drawing_utils_bonus.c
void	make_palette(t_palette *p, t_pixel *pixel, t_pixel *next);
double	coordinate_init(double *x1, double *y1, double *x2, double *y2);
void	swap_coordinate(double *x1, double *x2, double *y1, double *y2);
void	x_axis_symmetry(double *y1, double *y2);
void	y_equal_x_symmetry(double *x1, double *x2, double *y1, double *y2);

// fdf_handling_bonus.c
int		key_hook(int keycode, t_vars *vars);
void	event_resize(int keycode, t_image *img);
void	event_move(int keycode, t_image *img);
void	event_rotate(int keycode, t_image *img);
void	event_projection(int keycode, t_image *img);
#endif
