NAME =		fdf
CC =		gcc
CFLAGS =	-Wall -Wextra -Werror
RM =		rm -f
LIBFT =		-L./libft -lft
SRCS =		main.c \
			read_map/read_map.c \
			read_map/read_map2.c \
			read_map/create_edges.c \
			projection/display.c \
			projection/projection.c \
			projection/render.c \
			hooks/key.c

OBJS =		$(SRCS:.c=.o)

all: $(NAME)

MAC_L =		-L./minilibx_macos -lmlx -framework OpenGL -framework AppKit
LINUX_L =	-L./minilibx-linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz

$(NAME): $(OBJS)
	make -C libft
ifeq ($(shell uname), Linux)
	make -C minilibx-linux
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(LINUX_L) -o $(NAME)
else
	make -C minilibx_macos
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MAC_L) -o $(NAME)
endif

clean:
	@make clean -C libft
ifeq ($(shell uname), Linux)
	@make clean -C minilibx-linux
else
	@make clean -C minilibx_macos 
endif
	$(RM) $(OBJS)

fclean: clean
ifeq ($(shell uname), Linux)
	rm -f minilibx-linux/libmlx_Linux.a
else
	rm -f minilibx_macos/libmlx.a
endif
	rm -f libft/libft.a
	$(RM) $(NAME)

re: fclean all


test: $(OBJS)
	@make -C libft
ifeq ($(shell uname), Linux)
	@make -C minilibx-linux
	$(CC) $(CFLAGS) -g $(OBJS) $(LIBFT) $(LINUX_L) -o $(NAME)
else
	@make -C minilibx_macos
	$(CC) $(CFLAGS) -g $(OBJS) $(LIBFT) $(MAC_L) -o $(NAME)
endif
	clear
	./fdf test_maps/42.fdf

.PHONY: all clean fclean re libft test
