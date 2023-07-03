NAME 	=	philo

SRCS 	=	main.c parser.c utils.c utils2.c init.c ft_philo.c tasks.c utils3.c

CC 		= 	@gcc -pthread -g

OBJS 	= 	$(SRCS:.c=.o)

FLAGS 	= 	-Wall -Werror -Wextra

.c.o	:
			$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME)	: 	$(OBJS)
			$(CC) $(FLAGS) $(OBJS) -o $(NAME)

all		: 	$(NAME)

clean	:
			@rm -rf $(OBJS)

fclean	: 	clean
			@rm -rf $(NAME)

re		: 	fclean all

.PHONY	: 	clean fclean re all
