/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjungo <qjungo@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:23:49 by qjungo            #+#    #+#             */
/*   Updated: 2022/11/01 14:56:42 by qjungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_H
# define FT_MATH_H

# include "vec/vec.h"
# include "matrix/matrix.h"
# include "geometrie/geometrie.h"

typedef struct s_droite{
	float	m;
	float	b;
	// TODO utiles ?
	float	x;
	float	y;
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



//			new.c
t_edge		new_edge(int a, int b);



#endif /* FT_MATH_H */

// TODO pas ici...
void		log_matrix(t_matrix m);
void		log_vec3(t_vec3 v);
void		log_vec2(t_vec2 v);
