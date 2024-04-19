/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:41:25 by jazevedo          #+#    #+#             */
/*   Updated: 2024/04/19 19:32:43 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	make_color(int c, int min, int max)
{
	int		red;
	int		green;
	int		blue;
	float	calc;

	if (c == 0)
		return (0x00FF00);
	else if (c > 0 && c <= max)
	{
		calc = (float)c / max;
		red = 255 * calc;
		green = 255 - red;
		blue = 0;
		return ((red << 16) | (green << 8) | blue);
	}
	else if (c < 0 && c >= min)
	{
		calc = (float)c / min;
		blue = 255 * calc;
		green = 255 - blue;
		red = 0;
		return ((red << 16) | (green << 8) | blue);
	}
	else
		return (0x000000);
}

void	*print_thread(void *thread)
{
	int		color;
	t_philo	*philo;

	philo = (t_philo *)thread;
	pthread_mutex_lock(&(philo->mutex));
	color = make_color(philo->color, -((philo->nb_philo) / 2),
			(philo->nb_philo / 2));
	printf("\033[38;2;%d;%d;%dm", (color >> 16) & 0xFF,
		(color >> 8) & 0xFF, color & 0xFF);
	printf("Você criou a Thread [%d]!\n", philo->tid);
	philo->tid++;
	philo->color++;
	pthread_mutex_unlock(&(philo->mutex));
	pthread_exit(NULL);
}

int	start_philo(t_philo *philo, char **argv)
{
	philo->nb_philo = ft_atol(argv[1]);
	philo->color = -((philo->nb_philo) / 2);
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
	long i = -1;
	while (++i < philo.nb_philo)
		pthread_create(&thread[i], NULL, print_thread, (void *)&philo);
	i = -1;
	while (++i < philo.nb_philo)
		pthread_join(thread[i], NULL);
	pthread_mutex_destroy(&(philo.mutex)); // DESTRUIR MUTEX
	return (0);
}
