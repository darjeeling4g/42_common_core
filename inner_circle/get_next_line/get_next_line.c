/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 10:08:43 by siyang            #+#    #+#             */
/*   Updated: 2022/09/08 10:46:20 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h> 
#include <fcntl.h> 

char	*get_next_line(int fd)
{
	t_list	**lst;

	lst = malloc(sizeof(t_list *);
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
