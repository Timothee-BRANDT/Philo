/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrandt <tbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:25:04 by tbrandt           #+#    #+#             */
/*   Updated: 2022/05/24 15:07:48 by tbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_num_param(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_is_numeric(argv[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_positive_param(t_param *param)
{
	if (param->nb_philo < 1)
		return (1);
	if (param->time_to_die <= 0)
		return (1);
	if (param->time_to_eat <= 0)
		return (1);
	if (param->time_to_sleep <= 0)
		return (1);
	return (0);
}
