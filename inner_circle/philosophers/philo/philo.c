/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 19:54:14 by siyang            #+#    #+#             */
/*   Updated: 2023/04/14 20:31:16 by siyang           ###   ########.fr       */
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

	// exception -> number of arg
	// 	return 1
	// setup()
	// 	return setup-error
	// while(number_of_philos)
	// 	pthread create --> philo_loop()
	// monitoring_loop()
	// finish_process()
}

int	setup()
{
	// setup info struct
	// 	atoi(number of philo)
	// 	atoi(time to die)
	// 	atoi(time to eat)
	// 	atoi(time to sleep)
	// 	atoi(number of must eat)
	// 	start_time = 0
	// 	is_end = FALSE
	// 	forks = malloc int * number of philo
	// 	m_fokrs = malloc mutex_t * number of philo
	// 	mutex init m_end
	// 	mutex init m_print
	// 	mutex init m_forks
	
	// malloc philo struct array
	// setup philo struct
	// 	while (number of philo)
	// 		id = i + 1
	// 		number of eat = 0
	// 		time of last eat = 0
	// 		mutext init m_eat
	// 		info = &info
	
	// start time = get_time()
}

long long get_time()
{
	// gettimeofday
	// return (tv.sec * 1000 + tv.uset / 1000)
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

int	get_fork()
{

}

int	eat()
{

}

int	sleep()
{

}

int	think()
{

}

void	monitoring_loop()
{

}
