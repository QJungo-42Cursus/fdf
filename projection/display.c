/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjungo <qjungo@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 11:35:13 by qjungo            #+#    #+#             */
/*   Updated: 2022/11/01 17:48:34 by qjungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../fdf.h"
#include "../libft/libft.h"
#include "../minilibx_macos/mlx.h"
#include "projection.h"

static void	disp_edges(t_vec2 *vertices, t_edge *edges, int n_edges, t_img_data *img)
{
	int		i;
	t_line	line;

	i = 0;
	while (i < n_edges)
	{
		line = new_line(vertices[edges[i].a], vertices[edges[i].b], 0x00FF6550, 2);
		draw_line(img, line);
		i++;
	}
}

void	render_background(t_img_data *img, int color)
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

typedef struct s_all {
	t_map		*map;
	t_view		*view;
	t_img_data	*img;
	t_mlx		*mlx;

}	t_all;
int	key_hook(int keycode, t_all *all)
{
	int		speed = 15;
	if (keycode == 65364) // arr down
		all->view->angle.x += speed;
	if (keycode == 65362) // arr up
		all->view->angle.x -= speed;
	if (keycode == 65363) // arr right
		all->view->angle.z += speed;
	if (keycode == 65361) // arr left
		all->view->angle.z -= speed;

	speed = 50;
	printf("keycode %d\n\n", keycode);
	if (keycode == 115) // arr down
		all->view->mov.y += speed;
	if (keycode == 119) // arr up
		all->view->mov.y -= speed;
	if (keycode == 100) // arr right
		all->view->mov.x += speed;
	if (keycode == 97) // arr left
		all->view->mov.x -= speed;

	if (keycode == 112)
		all->view->perspective = !all->view->perspective;
	if (keycode == 111)
		all->view->distance -= 1;
	if (keycode == 105)
		all->view->distance += 1;
	
	if (keycode == 65451)
		all->view->scale += 1;
	if (keycode == 65453)
		all->view->scale -= 1;

	render_background(all->img, 0x00000000);

	return (0);
}

int		close_on_esc(int key, t_mlx *mlx)
{
	// TODO clean juste pour mac
	if (key != KEY_ESC && key != 65307)
		return (0);
	mlx_destroy_window(mlx->self, mlx->win);
	exit(0);
	return (0);
}


int	render_next_frame(t_all *all)
{
	t_vec2		*proj;

	proj = projection(all->map, *all->view);
	disp_edges(proj, all->map->edges, all->map->n_edges, all->img);

	// Print the image on the screen !
	mlx_put_image_to_window(all->mlx->self, all->mlx->win, all->img->img, 0, 0);
	return (0);
}

void	display(t_map *map)
{
	t_mlx		mlx;
	t_img_data	img;
	t_vec2		screen;
	t_view		view;
	t_all		all;

	all.view = &view;
	all.img = &img;
	all.mlx = &mlx;
	all.map = map;

	init_window(&mlx, &img, &screen);

	// Display !!! -------------------------------------------
	view.angle.z = 45;
	view.angle.x = 45;
	view.angle.y = 0;
	view.scale = 5;
	view.mov.x = 500;
	view.mov.y = 500;
	view.perspective = FALSE;
	view.distance = 9;

	// Hook that call the close_exit function (TODO : wtf is the 1L<<0 filter ??)
	mlx_hook(mlx.win, ON_KEYDOWN, 1L<<0, close_on_esc, &mlx);

	mlx_key_hook(mlx.win, close_on_esc, &mlx);
	mlx_key_hook(mlx.win, key_hook, &all);
	mlx_loop_hook(mlx.self, render_next_frame, &all);
	
	// Start the loop
	mlx_loop(mlx.self);
}
