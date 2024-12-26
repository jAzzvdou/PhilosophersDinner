#include "philo_bonus.h"

void	paint(int color)
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

int	make_color(int c, int min, int max)
{
	int		red;
	int		green;
	int		blue;
	float	calc;

	if (c == 0)
		return (0x00FF00);
	else if (c > 0 && c <= max)
	{
		calc = (float)c / max;
		red = 255 * calc;
		green = 255 - red;
		blue = 0;
		return ((red << 16) | (green << 8) | blue);
	}
	else if (c < 0 && c >= min)
	{
		calc = (float)c / min;
		blue = 255 * calc;
		green = 255 - blue;
		red = 0;
		return ((red << 16) | (green << 8) | blue);
	}
	else
		return (0x000000);
}

int	*get_colors(int philos)
{
	int	i;
	int	color;
	int	*colors;

	colors = malloc(sizeof(int) * philos);
	if (!colors)
		return (NULL);
	color = -(philos / 2);
	i = -1;
	while (++i < philos)
		colors[i] = make_color(color++, -(philos / 2), (philos / 2));
	return (colors);
}
