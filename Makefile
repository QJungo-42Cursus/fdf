NAME =		fdf

CC =		gcc
CFLAGS =	-Wall -Wextra -Werror
RM =		rm -f
SRCS =		main.c \
			read_file.c
OBJS =		$(SRCS:.c=.o)

all: $(NAME)

# TODO : attention ca relink la libft !! (ou pas ?)
libft:
	cd ./libft/ && make bonus

$(NAME): $(OBJS)
	make libft
	$(CC) $(CFLAGS) $(OBJS) -L./libft -lft -o $(NAME)

clean:
	cd ./libft/ && make clean
	$(RM) $(OBJS)

fclean: clean
	cd ./libft/ && make fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re libft

test: re
	./fdf
