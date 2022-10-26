/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjungo <qjungo@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 11:35:13 by qjungo            #+#    #+#             */
/*   Updated: 2022/10/26 16:25:45 by qjungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_math/ft_math.h"

float	slope(t_vec2 a, t_vec2 b)
{
	return ((b.y - a.y) / (b.x - a.x));
}

float	ordonnate_to_origin(float x, float y, float m)
{
	return (y - m * x);
}

t_vec2	new_vec2(int x, int y)
{
	t_vec2	new;

	new.x = x;
	new.y = y;
	return (new);
}
