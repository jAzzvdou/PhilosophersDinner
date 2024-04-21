#include "philo.h"

t_philo	*new_philo(t_info *info, t_mutexes *mutexes, int tid, int color)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	philo->tid = tid;

void	add_on_table(t_philo **philo, t_philo *new_philo)
{
	if (!new_philo)
		return ;
	if (!*philo)
		*philo = new_philo;
	else
		last_philo(*philo)->next = new_philo;
}
