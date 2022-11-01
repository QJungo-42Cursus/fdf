/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjungo <qjungo@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 19:18:21 by qjungo            #+#    #+#             */
/*   Updated: 2022/11/01 16:16:42 by qjungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECTION_H
# define PROJECTION_H
# include "../fdf.h"

typedef struct s_view {
	t_vec3	angle;
	t_vec2	mov;
	float	scale;
	t_bool	perspective;
	float	distance;
}	t_view;

t_matrix	iso_matrix(float alpha, float beta);
t_vec2		*projection(t_map *map, t_view view);
void		display(t_map *map);

#endif /* PROJECTION_H */
