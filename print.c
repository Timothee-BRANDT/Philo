/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrandt <tbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 14:41:13 by tbrandt           #+#    #+#             */
/*   Updated: 2022/08/29 16:14:58 by tbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_status(t_philo *philo, int code)
{
	//while(philo->alive)
	//{
		pthread_mutex_lock(&philo->status);
		if (code == FORK)
			printf("%ld %d has taken a fork\n", get_time(), philo->number);
		if (code == EAT)
			printf("%ld %d is eating\n", get_time(), philo->number);
		if (code == SLEEP)
			printf("%ld %d is sleeping\n", get_time(), philo->number);
		if (code == THINK)
			printf("%ld %d is thinking\n", get_time(), philo->number);
		pthread_mutex_unlock(&philo->status);
//	}
	return (0);
}
