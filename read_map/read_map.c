/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjungo <qjungo@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 09:57:22 by qjungo            #+#    #+#             */
/*   Updated: 2022/11/02 11:15:43 by qjungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "read_map.h"
#include "../fdf.h"
#include "../libft/libft.h"

static int	part1(t_map *map, t_list **start_lines_list,
		int fd)
{
	map->x_size = 0;
	map->y_size = 0;
	*start_lines_list = NULL;
	if (get_lines(fd, start_lines_list, map))
	{
		ft_lstclear(start_lines_list, free);
		return (1);
	}
	map->x_size = get_x_size(*start_lines_list);
	if (map->x_size == 0)
	{
		ft_lstclear(start_lines_list, free);
		return (2);
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
	if (part1(map, &start_lines_list, fd))
		return (1);
	map->size = map->x_size * map->y_size;
	map->vertices = malloc(sizeof(t_vec3) * (map->x_size * map->y_size));
	if (map->vertices == NULL)
	{
		free(map->vertices);
		ft_lstclear(&start_lines_list, free);
		return (3);
	}
	parse_lines(&start_lines_list, map);
	return (0);
}
