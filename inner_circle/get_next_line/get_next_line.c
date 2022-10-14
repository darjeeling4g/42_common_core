/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 10:08:43 by siyang            #+#    #+#             */
/*   Updated: 2022/10/14 21:39:49 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//#include <stdio.h> 
//#include <fcntl.h> 

static int	get_until_eol(char *buffer, char **backup, char **result);

char	*get_next_line(int fd)
{
	static char	*backup;
	ssize_t		nbyte;
	char		*buffer;
	char		*result;
	int			eol;

	result = malloc(sizeof(char) * 1);
	result[0] = 0;
	eol = 0;
	if (backup)
	{
		buffer = backup;
		eol = get_until_eol(buffer, &backup, &result);
		free(buffer);
	}
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	buffer[BUFFER_SIZE] = '\0';
	while (eol == 0)
	{
		nbyte = read(fd, buffer, BUFFER_SIZE);
		if (nbyte < 0)
			return (NULL);
		else if (nbyte == 0)
			return (result);
		else
			eol = get_until_eol(buffer, &backup, &result);
	}
	free(buffer);
	return (result);
}

static int	get_until_eol(char *buffer, char **backup, char **result)
{
	char	*temp;
	int		eol;

	eol = 0;
	temp = ft_strchr(buffer, '\n');
	if (temp != NULL)
	{
		*backup = ft_strdup(temp + 1);
		temp[1] = '\0';
		eol = 1;
	}
	temp = *result;
	*result = ft_strjoin(*result, buffer);
	free(temp);
	return (eol);
}

//int	main()
//{
//	int	fd;
//	fd = open("test", O_RDWR);
//	printf("%s", get_next_line(fd));
//	printf("%s", get_next_line(fd));
//	printf("%s", get_next_line(fd));
//	printf("%s", get_next_line(fd));
//}
