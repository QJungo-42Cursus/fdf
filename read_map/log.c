/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjungo <qjungo@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 10:09:21 by qjungo            #+#    #+#             */
/*   Updated: 2022/10/26 12:58:41 by qjungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../libft/libft.h"
#include"../fdf.h"

void	log_final_map(t_map map)
{
	int		y;
	int		x;
	
	ft_printf("\n");
	y = 0;
	while (y < map.y_size)
	{
		x = 0;
		while (x < map.x_size)
		{
			ft_printf("%i ", map.points[y][x]);
			x++;
		}
		ft_printf("\n");
		y++;
	}
}

void	log_print_map(t_list *start_lines_list, t_map map)
{
	t_list	*ptr;

	ft_printf("X %i // Y %i \n", map.x_size, map.y_size);
	ptr = start_lines_list;
	while (ptr)
	{
		int i = 0;
		int	*val = (int *)ptr->content;
		while (i < map.x_size)
		{
			ft_printf("%i ", val[i]);
			i++;
		}
		ft_printf("\n");
		ptr = ptr->next;
	}
}
