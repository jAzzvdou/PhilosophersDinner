/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:23:25 by jazevedo          #+#    #+#             */
/*   Updated: 2024/04/17 17:50:30 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>  //| WRITE, USLEEP
# include <stdlib.h>  //| MALLOC, FREE, NULL
# include <pthread.h> //| THREAD's FUNCTIONS
# include <string.h>  //| MEMSET
# include <stdio.h>   //| PRINTF

# define USAGE "Usage: (Philosophers) (Die) (Eat) (Sleep) [Must Eat]."
# define ERROR_ARGS "Error! Invalid Arguments."
/*
typedef struct s_table
{
	int	philo;
	s_table	*next;
}	t_table;

typedef struct s_philo
{
	t_table	*table;
}	t_philo;
*/
#endif //| PHILOSOPHERS
