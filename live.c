/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrandt <tbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:40:17 by tbrandt           #+#    #+#             */
/*   Updated: 2022/09/07 17:24:56 by tbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex->fork[philo->left_fork]);
	print_status(philo, FORK);
	pthread_mutex_lock(&philo->mutex->fork[philo->right_fork]);
	print_status(philo, FORK);
}

void	eat(t_philo *philo)
{
	philo->last_eat = get_time();
	print_status(philo, EAT);
	pthread_mutex_lock(&philo->mutex->status);
	philo->eat_count++;
	pthread_mutex_unlock(&philo->mutex->status);
	mysleep(philo->param->time_to_eat);
}

void	fork_back(t_philo *philo)
{
	pthread_mutex_unlock(&philo->mutex->fork[philo->left_fork]);
	pthread_mutex_unlock(&philo->mutex->fork[philo->right_fork]);
}

void	feeling_sleepy(t_philo *philo)
{
	print_status(philo, SLEEP);
	mysleep(philo->param->time_to_sleep);
}

void	thinking(t_philo *philo)
{
	print_status(philo, THINK);
}
