/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrandt <tbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 14:41:13 by tbrandt           #+#    #+#             */
/*   Updated: 2022/05/27 11:51:08 by tbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_status(t_philo *philo, int code)
{
	pthread_mutex_t status;

	pthread_mutex_lock(&status);
	if (code == 0)
		printf("%ld %d has taken a fork\n", get_time(), philo->number);
	if (code == 1)
		printf("%ld %d is eating\n", get_time(), philo->number);
	if (code == 2)
		printf("%ld %d is sleeping\n", get_time(), philo->number);
	if (code == 3)
		printf("%ld %d is thinking\n", get_time(), philo->number);
	pthread_mutex_unlock(&status);
	return (0);
}