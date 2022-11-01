/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjungo <qjungo@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 09:57:22 by qjungo            #+#    #+#             */
/*   Updated: 2022/11/01 11:58:24 by qjungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "read_map.h"
#include "../fdf.h"
#include "../ft_math/ft_math.h"
#include "../libft/libft.h"

static int	fail(t_list **list)
//	Free tous ce qui a ete alloue (les string, les noeus, ...)
{
	(void)list;
	return (2);
}

static int	get_lines(int fd, t_list **start_lines_list, t_map *map)
{
	t_list	*new_node;
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		new_node = ft_lstnew((void *)line);
		if (new_node == NULL)
			return (fail(start_lines_list));
		ft_lstadd_back(start_lines_list, new_node);
		map->y_size++;
	}
	return (0);
}

static int	get_x_size(t_list *line)
{
	char	**words;
	int		size;

	words = ft_split((char *)line->content, ' ');
	size = 0;
	while (words[size] && words[size][0] != '\n')
	{
		free(words[size]);
		size++;
	}
	free(words);
	return (size);
}

static int	line_to_vertices(char ***words, t_map *map, int *i, int y)
{
	int		x;

	x = 0;
	while ((*words)[x] && (*words)[x][0] != '\n')
	{
		map->vertices[*i] = new_vec3(x, y, ft_atoi((*words)[x]));
		map->vertices[*i] = new_vec3(x, y, ft_atoi((*words)[x]));
		free((*words)[x]);
		x++;
		(*i)++;
	}
	free(*words);
	return (0);
}

static int	parse_lines(t_list **start_lines_list, t_map *map)
{
	t_list	*node;
	t_list	*l_node;
	char	**words;
	int		y;
	int		i;

	node = *start_lines_list;
	i = 0;
	y = 0;
	while (node)
	{
		words = ft_split((char *)node->content, ' ');
		if (words == NULL)
			return (fail(start_lines_list));
		line_to_vertices(&words, map, &i, y);
		y++;
		l_node = node;
		node = node->next;
		free(l_node->content);
		free(l_node);
	}
	return (0);
}

int	read_map(const char *path, t_map *map)
{
	int		fd;
	t_list	*start_lines_list;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (-1);
	map->x_size = 0;
	map->y_size = 0;
	start_lines_list = NULL;
	get_lines(fd, &start_lines_list, map);
	map->x_size = get_x_size(start_lines_list);
	map->vertices = malloc(sizeof(t_vec3) * (map->x_size * map->y_size));
	parse_lines(&start_lines_list, map);
	map->size = map->x_size * map->y_size;

	//log_final_map(map);
	return (0);
}

