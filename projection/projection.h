/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjungo <qjungo@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 19:18:21 by qjungo            #+#    #+#             */
/*   Updated: 2022/11/02 15:58:52 by qjungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECTION_H
# define PROJECTION_H
# include "../fdf.h"

void	projection(t_map *map, t_view view);
void	display(t_map *map);
int		render_next_frame(t_all *all);

#endif /* PROJECTION_H */
