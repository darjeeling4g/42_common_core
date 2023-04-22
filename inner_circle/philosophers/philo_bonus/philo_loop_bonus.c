/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_loop_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:48:27 by siyang            #+#    #+#             */
/*   Updated: 2023/04/22 09:14:40 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*philo_loop(void *arg)
{
	t_info	*info;
	
	info = (t_info *)arg;
	if (info->id % 2 == 0)
		usleep(info->time_to_eat * 500);
	while (1)
	{
		if (pick_up_fork(info))
			break ;
		if (eat(info))
			break ;
		if (sleep_n_think(info))
			break ;
	}
	return (NULL);
}

int	pick_up_fork(t_info *info)
{
	sem_wait(info->cs_fork);
	if (safe_print(info, "has taken a fork"))
	{
		sem_post(info->cs_fork);
		return (1);
	}
	if (info->number_of_philo == 1)
	{
		sem_post(info->cs_fork);
		return (1);
	}
	sem_wait(info->cs_fork);
	if (safe_print(info, "has taken a fork"))
	{
		sem_post(info->cs_fork);
		sem_post(info->cs_fork);
		return (1);
	}
	return (0);
}

int	eat(t_info *info)
{
	sem_wait(info->bs_eat[info->id - 1]);
	if (safe_print(info, "is eating"))
	{
		sem_post(info->bs_eat[info->id - 1]);
		sem_post(info->cs_fork);
		sem_post(info->cs_fork);
		return (1);
	}
	info->time_of_last_eat = get_time();
	sem_post(info->bs_eat[info->id - 1]);
	custom_usleep(info->time_to_eat);
	sem_post(info->cs_fork);
	sem_post(info->cs_fork);
	sem_wait(info->bs_eat[info->id - 1]);
	if (info->number_of_must_eat > 0)
	{
		info->number_of_eat++;
		if (info->number_of_eat == info->number_of_must_eat)
		{
			sem_post(info->bs_eat[info->id - 1]);
			return (1);
		}
	}
	sem_post(info->bs_eat[info->id - 1]);
	return (0);
}

int	sleep_n_think(t_info *info)
{
	if (safe_print(info, "is sleeping"))
		return (1);
	custom_usleep(info->time_to_sleep);
	if (safe_print(info, "is thinking"))
		return (1);
	return (0);
}

