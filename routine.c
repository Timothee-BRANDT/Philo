/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrandt <tbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 10:08:53 by tbrandt           #+#    #+#             */
/*   Updated: 2022/09/05 17:07:41by tbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	death_handler(t_philo *philo)
{
	print_status(philo, DIE);
	philo->param->alive = 0;
}

void	*checker(void *args)
{
	t_philo *philo;

	philo = (t_philo *)(args);
	while (philo->param->alive)
	{
		if (get_time() > philo->last_eat + philo->param->time_to_die)
			death_handler(philo);
	}
	return (NULL);
}

void	*routine(void *args)
{
	t_philo *philo;
	pthread_t check;

	philo = (t_philo *)(args);
	philo->last_eat = get_time();
	pthread_create(&check, NULL, &checker, philo);
	while(philo->param->alive)
	{
		take_fork(philo);
		eat(philo);
		//if (get_time() > philo->last_eat + philo->param->time_to_die)
		//	printf("I AM DEAD");
		fork_back(philo);
		feeling_sleepy(philo);
		thinking(philo);
	}
	pthread_join(check, NULL);
	return (NULL);
}

void    mysleep(long	ms)
{
    long	time;
    time = get_time();
    while ((get_time() - time) < ms)
        usleep(500);
	usleep(1);
}