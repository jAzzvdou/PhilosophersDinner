NAME	=	philo

SRCS	=	main.c             \
		verify_arguments.c \
		errors.c           \
		color.c            \
		starters.c         \
		routine.c          \
		eat.c              \
		sleep.c            \
		cleaner.c          \
		philo_utils.c      \
		utils.c

OBJS	=	$(SRCS:.c=.o)

CC	=	cc

CFLAGS	=	-Wall -Werror -Wextra

RM	=	rm -rf 

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) -o $(NAME) $(OBJS)

.c.o:
		$(CC) $(CFLAGS) -c $<

clean:
		$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

bonus: $(NAME_BONUS)

.PHONY: all clean fclean re
