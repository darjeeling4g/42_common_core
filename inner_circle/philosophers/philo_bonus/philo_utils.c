/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 21:22:43 by siyang            #+#    #+#             */
/*   Updated: 2023/04/18 20:32:40 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	handle_over_ll(unsigned long long result, int sign);

void	custom_usleep(int time)
{
	long long	target;

	target = get_time() + (long long)time;
	usleep(time * 700);
	while (get_time() < target)
		usleep(200);
}

long long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	safe_print(t_philo *philo, char *msg)
{
	long long	time;

	pthread_mutex_lock(&(philo->info->m_end));
	if (philo->info->is_end == ON)
	{
		pthread_mutex_unlock(&(philo->info->m_end));
		return (1);
	}
	time = get_time() - philo->info->start_time;
	printf("%lld %d %s\n", time, philo->id, msg);
	pthread_mutex_unlock(&(philo->info->m_end));
	return (0);
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

