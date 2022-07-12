/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:14:14 by siyang            #+#    #+#             */
/*   Updated: 2022/07/12 02:21:42 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *temp;
	unsigned char value;
	size_t i;

	temp = b;
	value = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		*temp = value;
		temp++;
		i++;
	}
	return (b);
}
