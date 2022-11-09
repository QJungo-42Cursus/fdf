/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjungo <qjungo@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 13:12:06 by qjungo            #+#    #+#             */
/*   Updated: 2022/11/09 16:15:11 by qjungo           ###   ########.fr       */
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
	t_vec3		size;
	int			xy_size;
	t_vec3		*vertices;	
	t_vec2		*proj;
	t_edge		*edges;
	int			n_edges;
}	t_map;

typedef struct s_all {
	t_map		*map;
	t_view		*view;
	t_img_data	*img;
	t_mlx		*mlx;
	//t_bool		is_running;
}	t_all;

void	terminate(char *s);

#endif /* FDF_H */
