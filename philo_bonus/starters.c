#include "philo_bonus.h"

int	start_philo(t_philo *philo, char **argv)
{
	philo->philos = my_atol(argv[1]);
	philo->colors = get_colors(philo->philos);
	philo->to_die = my_atol(argv[2]);
	philo->to_eat = my_atol(argv[3]);
	philo->to_sleep = my_atol(argv[4]);
	if (argv[5])
		philo->must_eat = my_atol(argv[5]);
	else
		philo->must_eat = -1;
	if (!philo->philos || philo->philos > 200
		|| philo->to_die < 60 || philo->to_eat < 60
		|| philo->to_sleep < 60 || !philo->must_eat)
		return (free(philo->colors), error_start());
	philo->tid = 1;
	return (1);
}

void	start_semaphores(t_philo *philo)
{
	int	p;

	p = philo->philos;
	sem_unlink("/sem_forks");
	sem_unlink("/sem_print");
	philo->sem_forks = sem_open("/sem_forks", O_CREAT | O_RDWR, 0777, p);
	philo->sem_print = sem_open("/sem_print", O_CREAT | O_RDWR, 0777, 1);
}

void	close_semaphores(t_philo *philo)
{
	sem_close(philo->sem_forks);
	sem_close(philo->sem_print);
	sem_unlink("/sem_forks");
	sem_unlink("/sem_print");
}

int	can_exit(int philos)
{
	int	i;
	int	status;

	i = 0;
	while (i < philos)
	{
		waitpid(0, &status, 0);
		if (WEXITSTATUS(status) == 1)
			return (1);
		i++;
	}
	return (0);
}

int	start_processes(t_philo *philo)
{
	int	killing;
	int	*pid;

	pid = malloc(sizeof(int) * philo->philos);
	while (philo->tid <= philo->philos)
	{
		pid[philo->tid - 1] = fork();
		if (pid[philo->tid - 1] == 0)
		{
			free(pid);
			philo->color = philo->colors[philo->tid - 1];
			return (routine(philo));
		}
		philo->tid++;
	}
	killing = philo->philos;
	if (can_exit(philo->philos))
	{
		while (killing--)
			kill(pid[killing], SIGKILL);
	}
	free(pid);
	free(philo->colors);
	return (1);
}
