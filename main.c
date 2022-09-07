/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrandt <tbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 13:16:44 by tbrandt           #+#    #+#             */
/*   Updated: 2022/09/07 17:31:33 by tbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_philo	*philo;
	t_param	param;
	t_mutex	mutex;

	if (argc == 5 || argc == 6)
	{
		if (init_params(argc, argv, &param))
			return (on_error("Bad arguments.\n", 1));
		philo = malloc(sizeof(t_philo) * param.nb_philo);
		init_philo(philo, &param, &mutex);
		if (init_mutex(philo, &mutex))
			return (on_error("Mutex initialisation failed\n", 2));
		if (init_threads(philo, param))
			return (on_error("Threads initialisaiton failed.\n", 3));
	}
	else
		printf("Invalid number of arguments.\n");
	return (0);
}
