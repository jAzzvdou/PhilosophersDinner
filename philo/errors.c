/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 18:35:03 by jazevedo          #+#    #+#             */
/*   Updated: 2024/04/18 15:39:39 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error_number_arguments(void)
{
	paint(RED);
	printf("%s", ERROR_ARGS);
	paint(WHITE);
	printf("%s\n", USAGE);
	paint(GREY);
	printf("%s\n", POSITIVE_VALUES);
	return (1);
}

int	error_only_number(void)
{
	paint(RED);
	printf("%s", ERROR_ARGS);
	paint(WHITE);
	printf("%s\n", ONLY_NB);
	paint(GREY);
	printf("%s\n", POSITIVE_VALUES);
	return (1);
}

int	error_overflow(void)
{
	paint(RED);
	printf("%s", ERROR_ARGS);
	paint(WHITE);
	printf("%s\n", OVERFLOW);
	paint(GREY);
	printf("%s\n", POSITIVE_VALUES);
	return (1);

}

int	error_philosophers(void)
{
	paint(RED);
	printf("%s", ERROR_ARGS);
	paint(WHITE);
	printf("%s\n", MAX_PHILO);
	paint(GREY);
	printf("%s\n", MIN_PHILO);
	return (1);
}
