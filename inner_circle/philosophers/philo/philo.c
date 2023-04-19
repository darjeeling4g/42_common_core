/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 19:54:14 by siyang            #+#    #+#             */
/*   Updated: 2023/04/19 13:39:39 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	clean_process(t_info *info, t_philo *philos)
{
	int i;

	i = 0;
	while (i < info->number_of_philo)
	{
		if (pthread_join(philos[i].philo, NULL))
			return (1);
		if (pthread_mutex_destroy(&(philos[i].m_eat)))
			return (1);
		if (pthread_mutex_destroy(&(info->m_forks[i])))
			return (1);
		i++;
	}
	if (pthread_mutex_destroy(&(info->m_end)))
		return (1);
	multy_free(info->forks, info->m_forks, philos);
	return (0);
}

void	monitoring_loop(t_info *info, t_philo *philos)
{
	int			i;
	int			count;
	long long	time;

	while (1)
	{
		// check_starvation
		i = 0;
		count = 0;
		time = get_time();
		while (i < info->number_of_philo)
		{
			pthread_mutex_lock(&(philos[i].m_eat));
			if (info->number_of_must_eat == philos[i].number_of_eat)
				count++;
			if (info->time_to_die <= time - philos[i].time_of_last_eat)
			{
				pthread_mutex_lock(&(info->m_end));
				info->is_end = ON;
				printf("%lld %d %s\n", time - info->start_time, philos[i].id, "died");
				pthread_mutex_unlock(&(info->m_end));
				pthread_mutex_unlock(&(philos[i].m_eat));
				return ;
			}
			pthread_mutex_unlock(&(philos[i].m_eat));
			i++;
		}

		// check_count
		if (count == info->number_of_philo)
		{
			pthread_mutex_lock(&(info->m_end));
			info->is_end = ON;
			pthread_mutex_unlock(&(info->m_end));
			return ;
		}
	}
}

int	main(int argc, char **argv)
{
	t_info	info;
	t_philo	*philos;
	int		i;

	if (argc != 5 && argc != 6)
		return (print_error("Error: number of arguments must be 4 or 5"));
	if (setup(argv, &info, &philos))
		return (print_error("Error: setup failure"));
	i = -1;
	while (++i < info.number_of_philo)
	{
		philos[i].time_of_last_eat = info.start_time;
		pthread_create(&(philos[i].philo), NULL, philo_loop, &(philos[i]));
	}
	monitoring_loop(&info, philos);
	if (clean_process(&info, philos))
		return (print_error("Error: clean failure"));
	return (0);
}

