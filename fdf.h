/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjungo <qjungo@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 13:12:06 by qjungo            #+#    #+#             */
/*   Updated: 2022/10/28 23:09:25 by qjungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include"ft_math/ft_math.h"

typedef struct s_map {
	int			x_size;
	int			y_size;
	t_vec3		*vertices;	
	t_edge		*edges;
	int			n_edges;
}	t_map;

#endif /* FDF_H */
