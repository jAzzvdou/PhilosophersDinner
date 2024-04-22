/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:04:24 by jazevedo          #+#    #+#             */
/*   Updated: 2024/04/22 14:43:31 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*last_philo(t_philo *philo)
{
	if (!philo)
		return (NULL);
	while (philo->next)
		philo = philo_next;
	return (philo);
}

t_philo	*new_philo(t_info *info, t_mutexes *mutexes, int tid, int color)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	philo->tid = tid;
	philo->color = color;
	philo->fork = 1;
	philo->start = 0;
	philo->death = 0;
	philo->infos = *infos;
	philo->mutexes = mutexes;
	pthread_mutex_init(&mutexes->mutex_fork, NULL);
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
