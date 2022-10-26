CC =		gcc
CFLAGS =	-Wall -Wextra -Werror
RM =		 rm -f


SRCS =			ft_split.c \
				ft_calloc.c \
				ft_itoa.c \
				ft_strmapi.c \
				ft_strtrim.c \
				ft_substr.c \
				ft_strjoin.c \
				ft_strdup.c \
				ft_atoi.c \
				ft_isalnum.c \
				ft_isalpha.c \
				ft_isascii.c \
				ft_isdigit.c \
				ft_isprint.c \
				ft_strlcpy.c \
				ft_strlen.c \
				ft_strncmp.c \
				ft_putchar_fd.c \
				ft_putendl_fd.c \
				ft_putstr_fd.c \
				ft_putendl_fd.c \
				ft_bzero.c \
				ft_putnbr_fd.c \
				ft_memcpy.c \
				ft_memcmp.c \
				ft_memchr.c \
				ft_memset.c \
				ft_memmove.c \
				ft_toupper.c \
				ft_tolower.c \
				ft_strlcat.c \
				ft_strchr.c \
				ft_strrchr.c \
				ft_strnstr.c \
				ft_striteri.c

SRCS_BONUS =	ft_lstnew.c \
				ft_lstadd_front.c \
				ft_lstsize.c \
				ft_lstlast.c \
				ft_lstadd_back.c \
				ft_lstdelone.c \
				ft_lstclear.c \
				ft_lstiter.c \
				ft_lstmap.c \
				is_in_charset_bonus.c \
				char_to_str_bonus.c \
				strlen_until_bonus.c \
				itoa_base_bonus.c \
				utoa_bonus.c \
				strrev_bonus.c \
				ft_printf/ft_printf.c \
				ft_printf/conversions/conversions.c \
				ft_printf/conversions/character.c \
				ft_printf/conversions/hexa.c \
				ft_printf/conversions/pointer.c \
				ft_printf/writer/writer.c \
				ft_printf/utils/free_join.c \
				ft_printf/utils/index_words.c \
				get_next_line.c

OBJS =			$(SRCS:.c=.o)
OBJS_BONUS =	$(SRCS_BONUS:.c=.o)
NAME =     		libft.a

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

all: $(NAME)

bonus: $(OBJS) $(OBJS_BONUS)
	ar -rcs $(NAME) $(OBJS) $(OBJS_BONUS)

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

testc:
	${RM} test

test: ${NAME} testc
	${CC} ${CFLAGS} main.c -L. -lft -o test
	./test
