/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjungo <qjungo@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 13:12:06 by qjungo            #+#    #+#             */
/*   Updated: 2022/11/01 20:03:03 by qjungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft/libft.h"

typedef struct s_view {
	t_vec3	angle;
	t_vec2	mov;
	float	scale;
	t_bool	perspective;
	float	distance;
}	t_view;

typedef struct s_map {
	int			x_size;
	int			y_size;
	int			size;
	t_vec3		*vertices;	
	t_edge		*edges;
	int			n_edges;
}	t_map;

typedef struct s_all {
	t_map		*map;
	t_view		*view;
	t_img_data	*img;
	t_mlx		*mlx;
}	t_all;

#endif /* FDF_H */
