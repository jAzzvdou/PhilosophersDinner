/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:23:25 by jazevedo          #+#    #+#             */
/*   Updated: 2024/05/10 13:44:19 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>   //| WRITE, USLEEP
# include <stdlib.h>   //| MALLOC, FREE, NULL
# include <pthread.h>  //| THREAD's FUNCTIONS
# include <stdio.h>    //| PRINTF
# include <sys/time.h> //| GETTIMEOFDAY

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
# define PHILO_ACTION "\033[38;2;%d;%d;%dmPhilosopher[%d] %s. TIME: %ld.\n"

//----------| INFOS STRUCT |----------//
typedef struct s_infos
{
	int	philos;
	int	to_die;
	int	to_eat;
	int	to_sleep;
	int	must_eat;
	int	colors;
}	t_infos;

//----------| MUTEXES STRUCT |----------//
typedef struct s_mutexes
{
	int				stop;
	int				eaten;
	pthread_mutex_t	mutex_stop;
	pthread_mutex_t	mutex_eaten;
	pthread_mutex_t	mutex_print;
}	t_mutexes;

//----------| PHILOSOPHERS STRUCT |----------//
typedef struct s_philo
{
	int				tid;
	int				fork;
	int				color;
	int				eaten;
	int				philo_ate;
	int				philo_died;
	int				philo_stop;
	long			start;
	long			death;
	t_infos			infos;
	t_mutexes		*mutexes;
	pthread_mutex_t	mutex_fork;
	struct s_philo	*next;
}	t_philo;

//----------| ARGUMENTS |----------//
int		invalid_arguments(int argc, char **argv);

//----------| STARTERS |----------//
int		start_infos(t_infos *infos, char **argv);
void	start_mutexes(t_infos *infos, t_mutexes *mutexes);
int		start_threads(t_infos *infos, t_mutexes *mutexes);
t_philo	*start_philos(t_infos *infos, t_mutexes *mutexes);

//----------| PHILOSOPHERS |----------//
void	add_on_table(t_philo **philo, t_philo *new_philo);
t_philo	*new_philo(t_infos *infos, t_mutexes *mutexes, int tid);
t_philo	*last_philo(t_philo *philo);

//----------| ROUTINE |----------//
void	print_action(t_philo *philo, char *message);
int		is_dead(t_philo *philo);
int		eat_pls(t_philo *philo);
int		sleep_pls(t_philo *philo);
void	return_forks(t_philo *philo);
int		have_eaten(t_philo *philo);
void	*routine(void *philo);
void	*death_watcher(void *watching);

//----------| TIMERS |----------//
long	milisecond(void);
int		waiting(t_philo *philo, long timer);

//----------| CLEANER |----------//
void	clear_philos(t_philo *philo);
void	cleaner(t_philo *philo, t_mutexes *mutexes);

//----------| ERRORS |----------//
int		error_number_arguments(void);
int		error_only_number(void);
int		error_overflow(void);
int		error_start(void);

//----------| COLORS |----------//
void	paint(int color);
int		make_color(int c, int min, int max);

//----------| UTILS |----------//
size_t	ft_strlen(const char *str);
long	ft_atol(const char *nptr);

#endif //| PHILOSOPHERS
