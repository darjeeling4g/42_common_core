/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_error_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 20:26:14 by siyang            #+#    #+#             */
/*   Updated: 2023/04/22 18:34:21 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	print_error(char *msg)
{
	printf("%s\n", msg);
	return (1);
}

void	clean_process(t_info *info)
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
	exit(0);
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
