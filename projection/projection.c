/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjungo <qjungo@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 23:21:13 by qjungo            #+#    #+#             */
/*   Updated: 2022/11/02 14:54:38 by qjungo           ###   ########.fr       */
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
	static float	last_z = 0;
	static float	last_x = 0;
	t_vec2			*proj;

	rotation_3d(map->vertices, map->size, -last_x, 'x');
	if (last_z != view.angle.z)
		rotation_3d(map->vertices, map->size, last_z, 'z');
	if (last_z != view.angle.z)
		rotation_3d(map->vertices, map->size, view.angle.z, 'z');
	rotation_3d(map->vertices, map->size, view.angle.x, 'x');
	last_x = view.angle.x;
	last_z = view.angle.z;

	// TODO free le proj ??
	if (view.perspective)
	{
		proj = perspective(map->vertices, map->size, view);
		map_scale(proj, map->size, view.scale * view.distance);
	}
	else
	{
		proj = copy_vec3_list_to2(map->vertices, map->size);
		map_scale(proj, map->size, view.scale);
	}
	translation_2d(proj, map->size, view.mov);
	return (proj);
}
