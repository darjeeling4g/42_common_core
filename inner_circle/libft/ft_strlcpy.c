/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 23:01:57 by siyang            #+#    #+#             */
/*   Updated: 2022/07/12 08:56:03 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

size_t ft_strlcpy(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t srclen;

	srclen = 0;
	while (*src)
	{
		if (srclen + 1 < dstsize)
		{
			*dst = *src;
			dst++;
		}
		src++;
		srclen++;
	}
	*dst = '\0';
	return (srclen);
}
