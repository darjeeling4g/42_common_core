/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 21:58:34 by siyang            #+#    #+#             */
/*   Updated: 2023/04/15 18:31:47 by siyang           ###   ########.fr       */
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
//  pthread_create, pthread_detach, pthread_join
//  pthread_mutex_init, pthread_mutex_destroy
//  pthread_mutex_lock, pthread_mutex_unlock
# include <pthread.h>

# define OFF 0
# define ON 1

# define FORK 0
# define EAT 1
# define SLEEP 2
# define THINK 3
# define DIE 4

typedef struct s_info
{
	// Read only(philos, monitor)
	int				number_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_must_eat;
	long long		start_time;

	// Read(philos) & Write(monitor) => need mutex
	int				is_end;

	// Read(philos) & Write(philos) => need mutex
	int				*forks;

	// philo vs philo vs monitor
	pthread_mutex_t	m_print;
	pthread_mutex_t	m_end;

	// philo vs philo
	pthread_mutex_t	*m_forks;
}	t_info;

typedef struct s_philo
{
	// Read only(philo, monitor)
	int				id;
	int				l_fork;
	int				r_fork;
	pthread_t		philo;

	// Read(monitor) & Write(philo) => need mutex
	int				number_of_eat;
	long long		time_of_last_eat;

	// philo vs monitor
	pthread_mutex_t	m_eat;

	struct s_info	*info;
}	t_philo;

typedef struct s_monitor
{
	struct s_info	*info;
	struct s_philo	*philos;
}	t_monitor;

// philo.c

// philo_utils.c
long long	get_time(void);
void		custom_usleep(int time);
int			safe_print(t_philo *philo, char *msg);
int			multy_free(void *arg1, void *arg2, void *arg3);
int			print_error(char *str);
int			ft_atoi(const char *str);

// philo_setup.c
int	setup(char **argv, t_info *info, t_philo **philos);
int	setup_info(char **argv, t_info *info);
int	setup_info_arg(char **argv, t_info *info);
int	setup_philo(t_info *info, t_philo *philos);

// philo_loop.c
void	*philo_loop(void *arg);
int		get_fork(t_philo *philo);
int		eat(t_philo *philo);
int		sleep_n_think(t_philo *philo);

#endif
