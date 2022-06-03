/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrandt <tbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 14:41:13 by tbrandt           #+#    #+#             */
/*   Updated: 2022/06/03 17:25:08 by tbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_status(t_philo *philo, int code)
{
	pthread_mutex_lock(&philo->status);
	if (code == 0)
		printf("%ld %d has taken a fork\n", get_time(), philo->param->nb_philo);
	if (code == 1)
		printf("%ld %d is eating\n", get_time(), philo->param->nb_philo);
	if (code == 2)
		printf("%ld %d is sleeping\n", get_time(), philo->param->nb_philo);
	if (code == 3)
		printf("%ld %d is thinking\n", get_time(), philo->param->nb_philo);
	pthread_mutex_unlock(&philo->status);
	return (0);
}