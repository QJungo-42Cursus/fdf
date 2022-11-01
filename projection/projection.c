/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjungo <qjungo@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 23:21:13 by qjungo            #+#    #+#             */
/*   Updated: 2022/11/01 22:17:32 by qjungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#include "projection.h"
#include <math.h>
#include <stdlib.h>

static t_vec2	*perspective(t_vec3 *vertices, int size, t_view view)
{
	t_vec2	*proj;
	float	z;
	int		i;

	proj = malloc(sizeof(t_vec2) * size);
	if (proj == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		z = 1 / (view.distance - vertices[i].z);
		proj[i] = new_vec2(vertices[i].x * z, vertices[i].y * z);
		i++;
	}
	return (proj);
}

t_vec2	*projection(t_map *map, t_view view)
{
	t_vec3		*map_copy;
	t_vec2		*proj;

	map_copy = copy_vec3_list(map->vertices, map->size);
	rotation_3d(map_copy, map->size, view.angle.z, 'z');
	rotation_3d(map_copy, map->size, view.angle.x, 'x');
	if (view.perspective)
	{
		proj = perspective(map_copy, map->size, view);
		map_scale(proj, map->size, view.scale * view.distance);
	}
	else
	{
		proj = copy_vec3_list_to2(map_copy, map->size);
		map_scale(proj, map->size, view.scale);
	}
	translation_2d(proj, map->size, view.mov);
	free(map_copy);
	return (proj);
}
