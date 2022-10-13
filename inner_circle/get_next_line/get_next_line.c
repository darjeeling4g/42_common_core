/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 10:08:43 by siyang            #+#    #+#             */
/*   Updated: 2022/10/13 19:55:14 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h> 
#include <fcntl.h> 

char	*get_next_line(int fd)
{
//	static ssize_t	fo;
	ssize_t			nbyte;
	char			*buffer;
	char			*result;
	char			*temp;
	int				i;
	int				eol;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	buffer[BUFFER_SIZE] = '\0';
	result = NULL;
	eol = 0;
	while (eol == 0)
	{
		nbyte = read(fd, buffer, BUFFER_SIZE);
		if (nbyte < 0)
			return (NULL);
		else if (nbyte == 0)
			return (result);
		else
		{
			i = 0;
			while (i < nbyte)
			{
				if (buffer[i] == '\n')
					break ;
				i++;
			}
			if (i < nbyte)
			{
				buffer[i + 1] = '\0';
				eol = 1;
			}
			temp = result;
			result = ft_strjoin(result, buffer);
			free(temp);
		}
	}
	free(buffer);
	return (result);
}

static char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	char	*temp;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	ptr = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (ptr == NULL)
		return (NULL);
	temp = ptr;
	while (*s1)
	{	
		*temp = *s1;
		temp++;
		s1++;
	}
	while (*s2)
	{
		*temp = *s2;
		temp++;
		s2++;
	}
	*temp = '\0';
	return (ptr);
}

static size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s)
	{
		s++;
		len++;
	}
	return (len);
}

int	main()
{
	int	fd;
	fd = open("test", O_RDWR);
	printf("%s", get_next_line(fd));
}
