NAME =		fdf
CC =		gcc
CFLAGS =	-Wall -Wextra -Werror
RM =		rm -f
LIBFT =		-L./libft -lft
SRCS =		main.c \
			utils.c \
			read_map/read_map.c \
			read_map/read_map2.c \
			read_map/read_map_utils.c \
			read_map/create_edges.c \
			projection/display.c \
			projection/projection.c \
			projection/render.c \
			hooks/key.c \
			hooks/expose.c

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

ifeq ($(shell uname), Linux)
LEAKS =	valgrind -q --leak-check=full --track-origins=yes
else 
LEAKS = leaks
endif		

SAN =	-fsanitize=address -fsanitize=undefined -fno-sanitize-recover=all \
		-fsanitize=float-divide-by-zero -fsanitize=float-cast-overflow \
		-fno-sanitize=null -fno-sanitize=alignment

san:
	@make -C libft
	@make -C $(MLX_REP)
	$(CC) $(CFLAGS) $(SAN) $(SRCS) $(LIBFT) $(MLX) -o $(NAME) 
	./fdf test_maps/42.fdf


leaks: all
	clear
	@#@echo "with bad map";
	@#$(LEAKS) ./fdf test_maps/tq3.fdf
	@#@echo "...";
	@#$(LEAKS) ./fdf test_maps/42.fdf

.PHONY: all clean fclean re libft test
