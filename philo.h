/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrandt <tbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 15:08:20 by tbrandt           #+#    #+#             */
/*   Updated: 2022/09/05 17:53:56 by tbrandt          ###   ########.fr       */
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

typedef struct s_param{
	int		nb_philo;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		nb_eat_by_ph;
	int		nb_ph_feed;
	long	init_time;
}		t_param;

typedef struct s_philo{
	int				number;
	int				left_fork;
	int				right_fork;
	int				eat_count;
	int				alive;
	long			time_start;
	long			last_eat;
	pthread_mutex_t	*fork;
	pthread_mutex_t	status;
	t_param			*param;
	pthread_t		thread;
}		t_philo;

int		ft_is_numeric(char c);
int		ft_atoi(const char *str);
int		init_params(int argc, char **argv, t_param *param);
int		check_num_param(char **argv);
int		check_positive_param(t_param *param);
int		init_mutex_and_threads(t_philo *philo, t_param param);
void	init_philo(t_philo *philo, t_param param);
int		print_status(t_philo *philo, int code);
int		on_error(char *str, int code);
void	take_fork(t_philo *philo);
void	fork_back(t_philo *philo);
void    mysleep(long int ms);
void	feeling_sleepy(t_philo *philo);
void	*routine(void *args);
long	get_time(void);
void	eat(t_philo *philo);

#endif
