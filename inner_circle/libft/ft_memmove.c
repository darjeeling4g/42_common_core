/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 22:04:16 by siyang            #+#    #+#             */
/*   Updated: 2022/07/12 14:04:40 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void *ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *temp_dst;
	const unsigned char *temp_src;
	unsigned char buffer[len];
	size_t i;

	temp_dst = dst;
	temp_src = src;
	i = 0;
	while (i < len)
	{
		buffer[i] = temp_src[i];
		i++;
	}
	i = 0;
	while (i < len)
	{
		temp_dst[i] =  buffer[i];
		i++;
	}
	return (dst);
}
