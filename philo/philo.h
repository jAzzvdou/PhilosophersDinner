/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:23:25 by jazevedo          #+#    #+#             */
/*   Updated: 2024/04/17 18:44:11 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>  //| WRITE, USLEEP
# include <stdlib.h>  //| MALLOC, FREE, NULL
# include <pthread.h> //| THREAD's FUNCTIONS
# include <string.h>  //| MEMSET
# include <stdio.h>   //| PRINTF

# define RED	1
# define GREEN	2
# define BLUE	3
# define YELLOW	4
# define WHITE	5
# define GREY	6
# define RESET	7
# define CLEAR	8

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

//----------| ERRORS |----------//
int	error_number_arguments(void);

//----------| COLORS |----------//
void	paint(int color);

#endif //| PHILOSOPHERS
