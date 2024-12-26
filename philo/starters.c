#include "philo.h"

int	start_infos(t_infos *infos, char **argv)
{
	infos->philos = my_atol(argv[1]);
	infos->colors = -((infos->philos) / 2);
	infos->to_die = my_atol(argv[2]);
	infos->to_eat = my_atol(argv[3]);
	infos->to_sleep = my_atol(argv[4]);
	if (argv[5])
		infos->must_eat = my_atol(argv[5]);
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
	pthread_t	watcher;

	philo = start_philos(infos, mutexes);
	philos = malloc(sizeof(pthread_t) * infos->philos);
	pthread_create(&watcher, NULL, &death_watcher, (void *)philo);
	pthread_detach(watcher);
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
	cleaner(philo, mutexes);
	return (1);
}
