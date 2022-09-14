CC =		gcc
CFLAGS =	-Wall -Wextra -Werror
RM =		rm -f
SRCS =		ft_printf.c \
			conversions/conversions.c \
			conversions/character.c \
			conversions/hexa.c \
			conversions/pointer.c \
			writer/writer.c \
			utils/free_join.c \
			utils/index_words.c

OBJS =		${SRCS:.c=.o}
NAME =		libftprintf.a

all: ${NAME}

libft:
	cd ./libft/ && make bonus
	cp ./libft/libft.a $(NAME)

$(NAME): $(OBJS)
	make libft
	ar -rcs $(NAME) $(OBJS)

clean:
	cd ./libft/ && make clean
	${RM} ${OBJS}

fclean: clean
	cd ./libft/ && make fclean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re libft

test: re
	gcc main.c -L. -lftprintf 
	./a.out
