/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_edges.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjungo <qjungo@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 13:36:17 by qjungo            #+#    #+#             */
/*   Updated: 2022/10/28 16:05:45 by qjungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../fdf.h"
#include "../ft_math/ft_math.h"

int	create_edges(t_map *map)
{
	int		i_edge;
	int		i_vert;

	map->n_edges = 2 * map->x_size * map->y_size - map->x_size - map->y_size;
	map->edges = malloc(sizeof(t_edge) * (map->n_edges));
	if (map->edges == NULL)
		return (1);
	i_edge = 0;
	i_vert = 0;
	while (i_edge < map->n_edges)
	{
		if (i_vert == 0 || ((i_vert + 1) % map->x_size != 0))
			map->edges[i_edge++] = new_edge(
					&(map->vertices[i_vert]),
					&(map->vertices[i_vert + 1])); 
		if (i_vert == 0 || ((i_vert + 1) <= map->x_size * (map->y_size - 1)))
			map->edges[i_edge++] = new_edge(
					&(map->vertices[i_vert]),
					&(map->vertices[i_vert + map->x_size])); 
		i_vert++;
	}
	return (0);
}
