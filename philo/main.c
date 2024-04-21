/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:41:25 by jazevedo          #+#    #+#             */
/*   Updated: 2024/04/19 20:12:50 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "infos.h"

int	main(int argc, char **argv)
{
	t_infos		infos;
	t_mutexes	mutexes;

	infos = (t_infos){0};
	mutexes = (t_mutexes){0};
	if (invalid_arguments(argc, argv))
		return (1);
	if (!start_infos(&infos, argv))
		return (1);
	start_mutexes(&infos, &mutexes);
	if (!start_threads(&infos, &mutexes))
		return (1);
	return (0);
}
