/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 10:08:43 by siyang            #+#    #+#             */
/*   Updated: 2022/09/07 17:01:57 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h> 
#include <fcntl.h> 

static int	check_nl(char *ptr);

char	*get_next_line(int fd)
{
	char	*ptr;
	size_t	i;
	ssize_t	n;

	i = 1;
	while ()
	{
		ptr = malloc(sizeof(char) * BUFFER_SIZE * i);
		if (ptr == NULL)
			return (NULL);
		n = read(fd, ptr, BUFFER_SIZE);
		if (n < 0)
		{
			free(ptr);
			return (NULL);
		}
		if (check_nl)
			break ;
	}
	return (ptr);
}

static int	check_nl(char *ptr)
{
	while (*ptr)
	{
		if (*ptr == '\n')
			return (1);
		ptr++;
	}
	return (0);
}


int	main()
{
	int	fd;
	fd = open("test", O_RDWR);
	printf("%s", get_next_line(fd));
}
