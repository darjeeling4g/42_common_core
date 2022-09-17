/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 10:08:43 by siyang            #+#    #+#             */
/*   Updated: 2022/09/17 18:48:15 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h> 
#include <fcntl.h> 

char	*get_next_line(int fd)
{
	t_list	**lst;

//	char	*ptr;
//	size_t	i;
//	ssize_t	n;
//
//	i = 1;
//	while ()
//	{
//		ptr = malloc(sizeof(char) * BUFFER_SIZE * i);
//		if (ptr == NULL)
//			return (NULL);
//		n = read(fd, ptr, BUFFER_SIZE);
//		if (n < 0)
//		{
//			free(ptr);
//			return (NULL);
//		}
//		if (check_nl)
//			break ;
//	}
//	return (ptr);
}

static t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

int	main()
{
	int	fd;
	fd = open("test", O_RDWR);
	printf("%s", get_next_line(fd));
}

char	*ft_strjoin(char const *s1, char const *s2)
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
