/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 17:20:14 by siyang            #+#    #+#             */
/*   Updated: 2022/08/31 16:17:08 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
//	size_t	i;

//	if (count == 0 || size == 0)
//	{
//		size = 1;
//		count = 1;
//	}
	ptr = malloc(size * count);
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, 0, size * count);
//	i = 0;
//	while (i < size * count)
//	{
//		ptr[i] = 0;
//		i++;
//	}
	return (ptr);
}
