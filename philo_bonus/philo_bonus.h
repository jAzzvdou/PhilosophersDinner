/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 21:21:33 by jazevedo          #+#    #+#             */
/*   Updated: 2024/04/29 21:27:54 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <unistd.h>   //| WRITE, USLEEP
# include <stdlib.h>   //| MALLOC, FREE, NULL
# include <pthread.h>  //| THREAD's FUNCTIONS
# include <stdio.h>    //| PRINTF
# include <sys/time.h> //| GETTIMEOFDAY

# define RED    1
# define GREEN  2
# define BLUE   3
# define YELLOW 4
# define WHITE  5
# define GREY   6
# define RESET  7
# define CLEAR  8

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
typedef struct s_philo
{
	int				philos;
        int                             tid;
        int                             color;
        int                             eaten;
	int				must_eat;
        long                    start;
        long                    death;
	long			to_die;
	long			to_eat;
	long			to_sleep;
	sem_t			*sem_forks;
	sem_t			*sem_print;
	pthread_mutex_t	mutex_death;
}       t_philo;
