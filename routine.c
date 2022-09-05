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

void take_fork(t_philo *philo)
{
	if (philo->param->nb_philo % 2) // philo->number?
	{
		pthread_mutex_lock(&philo->fork[philo->right_fork]);
		pthread_mutex_lock(&philo->fork[philo->left_fork]);
		print_status(philo, FORK);
	}
	else
	{
		pthread_mutex_lock(&philo->fork[philo->left_fork]);
		pthread_mutex_lock(&philo->fork[philo->right_fork]);
		print_status(philo, FORK);
	}
	print_status(philo, FORK);
}

void	fork_back(t_philo *philo)
{
	pthread_mutex_unlock(&philo->fork[philo->left_fork]);
	pthread_mutex_unlock(&philo->fork[philo->right_fork]);
}

void    eat(t_philo *philo)
{
	philo->last_eat = get_time();
	print_status(philo, EAT);
	mysleep(philo->param->time_to_eat);
}

void	feeling_sleepy(t_philo *philo)
{
	print_status(philo, SLEEP);
	mysleep(philo->param->time_to_sleep);
}

void    mysleep(long int ms)
{
    long int    time;
    time = get_time();
    while ((get_time() - time) < ms)
        usleep(ms);
    usleep(1);
}