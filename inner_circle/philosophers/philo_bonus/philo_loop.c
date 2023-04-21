/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 17:27:15 by siyang            #+#    #+#             */
/*   Updated: 2023/04/19 15:55:58 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_loop(void *arg)
{
	t_philo	*philo;
	
	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		usleep(philo->info->time_to_eat * 500);
	while (1)
	{
		if (pick_up_fork(philo, LEFT))
			break ;
		if (pick_up_fork(philo, RIGHT))
			break ;
		if (eat(philo))
			break ;
		if (sleep_n_think(philo))
			break ;
	}
	return (NULL);
}

int	pick_up_fork(t_philo *philo, int hand)
{
	int	fork;

	if (hand == LEFT)
		fork = philo->l_fork;
	else
		fork = philo->r_fork;

	/*
	while (1)
	{
		pthread_mutex_lock(&(philo->info->m_end));
		if (philo->info->is_end == ON)
		{
			if (hand == RIGHT)
				put_down_fork(philo->info, philo->l_fork);
			pthread_mutex_unlock(&(philo->info->m_end));
			return (1);
		}
		pthread_mutex_unlock(&(philo->info->m_end));

		pthread_mutex_lock(&(philo->info->m_forks[fork]));
		if (philo->info->forks[fork] == ON)
		{
			philo->info->forks[fork] = OFF;
			if (safe_print(philo, "has taken a fork"))
			{
				if (hand == RIGHT)
					put_down_fork(philo->info, philo->l_fork);
				philo->info->forks[fork] = ON;
				pthread_mutex_unlock(&(philo->info->m_forks[fork]));
				return (1);
			}
			pthread_mutex_unlock(&(philo->info->m_forks[fork]));
			return (0);
		}
		pthread_mutex_unlock(&(philo->info->m_forks[fork]));
	}
	*/

	if (hand == RIGHT && philo->info->number_of_philo == 1)
	{
		put_down_fork(philo->info, philo->l_fork);
		return (1);
	}
	pthread_mutex_lock(&(philo->info->m_forks[fork]));
	philo->info->forks[fork] = OFF;
	if (safe_print(philo, "has taken a fork"))
	{
		if (hand == RIGHT)
			put_down_fork(philo->info, philo->l_fork);
		put_down_fork(philo->info, fork);
		return (1);
	}
	return (0);

}

void	put_down_fork(t_info *info, int fork)
{
//	pthread_mutex_lock(&(info->m_forks[fork]));
	info->forks[fork] = ON;
	pthread_mutex_unlock(&(info->m_forks[fork]));
}

int	eat(t_philo *philo)
{
	pthread_mutex_lock(&(philo->m_eat));
	if (safe_print(philo, "is eating"))
	{
		pthread_mutex_unlock(&(philo->m_eat));
		put_down_fork(philo->info, philo->l_fork);
		put_down_fork(philo->info, philo->r_fork);
		return (1);
	}
	philo->time_of_last_eat = get_time();
	pthread_mutex_unlock(&(philo->m_eat));
	custom_usleep(philo->info->time_to_eat);
	put_down_fork(philo->info, philo->l_fork);
	put_down_fork(philo->info, philo->r_fork);
	pthread_mutex_lock(&(philo->m_eat));
	if (philo->info->number_of_must_eat > 0)
	{
		philo->number_of_eat++;
		if (philo->number_of_eat == philo->info->number_of_must_eat)
		{
			pthread_mutex_unlock(&(philo->m_eat));
			return (1);
		}
	}
	pthread_mutex_unlock(&(philo->m_eat));
	return (0);
}

int	sleep_n_think(t_philo *philo)
{
	if (safe_print(philo, "is sleeping"))
		return (1);
	custom_usleep(philo->info->time_to_sleep);
	if (safe_print(philo, "is thinking"))
		return (1);
	return (0);
}

