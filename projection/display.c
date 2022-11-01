/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjungo <qjungo@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 11:35:13 by qjungo            #+#    #+#             */
/*   Updated: 2022/11/01 21:28:56 by qjungo           ###   ########.fr       */
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

	// Create a image and get its addresse
	img->x_size = screen->x;
	img->y_size = screen->y;
	img->img = mlx_new_image(mlx->self, img->x_size, img->y_size);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
}

static void	init_view(t_view *view)
{
	// TODO calcule pour que ce soit au centre
	view->angle = new_vec3(45, 0, 45);
	view->mov = new_vec2(0, 0);
	view->scale = 50;
	view->distance = 10;
	view->perspective = FALSE;
}

static t_all *init_all(t_map *map, t_view *view, t_img_data *img, t_mlx *mlx)
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
	init_view(&view);
	render_next_frame(all);

	// HOOKS
	//mlx_hook(mlx.win, ON_DESTROY, 0, close_on_esc, all);
	mlx_key_hook(mlx.win, key_hook, all);
	
	// Start the loop
	mlx_loop(mlx.self);

	free(all);
}
