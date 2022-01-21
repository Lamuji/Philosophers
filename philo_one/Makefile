NAME = philo.a
CC = gcc -g 
FLAGS = -Wall -Werror -Wextra
AR = ar -rcs
PROG_NAME = philo

SRC = main.c \
	philo_utils.c \


OBJS = $(SRC:.c=.o)

%.o: %.c
 
		$(CC) $(FLAGS) -c $< -o $@
	
all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft/
	@$(AR) $(NAME) $(OBJS)
	@$(CC) $(FLAGS) $(NAME) -lpthread libft/libft.a -o $(PROG_NAME) $?

clean: 
		@make -C libft/ clean
		rm -f $(OBJS)

fclean: clean
	@make -C libft/ fclean
	rm -f $(NAME) $(PROG_NAME)

re: fclean all
