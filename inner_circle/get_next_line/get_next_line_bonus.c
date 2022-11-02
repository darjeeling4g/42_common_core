/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 10:08:43 by siyang            #+#    #+#             */
/*   Updated: 2022/11/02 19:42:50 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//#include <stdio.h> 
//#include <fcntl.h> 

static void	get_until_eol(char *buffer, char **backup, char **result);

char	*get_next_line(int fd)
{
	static char	*backup[257];
	ssize_t		nbyte;
	char		*buffer;
	char		*result;

	result = ft_strdup("");
	if (result == NULL)
	{
		free(result);
		return(NULL);
	}
	if (backup[fd])
	{
		buffer = backup[fd];
		get_until_eol(buffer, &backup[fd], &result);
		free(buffer);
	}
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
	{
		free(buffer);
		free(result);
		return (NULL);
	}
	buffer[BUFFER_SIZE] = '\0';
	while (!backup[fd])
	{
		nbyte = read(fd, buffer, BUFFER_SIZE);
		if (nbyte < 0 || (nbyte == 0 && *result == '\0'))
		{
			free(result);
			free(buffer);
			return (NULL);
		}
		else if (nbyte == 0)
			break ;
		else
			get_until_eol(buffer, &backup[fd], &result);
	}
	free(buffer);
	return (result);
}

static void	get_until_eol(char *buffer, char **backup, char **result)
{
	char	*temp;

	temp = ft_strchr(buffer, '\n');
	if (temp != NULL)
	{
		*backup = ft_strdup(temp + 1);
		temp[1] = '\0';
	}
	else
		*backup = NULL;
	temp = *result;
	*result = ft_strjoin(*result, buffer);
	free(temp);
}

//int	main()
//{
//	int	fd;
//	fd = open("test", O_RDWR);
//	printf("%s", get_next_line(fd));
//	printf("%s", get_next_line(fd));
//	system("leaks a.out");
//}
