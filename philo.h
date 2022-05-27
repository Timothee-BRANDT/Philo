/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrandt <tbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 15:08:20 by tbrandt           #+#    #+#             */
/*   Updated: 2022/05/27 11:51:03 by tbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h> // printf allowed
# include <stdlib.h> // malloc allowed
# include <unistd.h> // write allowed
# include <pthread.h>
# include <sys/time.h>

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
	int				fork;
	int				nb_eat;
	int				alive;
	long			time_start;
	pthread_mutex_t	mutex;
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
void	*routine(void *args);
long	get_time(void);

#endif
