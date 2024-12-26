#include "philo.h"

int	error_number_arguments(void)
{
	paint(RED);
	printf("%s", ERROR_ARGS);
	paint(WHITE);
	printf("%s\n", USAGE);
	paint(GREY);
	printf("%s\n", POSITIVE_VALUES);
	return (1);
}

int	error_only_number(void)
{
	paint(RED);
	printf("%s", ERROR_ARGS);
	paint(WHITE);
	printf("%s\n", ONLY_NB);
	paint(GREY);
	printf("%s\n", POSITIVE_VALUES);
	return (1);
}

int	error_overflow(void)
{
	paint(RED);
	printf("%s", ERROR_ARGS);
	paint(WHITE);
	printf("%s\n", OVERFLOW);
	paint(GREY);
	printf("%s\n", POSITIVE_VALUES);
	return (1);
}

int	error_start(void)
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
