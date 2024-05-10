/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 13:42:43 by jazevedo          #+#    #+#             */
/*   Updated: 2024/05/10 13:44:22 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	milisecond(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

int	waiting(t_philo *philo, long timer)
{
	long	final;

	final = milisecond() + timer;
	while (final > milisecond())
	{
		if (is_dead(philo))
			return (0);
		usleep(500);
	}
	return (1);
}
