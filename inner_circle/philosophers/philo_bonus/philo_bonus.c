/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 15:59:43 by siyang            #+#    #+#             */
/*   Updated: 2023/04/20 18:57:30 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char **argv)
{
	t_info	info;
	pid_t	pid;
	int		i;

	if (argc != 5 && argc != 6)
		return (print_error("Error: number of arguments must be 4 or 5"));
	if (setup(argv, &info))
		return (print_error("Error: setup failure"));
	i = -1;
	while (++i < info.number_of_philo)
	{
		pid = fork();
		if (!pid)
		{
			info.id = i + 1;
			pthread_create(&(info.philo), NULL, philo_loop, &info);
//			sub_monitor_loop();
		}
	}
	main_monitor_loop(&info);
//	if (clean_process(&info, philos))
//		return (print_error("Error: clean failure"));
}

//void	sub_monitor_loop()
//{
//
//}

void	main_monitor_loop(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->number_of_philo)
	{
		waitpid(0, NULL, 0);
		i++;
	}
}
