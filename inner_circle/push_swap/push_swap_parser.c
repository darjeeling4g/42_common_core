/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 19:20:18 by siyang            #+#    #+#             */
/*   Updated: 2023/02/21 15:39:59 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_parser(int argc, char **argv, int **arr)
{
	char	**value_group;
	char	*args;
	int		*res;
	int		i;

	args = combine_args(argc, argv);
	value_group = ft_split(args, ' ');
	free(args);
	is_integer(value_group);
	is_duplicated(value_group);
	*arr = atoi_only_int_range(value_group);
	i = 0;
	while (value_group[i])
	{
		free(value_group[i]);
		i++;
	}
	free(value_group);
	return (i);
}

char	*combine_args(int argc, char **argv)
{
	char	*res;
	char	*temp;
	int		i;

	res = ft_strdup("");
	if (!(res))
		exit_process(1);
	i = 1;
	while (i < argc)
	{
		temp = res;
		res = ft_strjoin(res, " ");
		if (!(res))
			exit_process(1);
		free(temp);
		temp = res;
		res = ft_strjoin(res, argv[i]);
		if (!(res))
			exit_process(1);
		free(temp);
		i++;
	}
	return (res);
}

void	is_integer(char **value_group)
{
	int	i;
	int	j;

	i = 0;
	while (value_group[i])
	{
		j = 0;
		if (value_group[i][j] == '-')
			j++;
		while (value_group[i][j])
		{
			if (j > 10)
				exit_process(1);
			if (value_group[i][j] < '0' || value_group[i][j] > '9')
				exit_process(1);
			j++;
		}
		i++;
	}
}

void	is_duplicated(char **value_group)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	while (value_group[i])
	{
		len = ft_strlen(value_group[i]);
		j = 1;
		while (value_group[i + j])
		{
			if (len < ft_strlen(value_group[i + j]))
				len = ft_strlen(value_group[i + j]);
			if (!(ft_strncmp(value_group[i], value_group[i + j], len)))
				exit_process(1);
			j++;
		}
		i++;
	}
}

int	*atoi_only_int_range(char **value_group)
{
	int	*res;
	int	i;

	i = 0;
	while (value_group[i])
		i++;
	res = malloc(sizeof(int) * i);
	if (!(res))
		exit_process(1);
	i = 0;
	while (value_group[i])
	{
		res[i] = ft_atoi(value_group[i]);
		if (value_group[i][0] == '-' && res[i] > 0)
			exit_process(1);
		else if (value_group[i][0] != '-' && res[i] < 0)
			exit_process(1);
		i++;
	}
	return (res);
}
