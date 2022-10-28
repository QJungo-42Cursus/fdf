/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjungo <qjungo@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 13:21:12 by qjungo            #+#    #+#             */
/*   Updated: 2022/10/28 14:03:50 by qjungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

t_vertice	new_vertice(t_vec3 position)
{
	t_vertice	n;

	n.position = position;
	n.projection = new_vec2(position.x, position.y);
	return (n);
}

t_edge	new_edge(t_vertice *a, t_vertice *b)
{
	t_edge	n;

	n.a = a;
	n.b = b;
	return (n);
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
