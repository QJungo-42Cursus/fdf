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

## MLX ##
ifeq ($(shell uname), Linux)
MLX =	-L./minilibx-linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz
else
MLX =		-L./minilibx_macos -lmlx -framework OpenGL -framework AppKit
endif

ifeq ($(shell uname), Linux)
MLX_REP = minilibx-linux
else
MLX_REP = minilibx_macos
endif
########

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft
	make -C $(MLX_REP)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) -o $(NAME)

clean:
	@make clean -C libft
	@make clean -C $(MLX_REP) 
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
	@make -C $(MLX_REP)
	$(CC) $(CFLAGS) -g $(OBJS) $(LIBFT) $(MLX) -o $(NAME)
	clear
	./fdf test_maps/42.fdf

.PHONY: all clean fclean re libft test
