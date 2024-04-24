/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:02:30 by jazevedo          #+#    #+#             */
/*   Updated: 2024/04/23 23:48:16 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	single_fork(t_philo *philo, t_philo *fork, char *message)
{
	pthread_mutex_lock(&fork->mutex_fork);
	if (fork->fork)
	{
		fork->fork--;
		pthread_mutex_unlock(&fork->mutex_fork);
		return (print_action(philo, message), 1);
	}
	return (pthread_mutex_unlock(&fork->mutex_fork), 0);
}

int	take_forks(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		if (is_dead(philo))
			return (0);
		i += single_fork(philo, philo, "has taken the fork 1");
		if (is_dead(philo))
			return (0);
		i += single_fork(philo, philo->next, "has taken the fork 2");
	}
	return (1);
}

int	eat_pls(t_philo *philo)
{
	if (!take_forks(philo))
		return (0);
	print_action(philo, "is eating..");
	philo->death = milisecond() + philo->infos.to_die;
	philo->eaten++;
	return (waiting(philo, philo->infos.to_eat));
}

void	return_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex_fork);
	philo->fork++;
	pthread_mutex_unlock(&philo->mutex_fork);
	pthread_mutex_lock(&philo->next->mutex_fork);
	philo->next->fork++;
	pthread_mutex_unlock(&philo->next->mutex_fork);
}

int	have_eaten(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutexes->mutex_eaten);
	if (philo->eaten == philo->infos.must_eat)
	{
		philo->mutexes->eaten--;
		if (!philo->mutexes->eaten)
		{
			pthread_mutex_unlock(&philo->mutexes->mutex_eaten);
			pthread_mutex_lock(&philo->mutexes->mutex_stop);
			philo->mutexes->stop++;
			pthread_mutex_unlock(&philo->mutexes->mutex_stop);
		}
		else
			pthread_mutex_unlock(&philo->mutexes->mutex_eaten);
		return (0);
	}
	pthread_mutex_unlock(&philo->mutexes->mutex_eaten);
	return (1);
}
