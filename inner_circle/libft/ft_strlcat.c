/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 09:12:51 by siyang            #+#    #+#             */
/*   Updated: 2022/07/12 09:25:10 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;
	size_t	dstlen;

	dstlen = 0;
	while (*dst)
	{
		dst++;
		dstlen++;
	}
	srclen = 0;
	while (*src)
	{
		if (srclen + dstlen + 1 < dstsize)
		{
			*dst = *src;
			dst++;
		}
		src++;
		srclen++;
	}
	*dst = '\0';
	if (dstsize <= dstlen)
		return (dstsize + srclen);
	else
		return (dstlen + srclen);
}
