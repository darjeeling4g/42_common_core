/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yangsiseon <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 18:42:50 by yangsiseon        #+#    #+#             */
/*   Updated: 2022/08/09 22:56:32 by yangsiseon       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_num(int n);

char	*ft_itoa(int n)
{
	char	*ptr;
	int		sign;
	int		i;

	sign = 0;
	if (n < 0)
		sign = 1;
	i = len_num(n) + sign;
	ptr = calloc(i + 1, 1);
	if (ptr == NULL)
		return (NULL);
	if (n == 0)
		ptr[i - 1] = '0';
	if (sign == 1)
		ptr[0] = '-';
	while (n != 0)
	{
		if (sign == 0)
			ptr[i - 1] = n % 10 + '0';
		else if (sign == 1)
			ptr[i - 1] = n % 10 * -1 + '0';
		n = n / 10;
		i--;
	}
	return (ptr);
}

static int	len_num(int n)
{
	int len;

	if (n == 0)
		return (1);
	len = 0;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}
