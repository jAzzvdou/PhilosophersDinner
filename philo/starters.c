/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starters.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:04:29 by jazevedo          #+#    #+#             */
/*   Updated: 2024/04/22 18:00:18 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	start_infos(t_infos *infos, char **argv)
{
	infos->philos = ft_atol(argv[1]);
	infos->colors = -((infos->philos) / 2);
	infos->to_die = ft_atol(argv[2]);
	infos->to_eat = ft_atol(argv[3]);
	infos->to_sleep = ft_atol(argv[4]);
	if (argv[5])
		infos->must_eat = ft_atol(argv[5]);
	else
		infos->must_eat = -1;
	if (!infos->philos || infos->philos > 200
		|| infos->to_die < 60 || infos->to_eat < 60
		|| infos->to_sleep < 60 || !infos->must_eat)
		return (error_start());
	return (1);
}

void	start_mutexes(t_infos *infos, t_mutexes *mutexes)
{
	mutexes->eaten = infos->philos;
	pthread_mutex_init(&mutexes->mutex_stop, NULL);
	pthread_mutex_init(&mutexes->mutex_eaten, NULL);
	pthread_mutex_init(&mutexes->mutex_print, NULL);
}

t_philo	*start_philos(t_infos *infos, t_mutexes *mutexes)
{
	int		i;
	t_philo	*philo;

	philo = NULL;
	i = -1;
	while (++i < infos->philos)
		add_on_table(&philo, new_philo(infos, mutexes, i + 1));
	last_philo(philo)->next = philo;
	return (philo);
}

int	start_threads(t_infos *infos, t_mutexes *mutexes)
{
	int			i;
	t_philo		*philo;
	pthread_t	*philos;

	philo = start_philos(infos, mutexes);
	philos = malloc(sizeof(pthread_t) * infos->philos);
	if (!philos)
		return (0);
	i = -1;
	while (++i < infos->philos)
	{
		pthread_create(&philos[i], NULL, &routine, (void *)philo);
		philo = philo->next;
	}
	i = -1;
	while (++i < infos->philos)
		pthread_join(philos[i], NULL);
	free(philos);
	//cleaner(mutexes, philo);
	return (1);
}
