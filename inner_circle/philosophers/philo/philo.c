/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 19:54:14 by siyang            #+#    #+#             */
/*   Updated: 2023/04/15 15:16:08 by siyang           ###   ########.fr       */
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
