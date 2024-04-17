/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:41:25 by jazevedo          #+#    #+#             */
/*   Updated: 2024/04/17 18:51:46 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	invalid_arguments(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (error_number_arguments());
	// if (todos os argumentos tem que ser só de número)
	// if (não pode dar overflow)
	// if (se o número de filósofos é maior que 200)
	return (0);
}

int	main(int argc, char **argv)
{
	/*
	t_philo	philo;

	philo = (t_philo){0};
	*/
	if (invalid_arguments(argc, argv))
		return (-1);
	return (0);
}
