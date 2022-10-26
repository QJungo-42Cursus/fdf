/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjungo <qjungo@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 09:57:22 by qjungo            #+#    #+#             */
/*   Updated: 2022/10/26 12:59:30 by qjungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "read_map.h"
#include "../fdf.h"
#include "../libft/libft.h"

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

static int	*parse_line(const char *line, int *x_size)
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
	(*x_size)--;
	if (last_len != 0 && last_len != *x_size)
	{
		ft_printf("L'axe X ne comporte pas les memes longueurs\n");
		// TODO free des trucs ?
		exit(0);
	}
	res = malloc(sizeof(int) * (*x_size));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (words[i])
	{
		res[i] = ft_atoi(words[i]);
		free(words[i]);
		i++;
	}
	return (res);
}

int	read_map(const char *path, t_map *map)
{
	int		fd;
	char	*line;
	t_list	*start_lines_list;
	t_list	*new_node;
	int		*parsed_line;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (-1);

	map->x_size = 0;
	map->y_size = 0;

	start_lines_list = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		parsed_line = parse_line(line, &(map->x_size));
		free(line);
		if (parsed_line == NULL)
			return (fail(&start_lines_list));
		new_node = ft_lstnew((void *)parsed_line);
		if (new_node == NULL)
			return (fail(&start_lines_list));
		ft_lstadd_back(&start_lines_list, new_node);
		map->y_size++;
	}

	log_print_map(start_lines_list, *map);

	int		y;
	y = 0;
	map->points = malloc(sizeof(int *) * map->y_size);
	while (start_lines_list)
	{

		parsed_line = (int *)start_lines_list->content;
		map->points[y] = parsed_line;
		new_node = start_lines_list;
		start_lines_list = start_lines_list->next;
		if (new_node != NULL)
			free(new_node);
		y++;
	}

	log_final_map(*map);
	return (0);
}

