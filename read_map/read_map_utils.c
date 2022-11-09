/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjungo <qjungo@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 09:57:22 by qjungo            #+#    #+#             */
/*   Updated: 2022/11/09 12:28:25 by qjungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "read_map.h"
#include "../fdf.h"
#include "../libft/libft.h"

int	highest_in_the_room(t_vec3 *vertices, int xy_size)
{
	int		lowest;
	int		i;

	lowest = INT_MIN;
	i = 0;
	while (i < xy_size)
	{
		if (vertices[i].z > lowest)
			lowest = vertices[i].z;
		i++;
	}
	return (lowest);
}

int	lowest_in_the_room(t_vec3 *vertices, int xy_size)
{
	int		lowest;
	int		i;

	lowest = INT_MAX;
	i = 0;
	while (i < xy_size)
	{
		if (vertices[i].z < lowest)
			lowest = vertices[i].z;
		i++;
	}
	return (lowest);
}

void	elevate_to_zero(t_vec3 *vertices, int xy_size)
{
	int		i;
	int		lowest;

	lowest = lowest_in_the_room(vertices, xy_size);
	i = 0;
	while (i < xy_size)
	{
		vertices[i].z -= lowest;
		i++;
	}
}

int	get_x_size(t_list *line)
{
	char	**words;
	int		size;

	words = ft_split((char *)line->content, ' ');
	if (words == NULL)
		return (0);
	size = 0;
	while (words[size] && words[size][0] != '\n')
	{
		free(words[size]);
		size++;
	}
	free(words[size]);
	free(words);
	return (size);
}
