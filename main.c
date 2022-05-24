/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrandt <tbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 13:16:44 by tbrandt           #+#    #+#             */
/*   Updated: 2022/05/24 15:06:41 by tbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_philo	*philo;
	t_param	param;

	if (argc == 5 || argc == 6)
	{
		if (init_params(argc, argv, &param))
			return (on_error("Bad arguments.\n", 1));
		philo = malloc(sizeof(t_philo) * param.nb_philo);
		if (init_mutex_and_threads(philo, param))
			return (on_error("Threads initialisaiton failed.\n", 2));
	}
	else
		printf("Invalid number of arguments.\n");
}
