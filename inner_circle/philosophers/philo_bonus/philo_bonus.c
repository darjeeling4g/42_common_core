/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 15:59:43 by siyang            #+#    #+#             */
/*   Updated: 2023/04/22 08:49:28 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char **argv)
{
	t_info	info;
	int		i;

	if (argc != 5 && argc != 6)
		return (print_error("Error: number of arguments must be 4 or 5"));
	if (setup(argv, &info))
		return (print_error("Error: setup failure"));
	i = -1;
	while (++i < info.number_of_philo)
	{
		info.pid[i] = fork();
		if (!info.pid[i])
		{
			info.id = i + 1;
			pthread_create(&(info.philo), NULL, philo_loop, &info);
			sub_monitor_loop(&info);
		}
	}
	main_monitor_loop(&info);
	clean_process(&info);
	return (0);
}

void	clean_process(t_info * info)
{
	sem_close(info->bs_eat);
	sem_close(info->bs_end);
	sem_close(info->bs_print);
	sem_close(info->cs_fork);
	sem_unlink("EAT");
	sem_unlink("END");
	sem_unlink("PRINT");
	sem_unlink("FORK");
	free(info->pid);
}

void	exit_process(t_info *info, int code)
{
	pthread_join(info->philo, NULL);
	sem_close(info->bs_eat);
	sem_close(info->bs_end);
	sem_close(info->bs_print);
	sem_close(info->cs_fork);
	free(info->pid);
	exit(code);
}

void	sub_monitor_loop(t_info *info)
{
	long long	time;

	while (1)
	{
		sem_wait(info->bs_eat);
		time = get_time();
		if (info->number_of_must_eat == info->number_of_eat)
		{
			sem_wait(info->bs_end);
			info->is_end = ON;
			sem_post(info->bs_end);
			sem_post(info->bs_eat);
			exit_process(info, 0);
		}
		else if (info->time_to_die <= time - info->time_of_last_eat)
		{
			sem_wait(info->bs_end);
			info->is_end = ON;
			sem_wait(info->bs_print);
			printf("%lld %d %s\n", time - info->start_time, info->id, "died");
			sem_post(info->bs_end);
			sem_post(info->bs_eat);
			exit_process(info, 1);
		}
		sem_post(info->bs_eat);
	}
}

void	main_monitor_loop(t_info *info)
{
	int	i;
	int	j;
	int	status;
	char	code;

	i = -1;
	while (++i < info->number_of_philo)
	{
		waitpid(0, &status, 0);
		code = status >> 8;
		if (code == 1)
			break ;
	}
	j = -1;
	while (++j < info->number_of_philo)
		kill(info->pid[j], SIGTERM);
	while (++i < info->number_of_philo)
		waitpid(0, &status, 0);
}
