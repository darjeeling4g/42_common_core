/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 16:09:58 by siyang            #+#    #+#             */
/*   Updated: 2023/04/22 09:06:24 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	handle_over_ll(unsigned long long result, int sign);
static int	len_num(int n);

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

int	safe_print(t_info *info, char *msg)
{
	long long	time;

	sem_wait(info->bs_end);
	if (info->is_end == ON)
	{
		sem_post(info->bs_end);
		return (1);
	}
	time = get_time() - info->start_time;
	sem_wait(info->bs_print);
	printf("%lld %d %s\n", time, info->id, msg);
	sem_post(info->bs_print);
	sem_post(info->bs_end);
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

char	*ft_itoa(int n)
{
	char	*ptr;
	int		sign;
	int		i;

	sign = 0;
	if (n < 0)
		sign = 1;
	i = len_num(n) + sign;
	ptr = malloc(i + 1);
	if (ptr == NULL)
		return (NULL);
	ptr[i] = '\0';
	while (i > 0)
	{
		if (sign == 0)
			ptr[i - 1] = n % 10 + '0';
		else if (sign == 1)
			ptr[i - 1] = n % 10 * -1 + '0';
		n = n / 10;
		i--;
	}
	if (sign == 1)
		ptr[0] = '-';
	return (ptr);
}

static int	len_num(int n)
{
	int	len;

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
