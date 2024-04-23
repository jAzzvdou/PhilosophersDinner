/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:05:06 by jazevedo          #+#    #+#             */
/*   Updated: 2024/04/23 12:05:17 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	milisecond(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	print_action(t_philo *philo, char *message)
{
	if (is_dead(philo))
		return ;
	pthread_mutex_lock(&philo->mutexes->mutex_print);
	printf("\033[38;2;%d;%d;%dmPhilosopher[%d] %s. TIME: %ld.\n",
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
		philo->mutexes->stop = 1;
		pthread_mutex_lock(&philo->mutexes->mutex_print);
		printf("\033[38;2;%d;%d;%dmPhilosopher[%d] dead. TIME: %ld.\n",
			128, 128, 128,
			philo->tid, milisecond() - philo->start);
		pthread_mutex_unlock(&philo->mutexes->mutex_print);
		return (pthread_mutex_unlock(&philo->mutexes->mutex_stop), 1);
	}
	return (pthread_mutex_unlock(&philo->mutexes->mutex_stop), 0);
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
			return (NULL);
		return_forks(philo);
		if (!have_eaten(philo)) // FAZER.
			return (NULL);
		if (!sleep_pls(philo)) // FAZER.
			return (NULL);
	}
	return (NULL);
}
