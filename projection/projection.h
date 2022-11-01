/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjungo <qjungo@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 19:18:21 by qjungo            #+#    #+#             */
/*   Updated: 2022/11/01 15:23:52 by qjungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECTION_H
# define PROJECTION_H
# include "../fdf.h"

t_matrix	iso_matrix(float alpha, float beta);
t_vec2		*projection(t_map *map);
void		display(t_map *map);

#endif /* PROJECTION_H */
