/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjungo <qjungo@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 09:57:22 by qjungo            #+#    #+#             */
/*   Updated: 2022/11/22 11:29:24 by qjungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "read_map.h"
#include "../fdf.h"
#include "../libft/libft.h"

static int	clean_return(t_list **l, int e)
{
	ft_lstclear(l, free);
	return (e);
}

static int	part1(t_map *map, t_list **start_lines_list,
		int fd)
{
	map->size.x = 0;
	map->size.y = 0;
	map->size.z = 0;
	*start_lines_list = NULL;
	if (get_lines(fd, start_lines_list, map))
	{
		ft_lstclear(start_lines_list, free);
		return (1);
	}
	map->size.x = get_x_size(*start_lines_list);
	if (map->size.x == 0)
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
	close(fd);
	map->xy_size = map->size.x * map->size.y;
	map->vertices = malloc(sizeof(t_vec3) * map->xy_size);
	if (map->vertices == NULL)
		clean_return(&start_lines_list, 3);
	map->proj = malloc(sizeof(t_vec2) * map->xy_size);
	if (map->proj == NULL)
		clean_return(&start_lines_list, 3);
	if (parse_lines(&start_lines_list, map, 0, 0))
	{
		free(map->vertices);
		free(map->proj);
		return (5);
	}
	elevate_to_zero(map->vertices, map->xy_size);
	map->size.z = highest_in_the_room(map->vertices, map->xy_size);
	return (0);
}
