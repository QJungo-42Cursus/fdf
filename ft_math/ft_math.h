/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjungo <qjungo@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:23:49 by qjungo            #+#    #+#             */
/*   Updated: 2022/10/28 13:23:42 by qjungo           ###   ########.fr       */
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

///		chaque sommet a deux inform
typedef struct	s_vertice {
	t_vec3	position;	// vrai position
	t_vec2	projection;	// position apres projection en 2d
}	t_vertice;

///		edge (arrete) lie deux sommets qu'on va lier pour dessiner un trait
typedef struct	s_edge {
	t_vertice	*a;
	t_vertice	*b;
}	t_edge;

float		slope(t_vec2 a, t_vec2 b);
int			assert_rounded_vec2(t_vec2 a, t_vec2 b);
float		ordonnate_to_origin(float x, float y, float m);

t_vertice	new_vertice(t_vec3 position);
t_edge		new_edge(t_vertice *a, t_vertice *b);
t_vec2		new_vec2(float x, float y);
t_vec3		new_vec3(float x, float y, float z);

#endif /* FT_MATH_H */
