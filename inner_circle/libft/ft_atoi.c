/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 16:25:20 by siyang            #+#    #+#             */
/*   Updated: 2022/07/16 17:15:25 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int sign;
	int result;

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
