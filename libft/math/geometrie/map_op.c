/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjungo <qjungo@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 10:17:02 by qjungo            #+#    #+#             */
/*   Updated: 2022/11/01 14:29:45 by qjungo           ###   ########.fr       */
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

t_vec3	rotation_z(t_vec3 point, float angle)
{
	t_matrix	rotation_matrix;
	t_matrix	n_point;
	t_vec3		res;

	angle = deg_to_rad(angle);
	rotation_matrix = init_matrix(3, 3);
	rotation_matrix.self[0][0] = cos(angle);
	rotation_matrix.self[0][1] = -sin(angle);
	rotation_matrix.self[0][2] = 0;
	rotation_matrix.self[1][0] = sin(angle);
	rotation_matrix.self[1][1] = cos(angle);
	rotation_matrix.self[1][2] = 0;
	rotation_matrix.self[2][0] = 0;
	rotation_matrix.self[2][1] = 0;
	rotation_matrix.self[2][2] = 1;
	n_point = matrix_product(rotation_matrix, vec3_to_matrix(point));
	res = matrix_to_vec3(n_point);
	free_matrix(n_point);
	free_matrix(rotation_matrix);
	return (res);
}

t_vec3 rotation_y(t_vec3 point, float angle)
{
	t_matrix	rotation_matrix;
	t_matrix	n_point;
	t_vec3		res;

	angle = deg_to_rad(angle);
	rotation_matrix = init_matrix(3, 3);
	rotation_matrix.self[0][0] = cos(angle);
	rotation_matrix.self[0][1] = 0;
	rotation_matrix.self[0][2] = sin(angle);
	rotation_matrix.self[1][0] = 0;
	rotation_matrix.self[1][1] = 1;
	rotation_matrix.self[1][2] = 0;
	rotation_matrix.self[2][0] = -sin(angle);
	rotation_matrix.self[2][1] = 0;
	rotation_matrix.self[2][2] = cos(angle);
	n_point = matrix_product(rotation_matrix, vec3_to_matrix(point));
	res = matrix_to_vec3(n_point);
	free_matrix(n_point);
	free_matrix(rotation_matrix);
	return (res);
}
t_vec3 rotation_x(t_vec3 point, float angle)
{
	t_matrix	rotation_matrix;
	t_matrix	n_point;
	t_vec3		res;

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
// vector rotation
/*
 * TODO de quel axe part la rotation ?
t_vec2	rotate_vec2(t_vec2 a, float angle)
{
	t_vec2	b;

	b.x = a.x * cos(angle) - a.y * sin(angle);
	b.y = a.x * sin(angle) + a.y * cos(angle);
	return (b);
}
*/

void	vec3_foreach(t_vec3 *a, int length, t_vec3 (*f)(t_vec3))
{
	int		i;

	i = 0;
	while (i < length)
	{
		a[i] = f(a[i]);
		i++;
	}
}

void	vec2_foreach(t_vec2 *a, int length, t_vec2 (*f)(t_vec2))
{
	int		i;

	i = 0;
	while (i < length)
	{
		a[i] = f(a[i]);
		i++;
	}
}

void	map_rotation_z(t_vec3 *points, int length, float angle)
{
	int		i;

	i = 0;
	while (i < length)
	{
		points[i] = rotation_z(points[i], angle);
		i++;
	}
}

void map_rotation_y(t_vec3 *points, int length, float angle)
{
	int		i;

	i = 0;
	while (i < length)
	{
		points[i] = rotation_y(points[i], angle);
		i++;
	}
}

void map_rotation_x(t_vec3 *points, int length, float angle)
{
	int		i;

	i = 0;
	while (i < length)
	{
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
