/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjungo <qjungo@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 11:35:13 by qjungo            #+#    #+#             */
/*   Updated: 2022/10/26 14:07:33 by qjungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../read_map/read_map.h"
#include "../display/display.h"
#include "../minilibx_macos/mlx.h"

/// 
/// All event called by the event handler function
///


/// Close window and quit programme
/// This must be called after freeing ??? TODO
/// Have to return a int to fit the function pointer
int		close_on_esc(int key, t_mlx *mlx)
{
	if (key != ESC)
		return (0);
	mlx_destroy_window(mlx->self, mlx->win);
	exit(0);
	return (0);
}

/// Same but on destroy
int		close_on_destroy(t_mlx *mlx)
{
	mlx_destroy_window(mlx->self, mlx->win);
	exit(0);
	return (0);
}
