/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjungo <qjungo@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 11:08:46 by qjungo            #+#    #+#             */
/*   Updated: 2022/11/22 11:28:21 by qjungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_MAP_H
# define READ_MAP_H

# include"../libft/libft.h"
# include"../fdf.h"

int		read_map(const char *path, t_map *map);
int		create_edges(t_map *map);

int		parse_lines(t_list **start_lines_list, t_map *map, int i, int y);
//int		line_to_vertices(char ***words, t_map *map, int *i, int y);
int		get_lines(int fd, t_list **start_lines_list, t_map *map);
int		get_x_size(t_list *line);

void	elevate_to_zero(t_vec3 *vertices, int xy_size);
int		lowest_in_the_room(t_vec3 *vertices, int xy_size);
int		highest_in_the_room(t_vec3 *vertices, int xy_size);

#endif /* READ_MAP_H */
