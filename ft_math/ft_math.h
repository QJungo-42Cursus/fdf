/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjungo <qjungo@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:23:49 by qjungo            #+#    #+#             */
/*   Updated: 2022/10/29 09:30:02 by qjungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_H
# define FT_MATH_H

#define PI 3.141592654

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


///		edge (arrete) lie deux sommets qu'on va lier pour dessiner un trait
///		Ce base sur l'index...
typedef struct	s_edge {
	int	a;
	int	b;
}	t_edge;

///		taille en x et y de la matrice
///		et un pointeur sur int** -> parceque de toute facon, c'est en 2d
///		{
///			[1, 2, 3],
///			[1, 3, 4],
///			[4, 5, 2]
///		}	
typedef struct	s_matrix {
	int		x;
	int		y;
	float	**self;
}	t_matrix;

float		slope(t_vec2 a, t_vec2 b);
int			assert_rounded_vec2(t_vec2 a, t_vec2 b);
float		ordonnate_to_origin(float x, float y, float m);
t_matrix	matrix_product(t_matrix a, t_matrix b);

t_vec2	vec3_to2(t_vec3 v);

t_matrix	new_matrix(float **matrix, int x, int y);
t_edge		new_edge(int a, int b);
t_vec2		new_vec2(float x, float y);
t_vec3		new_vec3(float x, float y, float z);

void		log_matrix(t_matrix m);
void	log_vec3(t_vec3 v);
void	log_vec2(t_vec2 v);

#endif /* FT_MATH_H */
