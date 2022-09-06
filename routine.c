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
	if (philo->number % 2)
	{
		pthread_mutex_lock(&philo->mutex->fork[philo->left_fork]);
		print_status(philo, FORK);
		pthread_mutex_lock(&philo->mutex->fork[philo->right_fork]);
	}
	else
	{
		pthread_mutex_lock(&philo->mutex->fork[philo->right_fork]);
		print_status(philo, FORK);
		pthread_mutex_lock(&philo->mutex->fork[philo->left_fork]);
	}
	print_status(philo, FORK);
}

void	fork_back(t_philo *philo)
{
	pthread_mutex_unlock(&philo->mutex->fork[philo->left_fork]);
	pthread_mutex_unlock(&philo->mutex->fork[philo->right_fork]);
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

void    mysleep(long	ms)
{
    long	time;
    time = get_time();
    while ((get_time() - time) < ms)
        usleep(500);
}