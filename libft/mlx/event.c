/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjungo <qjungo@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 11:35:13 by qjungo            #+#    #+#             */
/*   Updated: 2022/11/01 15:12:40 by qjungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mlx.h"
#include "ft_mlx.h"
#include <stdlib.h>

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
