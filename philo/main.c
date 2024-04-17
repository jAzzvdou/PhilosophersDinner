/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:41:25 by jazevedo          #+#    #+#             */
/*   Updated: 2024/04/17 17:53:09 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	n -= 1;
	i = -1;
	while ((s1[++i] || s2[i]) && i < n)
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void    paint(char *color)
{
        if (!ft_strncmp(color, "red", 3))
                printf("\033[38;2;255;0;0m");
        else if (!ft_strncmp(color, "green", 5))
                printf("\033[38;2;0;255;0m");
        else if (!ft_strncmp(color, "blue", 4))
                printf("\033[38;2;0;0;255m");
        else if (!ft_strncmp(color, "yellow", 6))
                printf("\033[38;2;255;255;0m");
        else if (!ft_strncmp(color, "white", 5))
                printf("\033[38;2;255;255;255m");
        else if (!ft_strncmp(color, "reset", 5))
                printf("\033[0m");
        else if (!ft_strncmp(color, "clear", 5))
                printf("\033[H\033[J");
}

int	invalid_arguments(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
	{
		paint("yellow");
		printf("%s\n", ERROR_ARGS);
		paint("red");
		return (printf("\t%s\n", USAGE));
	}
	return (0);
}

int	main(int argc, char **argv)
{
	/*
	t_philo	philo;

	philo = (t_philo){0};
	*/
	if (invalid_arguments(argc, argv))
		return (-1);
	return (0);
}
