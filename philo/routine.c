/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:05:06 by jazevedo          #+#    #+#             */
/*   Updated: 2024/05/09 14:39:38 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	milisecond(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

int	waiting(t_philo *philo, long timer)
{
	long	final;

	final = milisecond() + timer;
	while (final > milisecond())
	{
		if (is_dead(philo))
			return (0);
		usleep(500);
	}
	return (1);
}

void	print_action(t_philo *philo, char *message)
{
	if (is_dead(philo) || philo->philo_stop)
		return ;
	pthread_mutex_lock(&philo->mutexes->mutex_print);
	printf(PHILO_ACTION,
		(philo->color >> 16) & 0xFF,
		(philo->color >> 8) & 0xFF,
		philo->color & 0xFF, philo->tid, message,
		milisecond() - philo->start);
	pthread_mutex_unlock(&philo->mutexes->mutex_print);
}

int	is_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutexes->mutex_stop);
	if (philo->mutexes->stop)
		return (pthread_mutex_unlock(&philo->mutexes->mutex_stop), 1);
	if (philo->death <= milisecond())
	{
		philo->philo_died = 1;
		return (pthread_mutex_unlock(&philo->mutexes->mutex_stop), 1);
	}
	return (pthread_mutex_unlock(&philo->mutexes->mutex_stop), 0);
}

void	*death_watcher(void *watching)
{
	t_philo	*watcher;
	t_philo	*philo;

	philo = watching;
	watcher = watching;
	while (1)
	{
		if (watcher->philo_died)
		{
			watcher->mutexes->stop = 1;
			pthread_mutex_lock(&watcher->mutexes->mutex_print);
			printf(PHILO_ACTION,
				102, 102, 102, philo->tid, "died",
				milisecond() - philo->start);
			pthread_mutex_unlock(&watcher->mutexes->mutex_print);
			break ;
		}
		if (watcher->philo_ate == philo->infos.must_eat)
			philo->philo_stop = 1;
		//usleep(100);
		philo = philo->next;
		watcher = philo;
	}
	return (NULL);
}

void	*routine(void *thread)
{
	t_philo	*philo;

	philo = (t_philo *)thread;
	philo->start = milisecond();
	philo->death = philo->start + philo->infos.to_die;
	if (philo->tid % 2 == 0)
		usleep(100);
	while (1)
	{
		print_action(philo, "is thinking..");
		if (!eat_pls(philo))
			break ;
		return_forks(philo);
		if (!have_eaten(philo))
			break ;
		if (!sleep_pls(philo))
			break ;
	}
	return (NULL);
}
