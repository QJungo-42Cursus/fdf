/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjungo <qjungo@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 11:35:13 by qjungo            #+#    #+#             */
/*   Updated: 2022/10/28 15:16:49 by qjungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_math/ft_math.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

float	slope(t_vec2 a, t_vec2 b)
{
	float	m;

	m = (b.y - a.y) / (b.x - a.x);
	return (m);
}

float	ordonnate_to_origin(float x, float y, float m)
{
	float	b;

	if (isinf(m))
		return (x); // TODO c'est faux mathematiquemetn ..
	b = y - m * x;
	if (isnan(b))
	{
		printf("is nan ! %f - %f * %f", y, m, x);
		//exit(4);
		b = 0;
	}
	return (b);
}

