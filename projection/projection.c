/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjungo <qjungo@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 23:21:13 by qjungo            #+#    #+#             */
/*   Updated: 2022/11/01 15:24:46 by qjungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#include "projection.h"
#include <math.h>
#include <stdlib.h>




/*
t_vec3	*projection(t_map *map)
{
	t_vec2		*res;
	//t_matrix	iso;
	t_matrix	point;
	//t_matrix	new_p;
	int			i;

	res = malloc(sizeof(t_vec2) * (map->x_size * map->y_size));
	if (res == NULL)
		return (NULL);


	//iso = iso_matrix(asin(tan(deg_to_rad(30))), 45);
	//log_matrix(iso);


	i = 0;
	while (i < map->x_size * map->y_size)
	{
		point = vec3_to_matrix(map->vertices[i]);
		if (point.self == NULL)
			return (NULL);
		//new_p = matrix_product(iso, point);
		//log_matrix(new_p);
		//res[i] = new_vec2(0, 0);
		//res[i] = new_vec2(new_p.self[0][0]+dec, new_p.self[1][0]+dec);
		res[i] = new_vec2(point.self[0][0], point.self[1][0]);
		//log_vec2(res[i]);
		i++;
	}

	return (res);
}
*/
