/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 21:58:34 by siyang            #+#    #+#             */
/*   Updated: 2023/04/19 17:06:24 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

// memset
# include <string.h>
// printf
# include <stdio.h>
// malloc, free
# include <stdlib.h>
// write, usleep
# include <unistd.h>
// gettimeofday
# include <sys/time.h>
// pthread_create, pthread_detach, pthread_join,
// pthread_mutex_init, pthread_mutex_destroy,
// pthread_mutex_lock, pthread_mutex_unlock
# include <pthread.h>

# define OFF 0
# define ON 1

# define LEFT 0
# define RIGHT 1

typedef struct s_info
{
	int				number_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_must_eat;
	long long		start_time;
	int				is_end;
	int				*forks;
	pthread_mutex_t	m_end;
	pthread_mutex_t	*m_forks;
}	t_info;

typedef struct s_philo
{
	int				id;
	int				l_fork;
	int				r_fork;
	pthread_t		philo;
	int				number_of_eat;
	long long		time_of_last_eat;
	pthread_mutex_t	m_eat;
	struct s_info	*info;
}	t_philo;

// philo.c
void		monitoring_loop(t_info *info, t_philo *philos);
int			check_starvation(t_info *info, t_philo *philo, \
			int *count, long long time);
int			clean_process(t_info *info, t_philo *philos);

// philo_error.c
int			multy_free(void *arg1, void *arg2, void *arg3);
int			print_error(char *str);

// philo_utils.c
long long	get_time(void);
void		custom_usleep(int time);
int			safe_print(t_philo *philo, char *msg);
int			ft_atoi(const char *str);

// philo_setup.c
int			setup(char **argv, t_info *info, t_philo **philos);
int			setup_info(char **argv, t_info *info);
int			setup_info_arg(char **argv, t_info *info);
int			setup_philo(t_info *info, t_philo *philos);

// philo_loop.c
void		*philo_loop(void *arg);
int			pick_up_fork(t_philo *philo, int hand);
void		put_down_fork(t_info *info, int fork);
int			eat(t_philo *philo);
int			sleep_n_think(t_philo *philo);

#endif
