NAME = philo.a
CC = gcc -g 
FLAGS = -Wall -Werror -Wextra
AR = ar -rcs
PROG_NAME = philo

SRC = main.c \
	philo_utils.c \
	ft_error.c \

OBJS = $(SRC:.c=.o)

%.o: %.c
		$(CC) $(FLAGS) -c $< -o $@
	
all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@$(CC) $(FLAGS) $(NAME) -lpthread  -o $(PROG_NAME) $?

clean: 
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) $(PROG_NAME)

re: fclean all
