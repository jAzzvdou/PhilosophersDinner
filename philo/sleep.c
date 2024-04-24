/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:54:44 by jazevedo          #+#    #+#             */
/*   Updated: 2024/04/24 13:55:10 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	sleep_pls(t_philo *philo)
{
	print_action(philo, "is sleeping..");
	return (waiting(philo, philo->infos.to_sleep));
}
