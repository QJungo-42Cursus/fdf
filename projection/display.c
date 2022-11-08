/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjungo <qjungo@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 11:35:13 by qjungo            #+#    #+#             */
/*   Updated: 2022/11/08 20:03:34 by qjungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../fdf.h"
#include "../libft/libft.h"
#include "../hooks/hooks.h"
#include "../minilibx_macos/mlx.h"
#include "projection.h"


static t_all	*init_all(t_map *map, t_view *view, t_img_data *img, t_mlx *mlx);
static void		init_view(t_view *view, t_map *map, t_vec2 screen);
static t_view	new_view(t_vec3 angle, t_vec2 mov, float scale, float distance);
static void		init_window(t_mlx *mlx, t_img_data *img, t_vec2 *screen);

void	display(t_map *map)
{
	t_mlx		mlx;
	t_img_data	img;
	t_vec2		screen;
	t_view		view;
	t_all		*all;

	all = init_all(map, &view, &img, &mlx);
	init_window(&mlx, &img, &screen);
	init_view(&view, map, screen);
	projection(map, view);
	init_view(&view, map, screen);
	render_next_frame(all);
	mlx_hook(mlx.win, ON_DESTROY, 0, close_window, all);
	mlx_key_hook(mlx.win, key_hook, all);
	mlx_loop(mlx.self);
	free(all);
}

static void		init_window(t_mlx *mlx, t_img_data *img, t_vec2 *screen)
{
	screen->x = 2550;
	screen->y = 1350;
	mlx->self = mlx_init();
	mlx->win = mlx_new_window(mlx->self, screen->x, screen->y, "FDF");
	img->x_size = screen->x;
	img->y_size = screen->y;
	img->img = mlx_new_image(mlx->self, img->x_size, img->y_size);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
}

/*
static float	hypotenuse(float a, float b)
// TODO math.h !!
{
	return (sqrt(pow(a, 2) + pow(b, 2)));
}
*/

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
	static t_bool	first = TRUE;
	float			diag_size;
	float			middle;

	*view = new_view(new_vec3(-45, 0, -45), new_vec2(0, 0), 0, 10);
	if (first)
	{
		first = FALSE;
		return ;
	}
	diag_size = distance(vec3_to2(map->vertices[0]),
			vec3_to2(map->vertices[map->size - 1]));
	view->scale = screen.y / diag_size / 1.2;
	middle = (map->vertices[map->size - 1].x - map->vertices[0].x)
		/ 2 * view->scale;
	view->mov = new_vec2(screen.x / 2 - middle,
			(screen.y / 2 - diag_size / 2) / 4);
}

static t_all	*init_all(t_map *map, t_view *view, t_img_data *img, t_mlx *mlx)
{
	t_all	*all;

	all = malloc(sizeof(t_all));
	if (!all)
		return (NULL);
	all->map = map;
	all->view = view;
	all->img = img;
	all->mlx = mlx;
	return (all);
}

