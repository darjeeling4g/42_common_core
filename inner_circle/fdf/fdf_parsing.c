/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:54:41 by siyang            #+#    #+#             */
/*   Updated: 2023/01/13 20:04:39 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
		free(new_line);
		x = 0;
		while (pixel_group[x] && pixel_group[x][0] != '\n')
		{
			pixel = malloc(sizeof(t_pixel));
			pixel->init_x = x;
			pixel->init_y = y;
			pixel->init_z = ft_atoi(pixel_group[x]);
			i = 0;
			while (pixel_group[x][i] && pixel_group[x][i] != '\n')
				i++;
			pixel->a = 0x00;
			pixel->r = 0xFF;
			pixel->g = 0xFF;
			pixel->b = 0xFF;
			ft_lstadd_back(model, ft_lstnew(pixel));
			if (pixel_group[x][i] == '\n')
			{
				free(pixel_group[x]);
				break ;
			}
			free(pixel_group[x]);
			x++;
		}
		free(pixel_group);
		y++;
	}
}

void	decide_img_size(t_list *model, t_image *img)
{
	t_pixel *pixel;

	img->width = 0;
	img->height = 0;
	while (model)
	{
		pixel = model->content;
		if (img->width < pixel->init_x)
			img->width = pixel->init_x;
		if (img->height < pixel->init_y)
			img->height = pixel->init_y;
		model = model->next;
	}
	img->scale = 0;
	while (1)
	{
		img->scale++;
		if (pixel->init_x * img->scale > 1280 || pixel->init_y * img->scale > 720)
			break ;
	}
	img->width *= img->scale;
	img->height *= img->scale;
}
