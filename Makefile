NAME =		fdf
CC =		gcc
CFLAGS =	-Wall -Wextra -Werror #-lm TODO math ?
RM =		rm -f
LIBFT =		-L./libft -lft
SRCS =		main.c \
			read_map/read_map.c \
			read_map/log.c \
			display/display.c \
			display/pixel_to_image.c \
			display/event.c \
			display/draw_line.c \
			ft_math/line.c \
			ft_math/vec.c
OBJS =		$(SRCS:.c=.o)


all: $(NAME)

MAC_L =		-L./minilibx_macos -lmlx -framework OpenGL -framework AppKit
LINUX_L =	-L./minilibx-linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz

$(NAME): $(OBJS)
	@make bonus -C libft
ifeq ($(shell uname), Linux)
	@make -C minilibx-linux
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(LINUX_L) -o $(NAME)
else
	@make -C minilibx_macos
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

.PHONY: all clean fclean re libft

test: $(OBJS)
	@make bonus -C libft
ifeq ($(shell uname), Linux)
	@make -C minilibx-linux
	$(CC) $(CFLAGS) -g $(OBJS) $(LIBFT) $(LINUX_L) -o $(NAME)
else
	@make -C minilibx_macos
	$(CC) $(CFLAGS) -g $(OBJS) $(LIBFT) $(MAC_L) -o $(NAME)
endif
	clear
	./fdf test_maps/100-6.fdf
	#@lldb --batch -K lldb.batch -o run ./fdf test_maps/100-6.fdf
	#@lldb --batch -K lldb.batch -o run ./fdf test_maps/10-70.fdf
	#@lldb --batch -K lldb.batch -o run ./fdf test_maps/10-2.fdf
	#@lldb --batch -K lldb.batch -o run ./fdf test_maps/10-2.fdf
