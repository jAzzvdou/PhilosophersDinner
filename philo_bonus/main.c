/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 21:11:59 by jazevedo          #+#    #+#             */
/*   Updated: 2024/04/30 09:30:41 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char **argv)
{
	t_philo	philo;

	philo = (t_philo){0};
	if (invalid_arguments(argc, argv))
		return (1);
	if (!start_philo(&philo, argv))
		return (1);
	start_semaphores(&philo);
	if (!start_processes(&philo))
		return (1);
	close_semaphores(&philo);
	return (0);
}
