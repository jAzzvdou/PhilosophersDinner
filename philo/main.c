/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:41:25 by jazevedo          #+#    #+#             */
/*   Updated: 2024/04/18 16:06:41 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_philo(t_philo *philo, char **argv)
{
	philo->nb_philo = ft_atol(argv[1]);
	philo->to_die = ft_atol(argv[2]);
	philo->to_eat = ft_atol(argv[3]);
	philo->to_sleep = ft_atol(argv[4]);
	if (argv[5])
		philo->must_eat = ft_atol(argv[5]);
	if (!philo->must_eat)
		philo->must_eat = -1;
}

int	main(int argc, char **argv)
{
	t_philo	philo;

	philo = (t_philo){0};
	if (invalid_arguments(argc, argv))
		return (1);
	start_philo(&philo, argv);
	return (0);
}
