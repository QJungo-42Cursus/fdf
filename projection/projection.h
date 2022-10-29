/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjungo <qjungo@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 19:18:21 by qjungo            #+#    #+#             */
/*   Updated: 2022/10/29 00:24:33 by qjungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECTION_H
# define PROJECTION_H

#include "../ft_math/ft_math.h"
#include "../fdf.h"

t_matrix	iso_matrix(float alpha, float beta);
t_vec2		*projection(t_map *map);

#endif /* PROJECTION_H */
