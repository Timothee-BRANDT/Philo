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
    int nb_eat;
    int nb_ph_feed;
}       t_param;

typedef struct s_mutex{
    pthread_mutex_t fork;
}       t_mutex;

typedef struct s_philo{
    int number;
    int left_fork;
    int right_fork;
    pthread_t thread;
    t_param params;
    t_mutex mutex;
}       t_philo;

int     ft_is_numeric(char c);
int     ft_atoi(const char *str);
int     init_params(int argc, char **argv, t_philo **philo);
int     check_num_param(char **argv);
int     check_positive_param(t_philo **philo);
void    init_threads(t_philo **philo);
void    init_mutex(t_philo **philo);
#endif