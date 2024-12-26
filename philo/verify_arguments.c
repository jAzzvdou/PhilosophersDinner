#include "philo.h"

int	is_number(int nb)
{
	if (nb >= '0' && nb <= '9')
		return (1);
	return (0);
}

int	only_number(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '-')
		return (0);
	if (s[i] == '+')
		i++;
	while (s[i])
		if (!is_number(s[i++]))
			return (0);
	return (1);
}

int	is_value(int argc, char **argv)
{
	while (--argc > 0)
		if (!only_number(argv[argc]))
			return (0);
	return (1);
}

int	is_int(int argc, char **argv)
{
	while (--argc > 0)
		if (my_strlen(argv[argc]) > 10
			|| my_atol(argv[argc]) > 2147483647)
			return (0);
	return (1);
}

int	invalid_arguments(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (error_number_arguments());
	if (!is_value(argc, argv))
		return (error_only_number());
	if (!is_int(argc, argv))
		return (error_overflow());
	return (0);
}
