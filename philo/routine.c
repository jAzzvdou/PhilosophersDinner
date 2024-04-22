/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:05:06 by jazevedo          #+#    #+#             */
/*   Updated: 2024/04/22 18:21:30 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *thread)
{
	t_philo	*philo;

	philo = (t_philo *)thread;
	//philo->start = ;
	//philo->death = philo->start + philo->infos.to_die;
	//if (philo->tid % 2 == 0)
	//	usleep(1000000);
	while (1)
	{
		printf("\033[38;2;%d;%d;%dmPhilosopher[%d] make an action.\n",
			(philo->color >> 16) & 0xFF,
			(philo->color >> 8) & 0xFF,
			philo->color & 0xFF, philo->tid);
		usleep(1000000);
		//reckon
		//eat
		//sleep
	}
}
