/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 14:47:55 by siyang            #+#    #+#             */
/*   Updated: 2022/08/05 18:36:36 by yangsiseon       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	char	*temp;

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
