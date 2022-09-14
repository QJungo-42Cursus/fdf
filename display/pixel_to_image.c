/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_to_image.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjungo <qjungo@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:48:53 by qjungo            #+#    #+#             */
/*   Updated: 2022/10/27 12:34:53 by qjungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include <math.h>
///		Add a pixel to an image
///		This is a more optimised way than mlx_put_pixel, because it render
///		only when you put the image to the screen instead of doing 1 by 1
void	pixel_to_image(t_img_data *img, t_vec2 point, int color)
{
	char	*dst;
	int		offset;
	int		x;
	int		y;

	//x = round(point.x);
	//y = round(point.y);
	x = point.x;
	y = point.y;

	//	Calcul la position de la couleur du pixel dans l'image
	offset = y * img->line_length + x * (img->bits_per_pixel / 8);
	dst = img->addr + offset;

	//	Set la couleur du pixel au bon endroit (etait transparent avant)
	*(unsigned int*)dst = color;
}
