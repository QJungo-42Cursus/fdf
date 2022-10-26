/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjungo <qjungo@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:23:49 by qjungo            #+#    #+#             */
/*   Updated: 2022/10/26 16:24:45 by qjungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_H
# define FT_MATH_H

typedef struct	s_vec2 {
	int	x;
	int	y;
}	t_vec2;

float	slope(t_vec2 a, t_vec2 b);
float	ordonnate_to_origin(float x, float y, float m);
t_vec2	new_vec2(int x, int y);

#endif /* FT_MATH_H */
