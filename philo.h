/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrandt <tbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 15:08:20 by tbrandt           #+#    #+#             */
/*   Updated: 2022/09/07 17:25:39 by tbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h> // printf allowed
# include <stdlib.h> // malloc allowed
# include <unistd.h> // write allowed
# include <pthread.h>
# include <sys/time.h>

# define FORK 0
# define EAT 1
# define THINK 2
# define SLEEP 3
# define DIE 4

typedef struct s_mutex{
	pthread_mutex_t	status;
	pthread_mutex_t	*fork;
}		t_mutex;

typedef struct s_param{
	int		nb_philo;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		nb_eat_by_ph;
	int		nb_ph_feed;
	int		alive;
	long	init_time;
}		t_param;

typedef struct s_philo{
	int				number;
	int				left_fork;
	int				right_fork;
	int				eat_count;
	long			time_start;
	long			last_eat;
	t_param			*param;
	t_mutex			*mutex;
	pthread_t		thread;
}		t_philo;

int		ft_is_numeric(char c);
int		ft_atoi(const char *str);
int		init_params(int argc, char **argv, t_param *param);
int		check_num_param(char **argv);
int		check_positive_param(t_param *param);
int		init_threads(t_philo *philo, t_param param);
int		init_mutex(t_philo *philo, t_mutex *mutex);
void	init_philo(t_philo *philo, t_param *param, t_mutex *mutex);
int		print_status(t_philo *philo, int code);
int		on_error(char *str, int code);
void	take_fork(t_philo *philo);
void	eat(t_philo *philo);
void	fork_back(t_philo *philo);
void	feeling_sleepy(t_philo *philo);
void	thinking(t_philo *philo);
void	death_handler(t_philo *philo);
void	mysleep(long int ms);
void	*routine(void *args);
long	get_time(void);

#endif
