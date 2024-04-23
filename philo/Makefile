NAME	=	philo

NAME_BONUS	=	philo_bonus

SRCS	=	main.c             \
		verify_arguments.c \
		errors.c           \
		color.c            \
		starters.c         \
		routine.c          \
		eat.c              \
		philo_utils.c      \
		utils.c

SRCS_BONUS	=	

OBJS	=	$(SRCS:.c=.o)

OBJS_BONUS	=	$(SRCS_BONUS:.c=.o)

CC	=	cc

CFLAGS	=	-Wall -Werror -Wextra

RM	=	rm -rf 

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) -o $(NAME) $(OBJS)

$(NAME_BONUS): $(OBJS_BONUS)
		$(CC) -o $(NAME_BONUS) $(OBJS_BONUS)

.c.o:
		$(CC) $(CFLAGS) -c $<

clean:
		$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)

re: fclean all

bonus: $(NAME_BONUS)

.PHONY: all clean fclean re bonus
