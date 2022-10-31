/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometrie.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjungo <qjungo@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 10:17:02 by qjungo            #+#    #+#             */
/*   Updated: 2022/10/31 10:51:55 by qjungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "ft_math.h"

// Grace au théorème de Pythagore,
// on peut calculer la distance entre deux points
float  distance(t_vec2 a, t_vec2 b)
{
	return (sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2)));
}

t_vec2	pos_from_distance(t_vec2 a, float distance, float angle)
{
	t_vec2	b;

	return (b);
}

// degree to radian
float  deg_to_rad(float deg)
{
	return (deg * M_PI / 180);
}

// radian to degree
float  rad_to_deg(float rad)
{
	return (rad * 180 / M_PI);
}
