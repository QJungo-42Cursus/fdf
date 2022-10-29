/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjungo <qjungo@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 12:35:34 by qjungo            #+#    #+#             */
/*   Updated: 2022/10/29 00:35:34 by qjungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "ft_math.h"

int	assert_rounded_vec2(t_vec2 a, t_vec2 b) // variadic ??
{
	return ((round(a.x) == round(b.x)) && (round(a.y) == round(b.y)));
}

t_vec2	new_vec2(float x, float y)
{
	t_vec2	n;

	n.x = x;
	n.y = y;
	return (n);
}

t_vec3	new_vec3(float x, float y, float z)
{
	t_vec3	n;

	n.x = x;
	n.y = y;
	n.z = z;
	return (n);
}

t_vec2	vec3_to2(t_vec3 v)
{
	t_vec2	n;

	n.x = v.x;
	n.y = v.y;
	return (n);
}

#include <stdio.h>
void	log_vec3(t_vec3 v)
{
	printf("Position : {%f, %f, %f}\n", v.x, v.y, v.z);
}

void	log_vec2(t_vec2 v)
{
	printf("{%f, %f}\n", v.x, v.y);
}
