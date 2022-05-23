/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrandt <tbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 13:16:44 by tbrandt           #+#    #+#             */
/*   Updated: 2022/05/23 12:36:58 by tbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char *argv[])
{
    t_philo *philo;
    t_param param;
    
    if (argc == 5 || argc == 6)
    {
        if (init_params(argc, argv, &param))
            return (1);
        printf("nb of philo :%d\n", param.nb_philo);
        printf("time to die :%d\n", param.time_to_die);
        printf("time to eat :%d\n", param.time_to_eat);
        printf("time to sleep :%d\n", param.time_to_sleep);
        printf("nb of eat :%d\n", param.nb_eat_by_ph);
        philo = NULL;
        init_threads(philo, param);
    }
    else
        printf("Invalid numver of arguments.\n");
}
