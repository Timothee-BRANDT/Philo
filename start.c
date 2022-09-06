/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrandt <tbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 13:19:31 by tbrandt           #+#    #+#             */
/*   Updated: 2022/09/06 15:39:53 by tbrandt          ###   ########.fr       */
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
	t_philo *philo;

	philo = (t_philo *)(args);
	while(philo->alive)
	{
		take_fork(philo);
		eat(philo);
		fork_back(philo);
		feeling_sleepy(philo);
		thinking(philo);
	}
	return (NULL);
}

void	init_philo(t_philo *philo, t_param *param, t_mutex *mutex)
{
	int	i;

	i = 0;
	while(i < param->nb_philo)
	{
		philo[i].number = i;
		philo[i].left_fork = (i + 1) % param->nb_philo;
		philo[i].right_fork = i;
		philo[i].alive = 1;
		philo[i].param = param;
		philo[i].mutex = mutex;
		i++;
	}
}

int	init_mutex(t_philo *philo, t_mutex *mutex)
{
	int	i;
	
	pthread_mutex_init(&mutex->status, NULL);
	mutex->fork	= malloc(sizeof(pthread_mutex_t) * philo->param->nb_philo);
	if (!mutex->fork)
		return (1);
	i = 0;
	while(i < philo->param->nb_philo)
	{
		pthread_mutex_init(&mutex->fork[i], NULL);
		i++;
	}
	return (0);
}

int	init_threads(t_philo *philo, t_param param)
{
	int	i;

	philo->param->init_time = get_time();
	i = 0;
	while (i < param.nb_philo)
	{
		if (pthread_create(&philo[i].thread, NULL, &routine, &philo[i]) != 0)
			return (1);
		i = i + 2;
	}
	usleep(100);
	i = 1;
	while (i < param.nb_philo)
	{
		if (pthread_create(&philo[i].thread, NULL, &routine, &philo[i]) != 0)
			return (1);
		i = i + 2;
	}
	i = -1;
	while (++i < param.nb_philo)
	{
		if (pthread_join(philo[i].thread, NULL) != 0)
			return (2);
	}
	return (0);
}
