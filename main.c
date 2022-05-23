/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrandt <tbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 13:16:44 by tbrandt           #+#    #+#             */
/*   Updated: 2022/05/23 16:49:53 by tbrandt          ###   ########.fr       */
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
        philo = malloc(sizeof(t_philo) * param.nb_philo);
        init_mutex_and_threads(philo, param);
    }
    else
        printf("Invalid numver of arguments.\n");
}
