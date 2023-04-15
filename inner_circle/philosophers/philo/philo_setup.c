/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_setup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 15:12:55 by siyang            #+#    #+#             */
/*   Updated: 2023/04/15 15:13:41 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	setup(char **argv, t_info *info, t_philo **philos)
{
	if (setup_info(argv, info))
		return (1);
	*philos = malloc(sizeof(t_philo) * info->number_of_philo);
	if (*philos = NULL)
		return (multy_free(info->forks, info->m_forks, NULL));
	if (setup_philo(info, *philos))
		return (1);
	info->start_time = get_time();
	return (0);
}

int	setup_info(char **argv, t_info *info)
{
	int i;

	info->number_of_philo = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5] == 0)
		info->number_of_must_eat = -1;
	else
		info->number_of_must_eat = ft_atoi(argv[5]);
	info->is_end = OFF;
	info->forks = malloc(sizeof(int) * info->number_of_philo);
	if (info->forks == NULL)
		return (1);
	info->m_forks = malloc(sizeof(pthread_mutex_t) * info->number_of_philo);
	if (info->m_forks == NULL)
		return (multy_free(info->forks, NULL, NULL));
	i = -1;
	while (++i < info->number_of_philo)
	{
		info->forks[i] = ON;
		if (pthread_mutex_init(info->m_forks[i], NULL))
			return (multy_free(info->forks, info->m_forks, NULL));
	}
	if (pthread_mutex_init(m_print, NULL);
		return (multy_free(info->forks, info->m_forks, NULL));
	if (pthread_mutex_init(m_end, NULL);
		return (multy_free(info->forks, info->m_forks, NULL));
	return (0);
}

int	setup_philo(t_info *info, t_philo *philos)
{
	int	i;

	i = -1
	while (++i < info->number_of_philo)
	{
		philos[i].id = i + 1;
		philos[i].number_of_eat = 0;
		philos[i].time_of_last_eat = 0;
		philos[i].info = info;
		if (pthread_mutex_init(philos[i].m_eat));
			return (multy_free(info->forks, info->m_forks, philos));
	}
	return (0);
}

