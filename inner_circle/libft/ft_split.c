/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yangsiseon <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 23:30:06 by yangsiseon        #+#    #+#             */
/*   Updated: 2022/07/26 13:36:35 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t count_str(char const *s, char c);	
static size_t len_str(char const *s, char c);
	
char	**ft_split(char const *s, char c)
{
	char	**ptr;
	size_t	count;
	size_t	len;
	size_t	i;
	size_t	j;

	count = count_str(s, c);
	ptr = malloc(sizeof(char *) * (count + 1));
	ptr[count] = NULL;
	i = 0;
	while (i < count)
	{
		while (*s == c)
			s++;
		len = len_str(s, c);
		ptr[i] = malloc(len + 1);
		j = 0;
		while (j < len)
		{
			ptr[i][j] =  s[j];
			j++;
		}
		ptr[i][len] = '\0';
		s = s + len;
		i++;
	}
	return (ptr);
}

static size_t count_str(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
			count++;
		s++;		
	}
	return (count);
}

static size_t len_str(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (*s != c || *s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}
