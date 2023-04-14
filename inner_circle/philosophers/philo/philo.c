/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 19:54:14 by siyang            #+#    #+#             */
/*   Updated: 2023/04/14 17:17:10 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_loop(void *info)
{
	(void)info;
	printf("i'm philosopher\n");
	return (NULL);
}

void	monitoring_loop()
{
	while (1);
}

int	main(int argc, char **argv)
{
	struct timeval	time;
	pthread_t		*philo;
	int				i;

	(void)argv;
	if (argc != 5 && argc != 6)
		return (1);
	gettimeofday(&time, NULL);
	printf("time test : usec: %d sec: %ld\n", time.tv_usec, time.tv_sec);
	philo = malloc(sizeof(pthread_t) * 5);
	i = -1;
	while (++i < 5)
		pthread_create(&philo[i], NULL, philo_loop, NULL);
	monitoring_loop();

	// exception (number of argc)
	// init
	// 	struct?
	// 		number of philosophers
	// 		time to die
	// 		time to eat
	// 		time to sleep
	// 		number of must eat
	// get_start_time
	// while
	// 	pthread create --> philo_loop
	// monitoring_loop
	// 	while(1)
	// 		check_died
	// 	finish_process
}

void	*philo_loop(void *philo)
{
	// if (id == even)
	// 	sleep
	// while(1)
	// 	get_fork
	// 	eat
	// 	sleep
	// 	think
}
