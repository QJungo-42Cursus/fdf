/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjungo <qjungo@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 11:09:28 by qjungo            #+#    #+#             */
/*   Updated: 2022/11/09 17:52:44 by qjungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_map.h"
#include "../fdf.h"
#include "../libft/libft.h"

int	get_lines(int fd, t_list **start_lines_list, t_map *map)
{
	t_list	*new_node;
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		new_node = ft_lstnew((void *)line);
		if (new_node == NULL)
		{
			ft_lstclear(start_lines_list, free);
			return (1);
		}
		ft_lstadd_back(start_lines_list, new_node);
		map->size.y++;
	}
	return (0);
}

static int	line_to_vertices(char ***words, t_map *map, int *i, int y)
{
	int		x;

	x = 0;
	while ((*words)[x] && (*words)[x][0] != '\n')
	{
		map->vertices[*i] = new_vec3(x, y, ft_atoi((*words)[x]));
		map->vertices[*i] = new_vec3(x, y, ft_atoi((*words)[x]));
		free((*words)[x]);
		x++;
		(*i)++;
	}
	free((*words)[x]);
	free(*words);
	return (0);
}

static int	words_n(char **words)
{
	int		len;

	len = 0;
	while (words[len] != NULL)
		len++;
	if (words[len - 1][0] == '\n')
		len--;
	return (len);
}

int	parse_lines(t_list **start_lines_list, t_map *map)
{
	t_list	*node;
	t_list	*l_node;
	char	**words;
	int		y;
	int		i;

	node = *start_lines_list;
	i = 0;
	y = 0;
	while (node)
	{
		words = ft_split((char *)node->content, ' ');
		if (words == NULL || words_n(words) != (int)map->size.x)
		{
			i = 0;
			while (words[i])
				free(words[i++]);
			free(words);
			ft_lstclear(&node, free);
			return (1);
		}
		line_to_vertices(&words, map, &i, y);
		y++;
		l_node = node;
		node = node->next;
		free(l_node->content);
		free(l_node);
	}
	return (0);
}
