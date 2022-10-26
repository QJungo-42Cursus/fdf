NAME =		fdf
CC =		gcc
# TODO le -lm ajoute les fonctions mathematiques	
CFLAGS =	-Wall -Wextra -Werror #-lm
RM =		rm -f
SRCS =		main.c \
			read_map/read_map.c \
			read_map/log.c \
			display/display.c \
			display/pixel_to_image.c \
			display/event.c \
			display/draw_line.c \
			ft_math/line.c

#%.o: %.c
#	$(CC) $(CFLAGS) -Imlx -c $< -o $@

OBJS =		$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@make bonus -C libft
	@make -C minilibx_macos
	$(CC) $(CFLAGS) $(OBJS) -L./libft -lft -L./minilibx_macos -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	@make clean -C libft
	@make clean -C minilibx_macos 
	$(RM) $(OBJS)

fclean: clean
	@make fclean -C libft
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re libft

test: $(OBJS)
	@make libft
	$(CC) $(CFLAGS) -g $(OBJS) -L./libft -lft -L./minilibx_macos -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@lldb --batch -K lldb.batch -o run ./fdf test_maps/10-2.fdf
	#@lldb --batch -K lldb.batch -o run ./fdf test_maps/10-70.fdf
	#@lldb --batch -K lldb.batch -o run ./fdf test_maps/10-2.fdf
	#@lldb --batch -K lldb.batch -o run ./fdf test_maps/10-2.fdf
