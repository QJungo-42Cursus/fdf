/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjungo <qjungo@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:23:49 by qjungo            #+#    #+#             */
/*   Updated: 2022/10/27 13:00:04 by qjungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_H
# define FT_MATH_H

typedef struct	s_vec2 {
	float	x;
	float	y;
}	t_vec2;

typedef struct	s_vec3 {
	float	x;
	float	y;
	float	z;
}	t_vec3;

typedef struct s_droite{
	float	m;
	float	b;
	// n'est pas mathematiquement vraiment a sa place ici mais bon...
	// (c'est la vitesse a laquelle j'avance)
	float	move_factor;
}	t_droite;


float	slope(t_vec2 a, t_vec2 b);
float	ordonnate_to_origin(float x, float y, float m);
t_vec2	new_vec2(float x, float y);
t_vec3	new_vec3(float x, float y, float z);
int		assert_rounded_vec2(t_vec2 a, t_vec2 b);

#endif /* FT_MATH_H */
