/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjungo <qjungo@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 10:17:02 by qjungo            #+#    #+#             */
/*   Updated: 2022/11/01 22:20:23 by qjungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../vec/vec.h"
#include "../ft_math.h"

float  deg_to_rad(float deg)
{
	return (deg * M_PI / 180);
}

float  rad_to_deg(float rad)
{
	return (rad * 180 / M_PI);
}


t_vec3 rotation_x(t_vec3 point, float angle)
{
	t_matrix	rotation_matrix;
	t_matrix	n_point;
	t_vec3		res;

	t_vec3	b;

	b.x = point.x;

	b.y = point.y * cos(angle) + point.z * sin(angle);
	b.z = (-point.y) * sin(angle) + point.z * cos(angle);

	(void)b;

	angle = deg_to_rad(angle);
	rotation_matrix = init_matrix(3, 3);
	rotation_matrix.self[0][0] = 1;
	rotation_matrix.self[0][1] = 0;
	rotation_matrix.self[0][2] = 0;
	rotation_matrix.self[1][0] = 0;
	rotation_matrix.self[1][1] = cos(angle);
	rotation_matrix.self[1][2] = -sin(angle);
	rotation_matrix.self[2][0] = 0;
	rotation_matrix.self[2][1] = sin(angle);
	rotation_matrix.self[2][2] = cos(angle);
	n_point = matrix_product(rotation_matrix, vec3_to_matrix(point));
	res = matrix_to_vec3(n_point);
	free_matrix(n_point);
	free_matrix(rotation_matrix);
	return (res);
}

t_vec3	rotation_z(t_vec3 a, float angle)
{
	t_vec3	b;

	b.x = a.x * cos(angle) - a.y * sin(angle);
	b.y = a.x * sin(angle) + a.y * cos(angle);
	b.z = a.z;
	return (b);
}

void	rotation_3d(t_vec3 *points, int length, float angle, char axe)
{
	int		i;

	i = 0;
	while (i < length)
	{
		if (axe == 'z')
			points[i] = rotation_z(points[i], angle);
		if (axe == 'x')
			points[i] = rotation_x(points[i], angle);
		i++;
	}
}

//	TODO a sa place ici ?
void	map_scale(t_vec2 *points, int length, float scale)
{
	int	i;

	i = 0;
	while (i < length)
	{
		points[i].x *= scale;
		points[i].y *= scale;
		i++;
	}
}
