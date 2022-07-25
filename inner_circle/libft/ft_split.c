/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yangsiseon <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 23:30:06 by yangsiseon        #+#    #+#             */
/*   Updated: 2022/07/26 00:02:25 by yangsiseon       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t count_str(char const *s, char c);	
	
char	**ft_split(char const *s, char c)
{
	char	**ptr;
	size_t	count;
	size_t	i;

	count = count_str(s, c);
	ptr = malloc(count + 1);
	ptr[count] = NULL;
	while (*s == c)
		s++;
	i = 0;
	while (i < count)
	{
		ptr[i] = malloc
	}
	return (ptr);
}

static size_t count_str(char const *s, char c)
{
	size_t	count;

	while (*s)
	{
		if (*s != c && (*(s + 1) == c) || *(s + 1) == '\0')
			count++;
		s++;		
	}
	return (count);
}

static size_t len_str(char const *s, char c)
{
	size_t	len;

}
