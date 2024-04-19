/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:41:25 by jazevedo          #+#    #+#             */
/*   Updated: 2024/04/19 18:43:59 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*print_thread(void *thread)
{
	t_philo *philo;

	philo = (t_philo *)thread;
	pthread_mutex_lock(&(philo->mutex));
	paint(GREEN);
	printf("Você criou a Thread [%d]!\n", philo->tid);
	philo->tid++;
	pthread_mutex_unlock(&(philo->mutex));
	pthread_exit(NULL);
}

int	start_philo(t_philo *philo, char **argv)
{
	philo->nb_philo = ft_atol(argv[1]);
	philo->to_die = ft_atol(argv[2]);
	philo->to_eat = ft_atol(argv[3]);
	philo->to_sleep = ft_atol(argv[4]);
	if (argv[5])
		philo->must_eat = ft_atol(argv[5]);
	else
		philo->must_eat = -1;
	if (!philo->nb_philo || philo->nb_philo > 200
		|| philo->to_die < 60 || philo->to_eat < 60
		|| philo->to_sleep < 60 || !philo->must_eat)
		return (error_start());
	return (1);
}

int	main(int argc, char **argv)
{
	t_philo	philo;

	philo = (t_philo){0};
	if (invalid_arguments(argc, argv))
		return (1);
	if (!start_philo(&philo, argv))
		return (1);
	pthread_mutex_init(&philo.mutex, NULL); // INICIAR A MUTEX.
	pthread_t *thread = malloc(sizeof(pthread_t) * philo.nb_philo);
	long i = 0;
	while (i < philo.nb_philo)
	{
		pthread_create(&thread[i], NULL, print_thread, (void *)&philo);
		i++;
	}
	i = 0;
	while (i < philo.nb_philo)
	{
		pthread_join(thread[i], NULL);
		i++;
	}
	pthread_mutex_destroy(&(philo.mutex)); // DESTRUIR MUTEX
	return (0);
}
