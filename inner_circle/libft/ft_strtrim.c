/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yangsiseon <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 22:31:41 by yangsiseon        #+#    #+#             */
/*   Updated: 2022/07/25 23:27:21 by yangsiseon       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	char	*ptr;

	while (*s1)
	{
		if (ft_strchr(set, *s1) == NULL)
			break ;
		s1++;
	}
	len = ft_strlen(s1);
	while (len > 0)
	{
		if (ft_strchr(set, s1[len - 1]) == NULL)
			break ;
		len--;
	}
	ptr = malloc(len + 1);
	ft_strlcpy(ptr, s1, len + 1);
	return (ptr);
}
