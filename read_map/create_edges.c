/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_edges.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjungo <qjungo@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 13:36:17 by qjungo            #+#    #+#             */
/*   Updated: 2022/11/09 11:06:45 by qjungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../fdf.h"

int	create_edges(t_map *map)
{
	int		i_edge;
	int		i_vert;

	map->n_edges = 2 * map->size.x * map->size.y - map->size.x - map->size.y;
	map->edges = malloc(sizeof(t_edge) * (map->n_edges));
	if (map->edges == NULL)
		return (1);
	i_edge = 0;
	i_vert = 0;
	while (i_edge < map->n_edges)
	{
		if (i_vert == 0 || ((i_vert + 1) % (int)map->size.x != 0))
			map->edges[i_edge++] = new_edge(i_vert, i_vert + 1);
		if (i_vert == 0
			|| ((i_vert + 1) <= (int)map->size.x * (map->size.y - 1)))
			map->edges[i_edge++] = new_edge(i_vert, i_vert + map->size.x);
		i_vert++;
	}
	return (0);
}
