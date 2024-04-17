/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 18:44:31 by jazevedo          #+#    #+#             */
/*   Updated: 2024/04/17 18:45:06 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    paint(int color)
{
        if (color == RED)
                printf("\033[38;2;255;0;0m");
        else if (color == GREEN)
                printf("\033[38;2;0;255;0m");
        else if (color == BLUE)
                printf("\033[38;2;0;0;255m");
        else if (color == YELLOW)
                printf("\033[38;2;255;255;0m");
        else if (color == WHITE)
                printf("\033[38;2;255;255;255m");
	else if (color == GREY)
                printf("\033[38;2;128;128;128m");
        else if (color == RESET)
                printf("\033[0m");
        else if (color == CLEAR)
                printf("\033[H\033[J");
}
