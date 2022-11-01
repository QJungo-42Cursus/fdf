/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjungo <qjungo@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:00:56 by qjungo            #+#    #+#             */
/*   Updated: 2022/11/01 21:38:10 by qjungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../fdf.h"
#include "../projection/projection.h"


int render(int keycode, t_all *all)
{
	(void) keycode;
	if (/* est dans le bonnes keys */1)
		render_next_frame(all);
	return (0);
}

#define speed 15
static int	perspective(int keycode, t_view *view)
{
	if (keycode == 112)					// perspective
		view->perspective = !view->perspective;
	else if (keycode == 111)
	{
		view->scale -= 5;
		view->distance -= 1;
	}
	else if (keycode == 105)
	{
		view->scale += 5;
		view->distance += 1;
	}
	else
		return (1);
	return (0);
}

#include "../minilibx_macos/mlx.h"

static void	close_window(t_all *all)
{
	//if (all->mlx->self && all->img)
	//	mlx_destroy_image(all->mlx->self, all->img);
	//exit (5);
	if (all->mlx->self && all->mlx->win)
		mlx_destroy_window(all->mlx->self, all->mlx->win);
	exit (0);
}

int	key_hook(int keycode, t_all *all)
{
	if (keycode == 65307)
		close_window(all);
	// juste mettre le reste aiileur...

	else if (keycode == 65364) // arr down	//	rotation
		all->view->angle.x += speed;
	else if (keycode == 65362) // arr up
		all->view->angle.x -= speed;
	else if (keycode == 65363) // arr right
		all->view->angle.z += speed;
	else if (keycode == 65361) // arr left
		all->view->angle.z -= speed;
	else if (keycode == 115) // arr down		//	mov	
		all->view->mov.y -= speed;
	else if (keycode == 119) // arr up
		all->view->mov.y += speed;
	else if (keycode == 100) // arr right
		all->view->mov.x -= speed;
	else if (keycode == 97) // arr left
		all->view->mov.x += speed;
	else if (keycode == 65451)				// scale
		all->view->scale += 1;
	else if (keycode == 65453)
		all->view->scale -= 1;
	else 
		if (perspective(keycode, all->view))
			return (0);
	render_next_frame(all);
	return (0);
}
