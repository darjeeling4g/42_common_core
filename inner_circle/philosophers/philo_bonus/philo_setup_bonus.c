/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_setup_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 16:05:33 by siyang            #+#    #+#             */
/*   Updated: 2023/04/20 19:13:25 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	setup(char **argv, t_info *info)
{
	info->number_of_philo = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5] == 0)
		info->number_of_must_eat = -1;
	else
		info->number_of_must_eat = ft_atoi(argv[5]);
	if (info->number_of_philo <= 0 || info->time_to_die <= 0 || \
		info->time_to_eat <= 0 || info->time_to_sleep <= 0 || \
		(argv[5] != 0 && info->number_of_must_eat <= 0))
		return (1);
	info->id = -1;
	info->is_end = OFF;
	info->number_of_eat = 0;
	sem_unlink("EAT");
	info->bs_eat = sem_open("EAT", O_CREAT, 0644, 1);
	sem_unlink("END");
	info->bs_eat = sem_open("END", O_CREAT, 0644, 1);
	sem_unlink("FORK");
	info->cs_fork = sem_open("FORK", O_CREAT, 0644, info->number_of_philo);
//	info->cs_pair = sem_open("PAIR", 0644, O_CREAT, info->number_of_philo / 2);
//	if (info->bs_eat == SEM_FAILED || info->bs_end == SEM_FAILED || \
//			info->cs_fork == SEM_FAILED || info->cs_pair == SEM_FAILED)
	printf("%p %p %p\n", info->bs_eat, info->bs_end, info->cs_fork);
	if (info->bs_eat == SEM_FAILED || info->bs_end == SEM_FAILED || \
			info->cs_fork == SEM_FAILED)
		return (1);
	info->start_time = get_time();
	info->time_of_last_eat = info->start_time;

	/*
	info->sb_eat = malloc(sizeof(sem_t *) * info->number_of_philo);
	if (info->sb_eat == NULL)
		return (1);
	while ()
	{
		info->sb_eat[i] = sem_open("", );
		if (info->sb_eat[i] == SEM_FAILED)
		{
			free(info->sb_eat);
			return (1);
		}
	}
	*/
	return (0);
}
