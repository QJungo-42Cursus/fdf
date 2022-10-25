#include "fdf.h"
#include "libft/libft.h"
#include <fcntl.h>

static int	fail(t_list **list)
//	Free tous ce qui a ete alloue (les string, les noeus, ...)
{
	(void)list;
	return (2);
}

/*
static int	get_lines()
{
}
*/

static int	*str_to_int_tab(const char *line, int *x_size)
{
	char	**words;
	int		*res;
	int		i;
	int		last_len;

	*x_size = 0;
	words = ft_split(line, ' ');
	last_len = *x_size;
	while (words[*x_size])
		(*x_size)++;
	if (last_len != 0 && last_len != *x_size)
	{
		ft_printf("L'axe X ne comporte pas les memes longueurs\n");
		// TODO free des trucs ?
		exit(0);
		return (NULL);
	}
	res = malloc(sizeof(int) * (*x_size));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (words[i])
	{
		res[i] = ft_atoi(words[i]);
		i++;
	}
	return (res);
}

int	read_file(const char *path)
{
	int		fd;
	t_map	map;
	char	*line;
	t_list	*lines;
	t_list	*new_node;
	int		*parsed_line;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (-1);

	map.x_size = 0;
	map.y_size = 0;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		parsed_line = str_to_int_tab(line, &(map.x_size));
		free(line);
		if (parsed_line == NULL)
			return (fail(&lines));
		new_node = ft_lstnew((void *)parsed_line);
		if (new_node == NULL)
			return (fail(&lines));
		ft_lstadd_back(&lines, new_node);
		map.y_size++;
	}
	return (0);
}
