#include "philo.h"

int	sleep_pls(t_philo *philo)
{
	print_action(philo, "is sleeping..");
	return (waiting(philo, philo->infos.to_sleep));
}
