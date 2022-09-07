/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrandt <tbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 14:41:13 by tbrandt           #+#    #+#             */
/*   Updated: 2022/09/07 17:27:50 by tbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_status(t_philo *philo, int code)
{
	long	init_time;
	long	actual_time;

	init_time = philo->param->init_time;
	actual_time = get_time() - init_time;
	pthread_mutex_lock(&philo->mutex->status);
	if (philo->param->alive)
	{
		if (code == FORK)
			printf("%ld %d has taken a fork\n", actual_time, philo->number);
		if (code == EAT)
			printf("%ld %d is eating\n", actual_time, philo->number);
		if (code == SLEEP)
			printf("%ld %d is sleeping\n", actual_time, philo->number);
		if (code == THINK)
			printf("%ld %d is thinking\n", actual_time, philo->number);
		if (code == DIE)
			printf("%ld %d died\n", actual_time, philo->number);
	}
	pthread_mutex_unlock(&philo->mutex->status);
	return (0);
}
