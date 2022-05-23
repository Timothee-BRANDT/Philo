#ifndef PHILO_H
# define PHILO_H

# include <stdio.h> // printf allowed
# include <stdlib.h> // malloc allowed
# include <unistd.h> // write allowed
# include <pthread.h>
#include <sys/time.h>

typedef struct s_param{
    int nb_philo;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int nb_eat_by_ph;
    int nb_ph_feed;
}       t_param;

typedef struct s_philo{
    int number;
    int left_fork;
    int right_fork;
	int	nb_eat;
    pthread_t thread;
    pthread_mutex_t mutex;
}       t_philo;

int     ft_is_numeric(char c);
int     ft_atoi(const char *str);
int     init_params(int argc, char **argv, t_param *param);
int     check_num_param(char **argv);
int     check_positive_param(t_param *param);
void    *routine();
int     init_threads(t_philo *philo, t_param param);

#endif
