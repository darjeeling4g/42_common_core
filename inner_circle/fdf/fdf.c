/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 20:30:00 by siyang            #+#    #+#             */
/*   Updated: 2023/01/10 18:05:23 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char *argv[])
{
	int		fd;
	void	*mlx_ptr;
	void	*win_ptr;
	t_list	*model;
	t_image	img;

	//exception
	if (argc != 2)
		return (0);

	//parse model
	fd = open(argv[1], O_RDONLY);
	model_parser(fd, &model);

	//isomatric projection
//	isomatric_projection(model);

	//dicide scale
	decide_img_size(model, &img);

	//mlx setup
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1920, 1080, "fdf");

	//create image
	image_generator(mlx_ptr, model, &img);

	//show image
	mlx_put_image_to_window(mlx_ptr, win_ptr, img.ptr, 0, 0);

	//handle image
	mlx_loop(mlx_ptr);
}

void	model_parser(int fd, t_list **model)
{
	int		x;
	int		y;
	int		i;
	char	*new_line;
	char	**pixel_group;
	t_pixel	*pixel;

	y = 0;
	while (1)
	{
		new_line = get_next_line(fd);
		if (new_line == NULL)
			break ;
		pixel_group = ft_split(new_line, ' ');
		x = 0;
		while (pixel_group[x][0] != '\n')
		{
			pixel = malloc(sizeof(t_pixel));
			pixel->initial_x = x;
			pixel->initial_y = y;
			pixel->x = x;
			pixel->y = y;
			pixel->z = ft_atoi(pixel_group[x]);
			i = 0;
			while (pixel_group[x][i] >= '0' &&  pixel_group[x][i] <= '9')
				i++;
			ft_lstadd_back(model, ft_lstnew(pixel));
			if (pixel_group[x][i] == '\n')
				break ;
			free(pixel_group[x]);
			x++;
		}
		free(pixel_group);
		y++;
	}
}

//void	isometric_projection(t_list *model)
//{
//	t_pixel *pixel;
//
//	while (model)
//	{
//		pixel = model->content;
//		rotate_x(pixel, theta);
//		rotate_y(pixel, theta);
//		rotate_z(pixel, theta);
//		model = model->next;
//	}
//}
//
//void	rotate_x(t_pixel *pixel, double theta)
//{
//	double pre_x;
//	double pre_y;
//	double pre_z;
//
//	pre_x = pixel->x;
//	pre_y = pixel->y;
//	pre_z = pixel->z;
//	pixel->x = pre_x;
//	pixel->y = pre_y * cos(theta) - pre_z * sin(theta);
//	pixel->z = pre_y * sin(theta) + pre_z * cos(theta);
//}
//
//void	rotate_y(t_pixel *pixel, double theta)
//{
//	double pre_x;
//	double pre_y;
//	double pre_z;
//
//	pre_x = pixel->x;
//	pre_y = pixel->y;
//	pre_z = pixel->z;
//	pixel->x = pre_x * cos(theta) + pre_z * sin(theta);
//	pixel->y = pre_y;
//	pixel->z = pre_z * cos(theta) - pre_x * sin(theta);
//}
//
//void	rotate_z(t_pixel *pixel, double theta)
//{
//	double pre_x;
//	double pre_y;
//	double pre_z;
//
//	pre_x = pixel->x;
//	pre_y = pixel->y;
//	pre_z = pixel->z;
//	pixel->x = pre_x * cos(theta) - pre_y * sin(theta);
//	pixel->y = pre_x * sin(theta) + pre_y * cos(theta);
//	pixel->z = pre_z;
//}

void	decide_img_size(t_list *model, t_image *img)
{
	t_pixel *pixel;

	img->width = 0;
	img->height = 0;
	while (model)
	{
		pixel = model->content;
		if (img->width < pixel->x)
			img->width = pixel->x;
		if (img->height < pixel->y)
			img->height = pixel->y;
		model = model->next;
	}
	if (1920 / img->width < 1080 / img->height)
		img->scale = 1920 / img->width;
	else
		img->scale = 1080 / img->height;
}

//void	bresenham(int x1, int y1, int x2, int y2)
//{
//	int	m;
//	int	W;
//	int	H;
//	int	F;
//
//	m = bresenham_init(&x1, &y1, &x2, &y2);
//	W = x2 - x1;
//	H = y2 - y1;
//	if (m >= 0 && m <= 1)
//	{
//		F = 2 * H - W;
//		while ()
//		{
//
//		}
//	}
//	else if (m > 1)
//	{
//		F = 2 * W - H;
//		while ()
//		{
//
//		}
//	}
//}
//
//int	bresenham_init(int *x1, int *y1, int *x2, int *y2)
//{
//	int	temp;
//	int	m;
//
//	if (*x2 < *x1)
//	{
//		temp = *x1;
//		*x1 = *x2;
//		*x2 = temp;
//		temp = *y1;
//		*y1 = *y2;
//		*y2 = temp;
//	}
//	if (*x2 - *x1 == 0)
//		m = 1;
//	else if (*y2 - *y1 == 0)
//		m = 0;
//	else
//		m = (*y2 - *y1) / (*x2 - *x1);
//	return (m);
//}

void	image_generator(void *mlx_ptr, t_list *model, t_image *img)
{
	t_pixel *pixel;
	int	x;
	int	y;
	int	scale;

	scale = img->scale;
	img->ptr = mlx_new_image(mlx_ptr, img->width * scale + 1, img->height * scale + 1);
	img->addr = mlx_get_data_addr(img->ptr, &img->bpp, &img->size_line, &img->endian);
	while (model)
	{
		pixel = model->content;
		x = pixel->x;
		y = pixel->y;
		draw_pixel(img, x * scale, y * scale);
		draw_line(model, pixel);
		model = model->next;
	}
}

void	draw_pixel(t_image *img, int x, int y)
{
	*(img->addr + (img->bpp * x / 8) + (img->size_line * y)) = 0xFF;
	*(img->addr + 1 + (img->bpp * x / 8) + (img->size_line * y)) = 0xFF;
	*(img->addr + 2 + (img->bpp * x / 8) + (img->size_line * y)) = 0xFF;
	*(img->addr + 3 + (img->bpp * x / 8) + (img->size_line * y)) = 0x00;
}

//void	draw_line(t_list *model, t_image *img, t_pixel *pixel)
void	draw_line(t_list *model, t_pixel *pixel)
{
	t_pixel	*next_x;
	t_pixel	*next_y;

	if (model->next == NULL)
		return ;
	model = model->next;
	next_x = model->content;
	if (pixel->initial_y != next_x->initial_y)
		next_x = NULL;
	while (model)
	{
		next_y = model->content;
		if (pixel->initial_x == next_y->initial_x)
			break ;
		model = model->next;
	}
	if (model == NULL)
		next_y = NULL;
	ft_printf("pixel : %d, %d ", (int)pixel->x, (int)pixel->y);
	if (next_x != NULL)
		ft_printf("next_x : %d, %d ", (int)next_x->x, (int)next_x->y);
//		bresenham(next_x);
	if (next_y != NULL)
		ft_printf("next_y : %d, %d\n", (int)next_y->x, (int)next_y->y);
//		bresenham(next_y);
}
