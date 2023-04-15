/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 19:54:14 by siyang            #+#    #+#             */
/*   Updated: 2023/04/15 17:33:39 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	monitoring_loop(void)
{
	while(1);
}

int	main(int argc, char **argv)
{
	// while(number_of_philos)
	// 	pthread create --> philo_loop()
	// monitoring_loop()
	// finish_process()

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
	monitoring_loop();

	/* setup test

	printf("===================info struct==========================\n");
	printf("number of philo : %d\n", info.number_of_philo);
	printf("time to die: %d\n", info.time_to_die);
	printf("time to eat: %d\n", info.time_to_eat);
	printf("time to sleep: %d\n", info.time_to_sleep);
	printf("number of must eat: %d\n", info.number_of_must_eat);
	printf("start time : %lld\n", info.start_time);

	printf("===================philo struct==========================\n");
	for (int i = 0; i < info.number_of_philo; i++)
	{
		printf("id : %d\n", philos[i].id);
		printf("l_fork : %d\n", philos[i].l_fork);
		printf("r_fork : %d\n", philos[i].r_fork);
		printf("number of eat : %d\n", philos[i].number_of_eat);
		printf("time of last eat : %lld\n", philos[i].time_of_last_eat);
	}

	*/
}

