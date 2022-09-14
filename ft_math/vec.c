/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjungo <qjungo@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 12:35:34 by qjungo            #+#    #+#             */
/*   Updated: 2022/10/27 12:39:37 by qjungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "ft_math.h"

int	assert_rounded_vec2(t_vec2 a, t_vec2 b) // variadic ??
{
	return ((round(a.x) == round(b.x)) && (round(a.y) == round(b.y)));
}
