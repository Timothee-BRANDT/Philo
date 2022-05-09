/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrandt <tbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 13:16:44 by tbrandt           #+#    #+#             */
/*   Updated: 2022/05/09 15:35:50 by tbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char *argv[])
{
    t_philo *philo;
    
    if (argc == 5 || argc == 6)
    {
        init_params(argc, argv, &philo);
        printf("nb of philo :%d\n", philo->params.nb_philo);
        printf("time to die :%d\n", philo->params.time_to_die);
        printf("time to eat :%d\n", philo->params.time_to_eat);
        printf("nb of eat :%d\n", philo->params.nb_eat);
        printf("time to sleep :%d\n", philo->params.time_to_sleep);
    }
    else
        printf("Invalid numver of arguments.\n");
}