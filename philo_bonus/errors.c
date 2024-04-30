/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 21:17:09 by jazevedo          #+#    #+#             */
/*   Updated: 2024/04/29 21:17:27 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int     error_number_arguments(void)
{
        paint(RED);
        printf("%s", ERROR_ARGS);
        paint(WHITE);
        printf("%s\n", USAGE);
        paint(GREY);
        printf("%s\n", POSITIVE_VALUES);
        return (1);
}

int     error_only_number(void)
{
        paint(RED);
        printf("%s", ERROR_ARGS);
        paint(WHITE);
        printf("%s\n", ONLY_NB);
        paint(GREY);
        printf("%s\n", POSITIVE_VALUES);
        return (1);
}

int     error_overflow(void)
{
        paint(RED);
        printf("%s", ERROR_ARGS);
        paint(WHITE);
        printf("%s\n", OVERFLOW);
        paint(GREY);
        printf("%s\n", POSITIVE_VALUES);
        return (1);
}

int     error_start(void)
{
        paint(RED);
        printf("%s", ERROR_ARGS);
        paint(WHITE);
        printf("%s\n", NB_PHILO);
        paint(RED);
        printf("\t-> ");
        paint(WHITE);
        printf("%s\n", VALUE_DIE);
        paint(RED);
        printf("\t-> ");
        paint(WHITE);
        printf("%s\n", VALUE_EAT);
        paint(RED);
        printf("\t-> ");
        paint(WHITE);
        printf("%s\n", VALUE_SLEEP);
        paint(RED);
        printf("\t-> ");
        paint(WHITE);
        printf("%s\n", VALUE_MUST_EAT);
        return (0);
}
