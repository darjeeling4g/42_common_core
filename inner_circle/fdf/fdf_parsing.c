/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:54:41 by siyang            #+#    #+#             */
/*   Updated: 2023/01/17 06:47:42 by siyang           ###   ########.fr       */
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
			parse_color(pixel_group[x], pixel);
			i = 0;
			while (pixel_group[x][i] && pixel_group[x][i] != '\n')
				i++;
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

void	parse_color(char *pixel_group, t_pixel *pixel)
{
	int	len;

	while (*pixel_group && *pixel_group != ',')
		pixel_group++;
	if (*pixel_group == ',')
	{
		pixel_group += 3;
		len = ft_strlen(pixel_group);
		if (len % 2 == 1)
			len--;
		if (len == 6)
			pixel->r = hex_to_int(pixel_group + len - 6);
		else if (len == 4 || len == 2)
			pixel->r = 0;
		if (len == 6 || len == 4)
			pixel->g = hex_to_int(pixel_group + len - 4);
		else if (len == 2)
			pixel->g = 0;
		pixel->b = hex_to_int(pixel_group + len - 2);
		return ;
	}
	pixel->r = 0xFF;
	pixel->g = 0xFF;
	pixel->b = 0xFF;
}

int	hex_to_int(char *str)
{
	int num;
	int i;

	i = 0;
	while (i < 2)
	{
		if (str[i] >= '0' && str[i] <= '9')
			num = num * 16 + (str[i] - 48);
		else if (str[i] >= 'A' && str[i] <= 'F')
			num = num * 16 + (str[i] - 55);
		else if (str[i] >= 'a' && str[i] <= 'f')
			num = num * 16 + (str[i] - 87);
		i++;
	}
	return (num);
}
