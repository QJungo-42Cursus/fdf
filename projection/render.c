/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjungo <qjungo@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:06:10 by qjungo            #+#    #+#             */
/*   Updated: 2022/11/02 13:29:59 by qjungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#include "../minilibx_macos/mlx.h"
#include "projection.h"

static void	disp_edges(t_vec2 *vertices,
		t_edge *edges, int n_edges, t_img_data *img)
{
	int		i;
	t_line	line;

	i = 0;
	while (i < n_edges)
	{
		line = new_line(vertices[edges[i].a],
				vertices[edges[i].b], 0x00FF6550, 2);
		draw_line(img, line);
		i++;
	}
}

static void	clean_edges(t_vec2 *vertices,
		t_edge *edges, int n_edges, t_img_data *img)
{
	int		i;
	t_line	line;

	i = 0;
	while (i < n_edges)
	{
		line = new_line(vertices[edges[i].a],
				vertices[edges[i].b], 0x00000000, 0);
		draw_line(img, line);
		i++;
	}
}

/*
static void	render_background(t_img_data *img, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < img->y_size)
	{
		j = 0;
		while (j < img->x_size)
		{
			pixel_to_image(img, new_vec2(j++, i), color);
		}
		++i;
	}
}
*/

int	render_next_frame(t_all *all)
{
	static t_vec2	*proj = NULL;

	if (proj != NULL)
	{
		clean_edges(proj, all->map->edges, all->map->n_edges, all->img);
		free(proj);
	}

	//render_background(all->img, 0x00000000);
	proj = projection(all->map, *all->view);
	disp_edges(proj, all->map->edges, all->map->n_edges, all->img);
	mlx_put_image_to_window(all->mlx->self, all->mlx->win, all->img->img, 0, 0);
	//free(proj);
	return (0);
}
