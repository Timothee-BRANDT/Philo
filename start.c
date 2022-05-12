/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrandt <tbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 13:19:31 by tbrandt           #+#    #+#             */
/*   Updated: 2022/05/12 17:01:58 by tbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int    init_params(int argc, char **argv, t_philo **philo)
{
    if (check_num_param(argv))
        return (1);
    (*philo) = malloc(sizeof(t_philo) * 1);
    (*philo)->params.nb_philo = ft_atoi(argv[1]);
    (*philo)->params.time_to_die = ft_atoi(argv[2]);
    (*philo)->params.time_to_eat = ft_atoi(argv[3]);
    (*philo)->params.time_to_sleep = ft_atoi(argv[4]);
    (*philo)->params.nb_eat = -1;
    if (argc == 6)
    {
        (*philo)->params.nb_eat = ft_atoi(argv[5]);
    }
    if (check_positive_param(philo))
        return (1);
    return (0);
}

void    init_mutex(t_philo **philo)
{
    int i;

    i = 0;
    while(i < (*philo)->params.nb_philo)
    {
        pthread_mutex_init(&(*philo)->mutex.fork, NULL);
        i++;
    }
}