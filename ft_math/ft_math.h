/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjungo <qjungo@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:23:49 by qjungo            #+#    #+#             */
/*   Updated: 2022/11/01 12:10:57 by qjungo           ###   ########.fr       */
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


///		edge (arrete) lie deux sommets qu'on va lier pour dessiner un trait
///		Se base sur l'index du tableau de sommets 
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
	int		x; // TODO change to width
	int		y; // TODO change to width
	float	**self;
}	t_matrix;

//			line.c
float		slope(t_vec2 a, t_vec2 b);
float		ordonnate_to_origin(float x, float y, float m);

//			geometrie.c
float		distance(t_vec2 a, t_vec2 b);
float		deg_to_rad(float deg);
float		rad_to_deg(float rad);
t_vec2		pos_from_distance(t_vec2 a, float distance, float angle);
void map_rotation_x(t_vec3 *points, int length, float angle);
void map_rotation_y(t_vec3 *points, int length, float angle);
void map_rotation_z(t_vec3 *points, int length, float angle);
void	map_scale(t_vec2 *points, int length, float scale);

//			matrix.c
t_matrix	new_matrix(float **matrix, int x, int y);
t_matrix	init_matrix(int x, int y);
void		free_matrix(t_matrix matrix);
t_matrix	matrix_addition(t_matrix a, t_matrix b);
t_vec2		matrix_to_vec2(t_matrix matrix);
t_vec3		matrix_to_vec3(t_matrix matrix);
t_matrix	vec3_to_matrix(t_vec3 vec);
t_matrix	vec2_to_matrix(t_vec2 vec);
t_matrix	matrix_product(t_matrix a, t_matrix b);
t_matrix	matrix_product_scal(t_matrix a, float scal);
void		log_matrix(t_matrix m);

//			new.c
t_edge		new_edge(int a, int b);

//			vec.c
t_vec2	*copy_vec3_to2(t_vec3 *src, int size);
t_vec2		new_vec2(float x, float y);
t_vec3		new_vec3(float x, float y, float z);
t_vec3		vec2_to3(t_vec2 v);
t_vec2		vec3_to2(t_vec3 v);
int			assert_rounded_vec2(t_vec2 a, t_vec2 b);
void		log_vec3(t_vec3 v);
void		log_vec2(t_vec2 v);
t_vec3	*copy_vec3(t_vec3 *src, int size);

//			translation.c
void		translation_2d(t_vec2 *vertices, int length, t_vec2 vec);
void		translation_3d(t_vec3 *vertices, int length, t_vec3 vec);

#endif /* FT_MATH_H */
