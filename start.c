/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrandt <tbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 13:19:31 by tbrandt           #+#    #+#             */
/*   Updated: 2022/09/05 19:21:11 by tbrandt          ###   ########.fr       */
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
	}
	return (NULL);
}

void	init_philo(t_philo *philo, t_param param)
{
	int	i;

	i = 0;
	while(i < param.nb_philo)
	{
		philo[i].number = i;
		philo[i].left_fork = i;
		philo[i].right_fork = (i + 1) % param.nb_philo;
		philo[i].alive = 1;
		philo[i].param = &param;
		i++;
	}
}

int	init_mutex_and_threads(t_philo *philo, t_param param)
{
	int	i;

	init_philo(philo, param);
	i = -1;
	while (++i < param.nb_philo)
		philo[i].fork = malloc(sizeof(pthread_mutex_t));
	i = -1;
	while (++i < param.nb_philo)
		pthread_mutex_init(philo[i].fork, NULL);
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
