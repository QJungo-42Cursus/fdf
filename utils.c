#include <errno.h>
#include <stdio.h>
#include "libft/libft.h"

void	terminate(char *s)
{
	if (errno == 0)
		ft_putendl_fd(s, 2);
	else
		perror(s);
	exit(1);
}
