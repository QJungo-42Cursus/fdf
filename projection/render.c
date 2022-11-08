/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjungo <qjungo@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:06:10 by qjungo            #+#    #+#             */
/*   Updated: 2022/11/08 23:14:00 by qjungo           ###   ########.fr       */
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
	while(y < img->y_size)
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
	// TODO avoir plusieurs images prete a switch une a une ??
	//background(all->img, 0x00FFFF00);
	clean_edges(all->map->proj, all->map->edges, all->map->n_edges, all->img);
	projection(all->map, *all->view);
	disp_edges(all->map, all->img);
	mlx_put_image_to_window(all->mlx->self, all->mlx->win, all->img->img, 0, 0);
	return (0);
}



/*

	//static	int	last_img;

	// TODO test draw line
	t_line	line;
	line = new_line(new_vec2(32, 10), new_vec2(30, 100) , 0x00FF6550, 0);
	draw_line(all->img, line);
	line = new_line(new_vec2(32, 10), new_vec2(40, 105) , 0x00FF6550, 0);
	draw_line(all->img, line);
	line = new_line(new_vec2(32, 10), new_vec2(50, 109) , 0x00FF6550, 0);
	draw_line(all->img, line);
	line = new_line(new_vec2(32, 10), new_vec2(60, 115) , 0x00FF6550, 0);
	draw_line(all->img, line);
	line = new_line(new_vec2(32, 10), new_vec2(70, 109) , 0x00FF6550, 0);
	draw_line(all->img, line);
	line = new_line(new_vec2(32, 10), new_vec2(80, 125) , 0x00FF6550, 0);
	draw_line(all->img, line);
	/// yep
	line = new_line(new_vec2(30, 100) ,new_vec2(320, 100),  0x00FF6550, 0);
	draw_line(all->img, line);
	line = new_line(new_vec2(40, 105) ,new_vec2(320, 100),  0x00FF6550, 0);
	draw_line(all->img, line);
	line = new_line(new_vec2(50, 109) ,new_vec2(320, 100),  0x00FF6550, 0);
	draw_line(all->img, line);
	line = new_line(new_vec2(60, 115) ,new_vec2(320, 100),  0x00FF6550, 0);
	draw_line(all->img, line);
	line = new_line(new_vec2(70, 109) ,new_vec2(320, 100),  0x00FF6550, 0);
	draw_line(all->img, line);
	line = new_line(new_vec2(80, 125) ,new_vec2(320, 100),  0x00FF6550, 0);
	draw_line(all->img, line);
	// etoile
	line = new_line(new_vec2(100, 200), new_vec2(200, 300) , 0x00FF6550, 0);
	draw_line(all->img, line);
	line = new_line(new_vec2(100, 200), new_vec2(0, 300) , 0x00FF6550, 0);
	draw_line(all->img, line);
	line = new_line(new_vec2(100, 200), new_vec2(200, 100) , 0x00FF6550, 0);
	draw_line(all->img, line);
	line = new_line(new_vec2(100, 200), new_vec2(0, 100) , 0x00FF6550, 0);
	draw_line(all->img, line);
	mlx_put_image_to_window(all->mlx->self, all->mlx->win, all->img->img, 0, 0);
	return (0);

*/
