/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:54:41 by siyang            #+#    #+#             */
/*   Updated: 2023/01/17 09:04:58 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	model_parser(int fd, t_list **model)
{
	int		x;
	int		y;
	int		res;
	char	*new_line;
	char	**pixel_group;

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
			res = generate_new_pixel(model, pixel_group[x], x, y);
			if (res == 1)
				break ;
			x++;
		}
		free(pixel_group);
		y++;
	}
}

int	generate_new_pixel(t_list **model, char *pixel_group, int x, int y)
{
	t_pixel	*pixel;
	t_list	*new;
	int		res;
	int		i;

	res = 0;
	pixel = malloc(sizeof(t_pixel));
	if (pixel == NULL)
		kill_process("Error : Memory allocation failed");
	pixel->init_x = x;
	pixel->init_y = y;
	pixel->init_z = ft_atoi(pixel_group);
	parse_color(pixel_group, pixel);
	new = ft_lstnew(pixel);
	if (new == NULL)
		kill_process("Error : Memory allocation failed");
	ft_lstadd_back(model, new);
	i = 0;
	while (pixel_group[i] && pixel_group[i] != '\n')
		i++;
	if (pixel_group[i] == '\n')
		res = 1;
	free(pixel_group);
	return (res);
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
	int	num;
	int	i;

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
