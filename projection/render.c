/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjungo <qjungo@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:06:10 by qjungo            #+#    #+#             */
/*   Updated: 2022/11/09 09:47:46 by qjungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#include "../minilibx_macos/mlx.h"
#include "projection.h"

static void	disp_edges(t_map *map, t_img_data *img)
{
	int		i;
	t_line	line;

	i = 0;
	while (i < map->n_edges)
	{
		line = new_line(map->proj[map->edges[i].a],
				map->proj[map->edges[i].b], 0x00FF6550, 2);
		draw_line(img, line);
		i++;
	}
}

void	clean_edges(t_vec2 *vertices,
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

void	background(t_img_data *img, int color)
{
	int		x;
	int		y;

	y = 0;
	while (y < img->y_size)
	{
		x = 0;
		while (x < img->x_size)
		{
			pixel_to_image(img, new_vec2(x, y), color);
			x++;
		}
		y++;
	}
}

int	render_next_frame(t_all *all)
{
	static int	last_img = 0;
	int			next_img;

	if (last_img == IMG_BUFF)
		last_img = 0;
	next_img = last_img + 1;
	if (next_img == IMG_BUFF)
		next_img = 0;
	clean_edges(all->map->proj, all->map->edges,
		all->map->n_edges, &all->imgs[last_img]);
	projection(all->map, *all->view);
	disp_edges(all->map, &all->imgs[next_img]);
	mlx_put_image_to_window(all->mlx->self,
		all->mlx->win, all->imgs[next_img].img, 0, 0);
	last_img++;
	return (0);
}
