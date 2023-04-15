/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 17:27:15 by siyang            #+#    #+#             */
/*   Updated: 2023/04/15 18:51:36 by siyang           ###   ########.fr       */
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
		if (get_fork(philo))
			break ;
		if (eat(philo))
			break ;
		if (sleep_n_think(philo))
			break ;
	}
	return (NULL);
}

int	get_fork(t_philo *philo)
{
	while (1)
	{
		pthread_mutex_lock(&(philo->info->m_forks[philo->l_fork]));
		if (philo->info->forks[philo->l_fork] == ON)
		{
			philo->info->forks[philo->l_fork] = OFF;
			if (safe_print(philo, "has taken a fork"))
			{
				philo->info->forks[philo->l_fork] = ON;
				pthread_mutex_unlock(&(philo->info->m_forks[philo->l_fork]));
				return (1);
			}
			break ;
		}
		pthread_mutex_unlock(&(philo->info->m_forks[philo->l_fork]));
	}
	pthread_mutex_unlock(&(philo->info->m_forks[philo->l_fork]));
	while (1)
	{
		pthread_mutex_lock(&(philo->info->m_forks[philo->r_fork]));
		if (philo->info->forks[philo->r_fork] == ON)
		{
			philo->info->forks[philo->r_fork] = OFF;
			if (safe_print(philo, "has taken a fork"))
			{
				philo->info->forks[philo->r_fork] = ON;
				pthread_mutex_unlock(&(philo->info->m_forks[philo->r_fork]));
				return (1);
			}
			break ;
		}
		pthread_mutex_unlock(&(philo->info->m_forks[philo->r_fork]));
	}
	pthread_mutex_unlock(&(philo->info->m_forks[philo->r_fork]));
	return (0);
}

int	eat(t_philo *philo)
{
	pthread_mutex_lock(&(philo->m_eat));
	if (philo->info->number_of_must_eat > 0)
		philo->number_of_eat++;
	if (safe_print(philo, "is eating"))
	{
		pthread_mutex_unlock(&(philo->m_eat));
		return (1);
	}
	philo->time_of_last_eat = get_time();
	pthread_mutex_unlock(&(philo->m_eat));
	custom_usleep(philo->info->time_to_eat);
	pthread_mutex_lock(&(philo->info->m_forks[philo->l_fork]));
	philo->info->forks[philo->l_fork] = ON;
	pthread_mutex_unlock(&(philo->info->m_forks[philo->l_fork]));
	pthread_mutex_lock(&(philo->info->m_forks[philo->r_fork]));
	philo->info->forks[philo->r_fork] = ON;
	pthread_mutex_unlock(&(philo->info->m_forks[philo->r_fork]));
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

