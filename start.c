/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrandt <tbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 13:19:31 by tbrandt           #+#    #+#             */
/*   Updated: 2022/05/09 16:02:29 by tbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    init_params(int argc, char **argv, t_philo **philo)
{
    (*philo) = malloc(sizeof(t_philo));
    (*philo)->params.nb_philo = ft_atoi(argv[1]);
    (*philo)->params.time_to_die = ft_atoi(argv[2]);
    (*philo)->params.time_to_eat = ft_atoi(argv[3]);
    (*philo)->params.time_to_sleep = ft_atoi(argv[4]);
    if (argc == 6)
    {
        (*philo)->params.nb_eat = ft_atoi(argv[5]);
    }
}

void    init_mutex(t_philo **philo)
{
    pthread_mutex_init(&(*philo)->mutex.left_fork, NULL);
    pthread_mutex_init(&(*philo)->mutex.right_fork, NULL);
}