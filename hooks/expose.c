/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expose.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjungo <qjungo@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:45:30 by qjungo            #+#    #+#             */
/*   Updated: 2022/11/09 14:47:34 by qjungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../fdf.h"
#include "../minilibx_macos/mlx.h"
#include "../projection/projection.h"
#include "hooks.h"



#include<stdio.h>
int	expose_hook(t_all *all)
{
	printf("EXPOSE\n\n");
	printf("EXPOSE\n\n");
	(void)all;

	return (0);
}
