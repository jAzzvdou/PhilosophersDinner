#include "philo_bonus.h"

int	main(int argc, char **argv)
{
	t_philo	philo;

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
