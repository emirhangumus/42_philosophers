NAME = philo
CC = gcc
CFLAGS = -Wall -Wextra -Werror -pthread

SRCS = philo.c timer.c utils.c error.c free.c parse.c init.c start_action.c routine.c print.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re