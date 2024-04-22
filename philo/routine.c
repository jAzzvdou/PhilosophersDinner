/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:05:06 by jazevedo          #+#    #+#             */
/*   Updated: 2024/04/22 17:33:47 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *philo)
{
	t_philo	*philo;

	philo = (t_philo *)philo;
	philo->start = ;
	philo->death = philo->start + philo->info.to_die;
	if (philo->tid % 2 == 0)
		//Waiting...
	while (1)
	{
		//reckon
		//eat
		//sleep
	}
}

