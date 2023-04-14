/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 21:58:34 by siyang            #+#    #+#             */
/*   Updated: 2023/04/14 17:17:04 by siyang           ###   ########.fr       */
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

# define NUM 1
# define DIE 2
# define EAT 3
# define SLEEP 4
# define LIMIT 5

typedef struct s_info
{
	// Read only(philos, monitor)
	int				number_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_must_eat;
	long long		start_time;

	// Read(philos) & Write(monitor)
	int				is_end;

	// Read(philos) & Write(philos) => need mutex
	int				*forks;

	// philo vs philo vs monitor
	pthread_mutex_t	m_print;

	// philo vs philo
	pthread_mutex_t	*m_forks;
}	t_info;

typedef struct s_philo
{
	// Read only(philo, monitor)
	int				id;
	pthread_t		philo;

	// Read(monitor) & Write(philo)
	int				number_of_eat;
	long long		time_of_last_eat;

	struct s_info	*info;
}	t_philo;

typedef struct s_monitor
{
	struct s_info	*info;
	struct s_philo	*philos;
}	t_monitor;

#endif
