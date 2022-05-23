/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrandt <tbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 13:19:31 by tbrandt           #+#    #+#             */
/*   Updated: 2022/05/23 11:4 by tbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int    init_params(int argc, char **argv, t_param *param)
{
    if (check_num_param(argv))
        return (1);
    param->nb_philo = ft_atoi(argv[1]);
    param->time_to_die = ft_atoi(argv[2]);
    param->time_to_eat = ft_atoi(argv[3]);
    param->time_to_sleep = ft_atoi(argv[4]);
    param->nb_eat_by_ph = -1;
    if (argc == 6)
    {
        param->nb_eat_by_ph = ft_atoi(argv[5]);
    }
    if (check_positive_param(param))
        return (1);
    return (0);
}

void    *routine()
{
    printf("i'm a thread\n");
    return (NULL); 
}

int	init_threads(t_philo *philo, t_param param)
{
	int i;
    i = 0;
    philo = malloc(sizeof(t_philo) * param.nb_philo);
    while (i < param.nb_philo)
    {
        pthread_create(&philo[i].thread, NULL, &routine, NULL);
        pthread_mutex_init(&philo[i].mutex, NULL);
        pthread_join(philo[i].thread, NULL);
        i++;
    }
    return (0);
}
