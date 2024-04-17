/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 18:35:03 by jazevedo          #+#    #+#             */
/*   Updated: 2024/04/17 18:47:03 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error_number_arguments(void)
{
	paint(RED);
	printf("%s\n\t-> ", ERROR_ARGS);
	paint(WHITE);
	printf("%s\n", USAGE);
	paint(GREY);
	printf("\t\tAll Values Must Be Positives.\n");
	return (1);
}
