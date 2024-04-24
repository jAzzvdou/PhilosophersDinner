/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:04:24 by jazevedo          #+#    #+#             */
/*   Updated: 2024/04/24 14:03:24 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*last_philo(t_philo *philo)
{
	if (!philo)
		return (NULL);
	while (philo->next)
		philo = philo->next;
	return (philo);
}

t_philo	*new_philo(t_infos *infos, t_mutexes *mutexes, int tid)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	philo->tid = tid;
	philo->color = make_color(infos->colors, -(infos->philos / 2),
			(infos->philos / 2));
	infos->colors++;
	philo->fork = 1;
	philo->eaten = 0;
	philo->death = 0;
	philo->infos = *infos;
	philo->mutexes = mutexes;
	pthread_mutex_init(&philo->mutex_fork, NULL);
	philo->next = NULL;
	return (philo);
}

void	add_on_table(t_philo **philo, t_philo *new_philo)
{
	if (!new_philo)
		return ;
	if (!*philo)
		*philo = new_philo;
	else
		last_philo(*philo)->next = new_philo;
}
