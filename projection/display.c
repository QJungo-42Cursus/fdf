/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjungo <qjungo@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 11:35:13 by qjungo            #+#    #+#             */
/*   Updated: 2022/11/09 16:12:29 by qjungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../fdf.h"
#include "../libft/libft.h"
#include "../hooks/hooks.h"
#include "../minilibx_macos/mlx.h"
#include "projection.h"

static void	init_all(t_map *map, t_view *view, t_img_data *img, t_mlx *mlx, t_all *all);
static void		init_view(t_view *view, t_map *map, t_vec2 screen);
static t_view	new_view(t_vec3 angle, t_vec2 mov, float scale, float distance);
static void		init_window(t_mlx *mlx, t_img_data *img, t_vec2 *screen);

#include <stdio.h>
void	display(t_map *map)
{
	t_mlx		mlx;
	t_img_data	img;
	t_vec2		screen;
	t_view		view;
	t_all		all;

	init_all(map, &view, &img, &mlx, &all);
	init_window(&mlx, &img, &screen);
	view = new_view(new_vec3(-45, 0, -45), new_vec2(0, 0), 0, 10);
	projection(map, view);
	init_view(&view, map, screen);
	render_next_frame(&all);
	mlx_hook(mlx.win, ON_DESTROY, 0, close_window, &all);
	mlx_hook(mlx.win, ON_KEYDOWN, 0, key_hook, &all);
	mlx_expose_hook(mlx.win, expose_hook, &all);

	// linux
	mlx_key_hook(mlx.win, key_hook, &all);
	//

	mlx_loop(all.mlx->self);
}

static void	init_window(t_mlx *mlx, t_img_data *img, t_vec2 *screen)
{
	screen->x = 2550;
	screen->y = 1350;

	//linux
	screen->x = 2550 / 4;
	screen->y = 1350 / 4;
	//
	
	mlx->self = mlx_init();
	mlx_do_key_autorepeaton(mlx->self);
	mlx->win = mlx_new_window(mlx->self, screen->x, screen->y, "FDF");
	img->size.x = screen->x;
	img->size.y = screen->y;
	img->img = mlx_new_image(mlx->self, screen->x, screen->y);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
}

static t_view	new_view(t_vec3 angle, t_vec2 mov, float scale, float distance)
{
	t_view	n;

	n.angle = angle;
	n.mov = mov;
	n.scale = scale;
	n.distance = distance;
	n.perspective = FALSE;
	return (n);
}

static void	init_view(t_view *view, t_map *map, t_vec2 screen)
{
	float			xy_diag_size;
	float			middle;

	xy_diag_size = distance(vec3_to2(map->vertices[0]),
			vec3_to2(map->vertices[map->xy_size - 1]));
	view->scale = screen.y / (xy_diag_size + map->size.z) / 1.2;
	middle = (map->vertices[map->xy_size - 1].x - map->vertices[0].x)
		/ 2 * view->scale;
	view->mov = new_vec2(screen.x / 2 - middle,
			((screen.y / 2) - (xy_diag_size / 2) + (map->size.z * 40)) / 4);
}

static void	init_all(t_map *map, t_view *view, t_img_data *img, t_mlx *mlx, t_all *all)
{
	//t_all	*all;

	//all = malloc(sizeof(t_all));
	//if (!all)
	//	return (NULL);
	all->map = map;
	all->view = view;
	all->img = img;
	all->mlx = mlx;
}
