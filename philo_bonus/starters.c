/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starters.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 22:05:41 by jazevedo          #+#    #+#             */
/*   Updated: 2024/04/29 23:06:26 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int     start_philo(t_philo *philo, char **argv)
{
        philo->philos = ft_atol(argv[1]);
        philo->colors = -((philo->philos) / 2);
        philo->to_die = ft_atol(argv[2]);
        philo->to_eat = ft_atol(argv[3]);
        philo->to_sleep = ft_atol(argv[4]);
        if (argv[5])
                philo->must_eat = ft_atol(argv[5]);
        else
                philo->must_eat = -1;
        if (!philo->philos || philo->philos > 200
                || philo->to_die < 60 || philo->to_eat < 60
                || philo->to_sleep < 60 || !philo->must_eat)
                return (error_start());
        philo->tid = 1;
        return (1);
}

void    start_semaphores(t_philo *philo)
{
        int     p;

        p = philo->philos;
        sem_unlink("/sem_forks");
        sem_unlink("/sem_print");
        philos->sem_forks = sem_open("/sem_forks", O_CREAT | O_RDWR, 0777, p);
        philos->sem_print = sem_open("/sem_print", O_CREAT | O_RDWR, 0777, 1);
}

void    close_semaphores(t_philo *philo)
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
			return (0);
		i++;
	}
	return (1);
}

int     start_processes(t_philo *philo)
{
	int	kill;
        int     *pid;

        pid = malloc(sizeof(int) * philo->philos);
        if (!pid)
                return (0);
        while (philo->tid <= philo->philos)
        {
                pid[philo->tid - 1] = fork();
                if (pid[philo->tid - 1] == 0)
                {
                        free(pid);
                        routine(philo);
                }
                philo->tid++;
        }
	kill = philo->philos;
	if (can_exit(philo->philos))
	{
		while (kill--)
			kill(pid[kill], SIGTERM);
	}
	free(pid);
        return (1);
}
