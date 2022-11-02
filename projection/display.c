/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjungo <qjungo@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 11:35:13 by qjungo            #+#    #+#             */
/*   Updated: 2022/11/02 14:57:03 by qjungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../fdf.h"
#include "../libft/libft.h"
#include "../hooks/hooks.h"
#include "../minilibx_macos/mlx.h"
#include "projection.h"

static void	init_window(t_mlx *mlx, t_img_data *img, t_vec2 *screen)
{
	screen->x = 1920;
	screen->y = 1080;
	mlx->self = mlx_init();
	mlx->win = mlx_new_window(mlx->self, screen->x, screen->y, "FDF");
	img->x_size = screen->x;
	img->y_size = screen->y;
	img->img = mlx_new_image(mlx->self, img->x_size, img->y_size);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
}

static float	hypotenuse(float a, float b)
// TODO math.h !!
{
	return (sqrt(pow(a, 2) + pow(b, 2)));
}

static void	init_view(t_view *view, t_map *map)
// TODO calcule pour que ce soit au centre
{
	float		diag_size;
	float		screen_diag;

	diag_size = hypotenuse(map->y_size, map->x_size);
	screen_diag = hypotenuse(1920, 1080);
	view->angle = new_vec3(-45, 0, -45);
	view->mov = new_vec2(500, 500);
	view->scale = screen_diag / diag_size / 5;
	view->distance = 10;
	view->perspective = FALSE;
	printf("diag size %f \n\n", diag_size);
	printf("scale : %f\n\n", view->scale);
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

void	display(t_map *map)
{
	t_mlx		mlx;
	t_img_data	img;
	t_vec2		screen;
	t_view		view;
	t_all		*all;

	all = init_all(map, &view, &img, &mlx);
	init_window(&mlx, &img, &screen);
	init_view(&view, map);
	render_next_frame(all);
	mlx_key_hook(mlx.win, key_hook, all);
	mlx_loop(mlx.self);
	free(all);
}
