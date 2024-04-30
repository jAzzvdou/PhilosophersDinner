/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 21:11:59 by jazevedo          #+#    #+#             */
/*   Updated: 2024/04/29 22:30:02 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*is_dead(void *thread)
{
	t_philo	*philo;

	philo = (t_philo *)thread;
	while (1)
	{
		pthread_mutex_lock(&philo->mutex_death);
		if (philo->death <= milisecond())
		{
			pthread_mutex_unlock(&philo->mutex_death);
			sem_wait(philo->sem_print);
			printf("\033[38;2;%d;%d;%dmPhilosopher[%d] dead.
				TIME: %ld.\n",
                        	102, 102, 102,
                        	philo->tid, milisecond() - philo->start);
			exit(1);
		}
		usleep(100);
	}
	return (NULL);
}

void	print_action(t_philo *philo, char *message)
{
	sem_wait(philo->sem_print);
	printf("\033[38;2;%d;%d;%dmPhilosopher[%d] %s. TIME: %ld.\n",
                (philo->color >> 16) & 0xFF,
                (philo->color >> 8) & 0xFF,
                philo->color & 0xFF, philo->tid, message,
                milisecond() - philo->start);
	sem_post(philo->sem_print);
}

void	eat_pls(t_philo *philo)
{
	sem_wait(philo->sem_forks);
	print_action(philo, "has taken the fork 1");
	sem_wait(philo->sem_forks);
	print_action(philo, "has taken the fork 2");
	print_action(philo, "is eating..");
	pthread_mutex_lock(&philo->mutex_death);
	philo->death = milisecond() + philo->to_die;
	pthread_mutex_unlock(&philo->mutex_death);
	philo->eaten++;
	usleep(philo->to_eat * 1000);
	sem_post(philo->sem_forks);
	sem_post(philo->sem_forks);
}

int	routine(t_philo *philo)
{
	pthread_t	unknown;

	pthread_mutex_init(&philo->mutex_death, NULL);
	philo->start = milisecond();
	philo->death = philo->start + philo->to_die;
	pthread_create(&unknown, NULL, &is_death, (void *)philo);
	pthread_detach(unknown);
	if (philo->tid % 2 == 0)
		usleep(100);
	while (1)
	{
		print_action(philo, "is thinking..");
		eat_pls(philo);
		if (philo->eat == philo->must_eat)
			return (0);
		print_action(philo, "is sleeping..");
		usleep(philo->to_sleep * 1000);
	}
	return (1);
}

int     main(int argc, char **argv)
{
        t_philo         philo;

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
