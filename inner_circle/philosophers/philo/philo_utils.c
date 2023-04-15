/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 21:22:43 by siyang            #+#    #+#             */
/*   Updated: 2023/04/15 15:15:11 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	handle_over_ll(unsigned long long result, int sign);

long long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	multy_free(void *arg1, void *arg2, void *arg3)
{
	if (arg1)
		free(arg1);
	if (arg2)
		free(arg2);
	if (arg3)
		free(arg3);
	return (1);
}

int	print_error(char *str)
{
	printf("%s\n", str);
	return (1);
}

int	ft_atoi(const char *str)
{
	int					sign;
	unsigned long long	result;

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
		result *= 10;
		result += *str - '0';
		str++;
	}
	result = handle_over_ll(result, sign);
	if (sign == 1)
		return (result * -1);
	return (result);
}

static int	handle_over_ll(unsigned long long result, int sign)
{
	if (result > 9223372036854775807)
	{
		if (sign == 1)
			return (0);
		return (-1);
	}
	return (result);
}

