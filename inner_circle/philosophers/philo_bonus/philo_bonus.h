/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 21:58:34 by siyang            #+#    #+#             */
/*   Updated: 2023/04/22 18:37:53 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

// memset
# include <string.h>
// printf
# include <stdio.h>
// malloc, free, exit
# include <stdlib.h>
// write, fork, usleep
# include <unistd.h>
// kill
# include <signal.h>
// gettimeofday
# include <sys/time.h>
// waitpid
# include <sys/wait.h>
// pthread_create, pthread_detach, pthread_join,
# include <pthread.h>
// sem_open, sem_close, sem_post, sem_wait, sem_unlink
# include <semaphore.h>

# define OFF 0
# define ON 1

typedef struct s_info
{
	int			number_of_philo;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			number_of_must_eat;
	int			id;
	long long	start_time;
	pthread_t	philo;
	pid_t		*pid;
	int			number_of_eat;
	long long	time_of_last_eat;
	int			is_end;
	sem_t		*bs_eat;
	sem_t		*bs_end;
	sem_t		*bs_print;
	sem_t		*cs_fork;
}	t_info;

// philo_bonus.c
void		main_monitor_loop(t_info *info);
void		sub_monitor_loop(t_info *info);
void		check_starvation(t_info *info, long long time);

// philo_error_bonus.c
int			print_error(char *msg);
void		clean_process(t_info *info);
void		exit_process(t_info *info, int code);

// philo_utils_bonus.c
void		custom_usleep(int time);
long long	get_time(void);
int			safe_print(t_info *info, char *msg);
int			ft_atoi(const char *str);

// philo_setup_bonus.c
int			setup(char **argv, t_info *info);
int			setup_arg(char **argv, t_info *info);

// philo_loop_bonus.c
void		*philo_loop(void *arg);
int			pick_up_fork(t_info *info);
int			eat(t_info *info);
int			sleep_n_think(t_info *info);

#endif
