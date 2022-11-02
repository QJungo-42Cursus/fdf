/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjungo <qjungo@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:00:56 by qjungo            #+#    #+#             */
/*   Updated: 2022/11/02 18:15:38 by qjungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#include "../minilibx_macos/mlx.h"
#include "../projection/projection.h"
#include "hooks.h"
#define ROTATION_SPEED 1.0f
#define MOV_SPEED 30

static int	perspective(int keycode, t_view *view)
{
	if (keycode == KEY_P)
		view->perspective = !view->perspective;
	else if (keycode == KEY_O)
	{
		view->scale -= 5;
		view->distance -= 1;
	}
	else if (keycode == KEY_I)
	{
		view->scale += 5;
		view->distance += 1;
	}
	else
		return (0);
	return (1);
}

static int	mov(int keycode, t_all *all)
{
	if (keycode == KEY_DOWN)
		all->view->angle.x += ROTATION_SPEED;
	else if (keycode == KEY_UP)
		all->view->angle.x -= ROTATION_SPEED;
	else if (keycode == KEY_RIGHT)
		all->view->angle.z += ROTATION_SPEED;
	else if (keycode == KEY_LEFT)
		all->view->angle.z -= ROTATION_SPEED;
	else if (keycode == KEY_S)
		all->view->mov.y -= MOV_SPEED;
	else if (keycode == KEY_W)
		all->view->mov.y += MOV_SPEED;
	else if (keycode == KEY_D)
		all->view->mov.x -= MOV_SPEED;
	else if (keycode == KEY_A)
		all->view->mov.x += MOV_SPEED;
	else if (keycode == KEY_PLUS)
		all->view->scale += 1;
	else if (keycode == KEY_MINUS)
		all->view->scale -= 1;
	else
		return (0);
	return (1);
}

	//if (all->mlx->self && all->img)
	//	mlx_destroy_image(all->mlx->self, all->img);
int	close_window(t_all *all)
{
	if (all->mlx->self && all->mlx->win)
		mlx_destroy_window(all->mlx->self, all->mlx->win);
	free(all->map->vertices);
	free(all->map->proj);
	free(all->map->edges);
	free(all->map);
	exit(0);
	return (0);
}

int	key_hook(int keycode, t_all *all)
{
	if (keycode == KEY_ESC)
		close_window(all);
	else if (mov(keycode, all))
		render_next_frame(all);
	else if (perspective(keycode, all->view))
		render_next_frame(all);
	return (0);
}
