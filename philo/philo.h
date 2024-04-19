/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:23:25 by jazevedo          #+#    #+#             */
/*   Updated: 2024/04/19 19:25:18 by jazevedo         ###   ########.fr       */
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

//----------| ARGUMENTS ERRORS |----------//
# define ERROR_ARGS "Error! Invalid Arguments.\n\t-> "
# define POSITIVE_VALUES "\t\tAll Values Must Be Positives > 0."
# define USAGE "Usage: (Philosophers) (Die) (Eat) (Sleep) [Must Eat]."
# define ONLY_NB "[Must Eat] Is Optional. All Arguments Must Be A Number."
# define OVERFLOW "Overflow: All Values Must Be An INT."
# define NB_PHILO "ARGV[1]: Max Number Of Philosphers Is 200."
# define VALUE_DIE "ARGV[2] Value: Max = INT_MAX && MIN = 60."
# define VALUE_EAT "ARGV[3] Value: Max = INT_MAX && MIN = 60."
# define VALUE_SLEEP "ARGV[4] Value: Max = INT_MAX && MIN = 60."
# define VALUE_MUST_EAT "ARGV[5] Value: Max = INT_MAX && MIN = 1."

//----------| PHILOSOPHERS STRUCT |----------//
/*
typedef struct s_table
{
	int	id;
	int	fork;
	int	eaten;
	s_table	*next;
}		t_table;
*/
//----------| MAIN STRUCT |----------//
typedef struct s_philo
{
	int		nb_philo;
	int		to_die;
	int		to_eat;
	int		to_sleep;
	int		must_eat;
	int		tid;
	int		color;
	pthread_t	thread;
	pthread_mutex_t	mutex;
	//t_table		*table;
}			t_philo;

//----------| ARGUMENTS |----------//
int	invalid_arguments(int argc, char **argv);

//----------| ERRORS |----------//
int	error_number_arguments(void);
int	error_only_number(void);
int	error_overflow(void);
int	error_start(void);

//----------| COLORS |----------//
void	paint(int color);

//----------| UTILS |----------//
size_t	ft_strlen(const char *str);
long	ft_atol(const char *nptr);

#endif //| PHILOSOPHERS
