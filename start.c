/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrandt <tbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 13:19:31 by tbrandt           #+#    #+#             */
/*   Updated: 2022/05/23 11:4 by tbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_params(int argc, char **argv, t_param *param)
{
	if (check_num_param(argv))
		return (1);
	param->nb_philo = ft_atoi(argv[1]);
	param->time_to_die = ft_atoi(argv[2]);
	param->time_to_eat = ft_atoi(argv[3]);
	param->time_to_sleep = ft_atoi(argv[4]);
	param->nb_eat_by_ph = -1;
	if (check_positive_param(param))
		return (1);
	if (argc == 6)
		param->nb_eat_by_ph = ft_atoi(argv[5]);
	return (0);
}

void	*routine(void *args)
{
	t_philo	*cast;

	cast = (t_philo *)args;
	pthread_mutex_lock(&cast->mutex);
	printf("i'm a thread\n");
	pthread_mutex_unlock(&cast->mutex);
	return (NULL);
}

int	init_mutex_and_threads(t_philo *philo, t_param param)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (++i < param.nb_philo + 1)
	{
		philo[j].number = i;
		j++;
	}
	i = -1;
	while (++i < param.nb_philo)
		pthread_mutex_init(&philo[i].mutex, NULL);
	i = -1;
	while (++i < param.nb_philo)
	{
		if (pthread_create(&philo[i].thread, NULL, &routine, philo) != 0)
			return (1);
	}
	i = -1;
	while (++i < param.nb_philo)
	{
		if (pthread_detach(philo[i].thread) != 0)
			return (2);
	}
	return (0);
}