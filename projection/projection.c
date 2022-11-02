/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjungo <qjungo@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 23:21:13 by qjungo            #+#    #+#             */
/*   Updated: 2022/11/02 15:55:46 by qjungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#include "projection.h"
#include <math.h>
#include <stdlib.h>

static void	perspective(t_map *map, t_view view)
{
	float	z;
	int		i;

	i = 0;
	while (i < map->size)
	{
		z = 1 / (view.distance - map->vertices[i].z);
		map->proj[i] = new_vec2(map->vertices[i].x * z, map->vertices[i].y * z);
		i++;
	}
}

void	projection(t_map *map, t_view view)
{
	static float	last_z = 0;
	static float	last_x = 0;

	rotation_3d(map->vertices, map->size, -last_x, 'x');
	if (last_z != view.angle.z)
		rotation_3d(map->vertices, map->size, last_z, 'z');
	if (last_z != view.angle.z)
		rotation_3d(map->vertices, map->size, view.angle.z, 'z');
	rotation_3d(map->vertices, map->size, view.angle.x, 'x');
	last_x = view.angle.x;
	last_z = view.angle.z;
	if (view.perspective)
	{
		perspective(map, view);
		map_scale(map->proj, map->size, view.scale * view.distance);
	}
	else
	{
		copy_vec3_list_to2(map->vertices, map->size, map->proj);
		map_scale(map->proj, map->size, view.scale);
	}
	translation_2d(map->proj, map->size, view.mov);
}
