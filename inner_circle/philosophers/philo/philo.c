/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 19:54:14 by siyang            #+#    #+#             */
/*   Updated: 2023/04/14 21:28:32 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	// exception -> number of arg
	// 	return 1
	// setup()
	// 	return setup-error
	// while(number_of_philos)
	// 	pthread create --> philo_loop()
	// monitoring_loop()
	// finish_process()

	t_info	info;
	t_philo	*philos;

	if (argc != 5 && argc != 6)
		return (print_error("Error: number of arguments must be 4 or 5"));
	if (setup(argv, &info, &philos))
		return (print_error("Error: setup failure");
}

//int	setup_info(char **argv, t_info *info)
//{
//
//}
//
//int	setup_philo(t_philo *philos)
//{
//
//}

int	setup(char **argv, t_info *info, t_philo **philos)
{
//	if (setup_info(argv, info))
//		return (1);
//	*philos = malloc(sizeof(t_philo) * info->number_of_philo);
//	if (*philos = NULL)
//		return (1);
//	if (setup_philo(*philos))
//		return (1);
//	info->start_time = get_time();
//	return (0);

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
