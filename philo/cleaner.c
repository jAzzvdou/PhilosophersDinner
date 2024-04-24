/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:43:11 by jazevedo          #+#    #+#             */
/*   Updated: 2024/04/24 13:56:44 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	clear_philos(t_philo *philo)
{
	t_philo	*tmp;
	t_philo	*first;

	if (!philo)
		return ;
	first = philo;
	while (philo->next != first)
	{
		tmp = philo->next;
		pthread_mutex_destroy(&philo->mutex_fork);
		free(philo);
		philo = tmp;
	}
	pthread_mutex_destroy(&philo->mutex_fork);
	free(philo);
}

void	cleaner(t_philo *philo, t_mutexes *mutexes)
{
	pthread_mutex_destroy(&mutexes->mutex_stop);
	pthread_mutex_destroy(&mutexes->mutex_eaten);
	pthread_mutex_destroy(&mutexes->mutex_print);
	clear_philos(philo);
}
