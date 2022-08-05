/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yangsiseon <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 17:42:07 by yangsiseon        #+#    #+#             */
/*   Updated: 2022/08/05 17:42:11 by yangsiseon       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	sign;
	int	result;

	sign = 0;
	result = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		str++;
		sign = 1;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 - '0' + *str;
		str++;
	}
	if (sign == 1)
		return (result * -1);
	return (result);
}
