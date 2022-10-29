/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjungo <qjungo@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 23:21:13 by qjungo            #+#    #+#             */
/*   Updated: 2022/10/29 16:39:18 by qjungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../ft_math/ft_math.h"
#include "../fdf.h"
#include "projection.h"
#include <math.h>
#include <stdlib.h>

//static int	init_point(

t_vec2	*projection(t_map *map)
{
	t_vec2		*res;
	t_matrix	iso;
	t_matrix	point;
	t_matrix	new_p;
	int			i;

	res = malloc(sizeof(t_vec2) * (map->x_size * map->y_size));
	if (res == NULL)
		return (NULL);
	float dg_rad = 30 * 2 * PI / 360;
	iso = iso_matrix(asin(tan(dg_rad)) * 360 / (PI * 2), 45);
	point.x = 1;
	point.y = 3;
	// TODO check malloc
	point.self = malloc(sizeof(float *) * 3);
	point.self[0] = malloc(sizeof(float));
	point.self[1] = malloc(sizeof(float));
	point.self[2] = malloc(sizeof(float));
	log_matrix(iso);
	i = 0;


	int	dec = 7;
	while (i < map->x_size * map->y_size)
	{
		point.self[0][0] = map->vertices[i].x;
		point.self[1][0] = map->vertices[i].y;
		point.self[2][0] = map->vertices[i].z;
		new_p = matrix_product(iso, point);
		log_matrix(new_p);
		res[i] = new_vec2(0, 0);
		res[i] = new_vec2(new_p.self[0][0]+dec, new_p.self[1][0]+dec);
		log_vec2(res[i]);
		i++;
	}

	return (res);
}
