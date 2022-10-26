/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_to_image.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjungo <qjungo@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:48:53 by qjungo            #+#    #+#             */
/*   Updated: 2022/10/26 14:01:22 by qjungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
///		Add a pixel to an image
///		This is a more optimised way than mlx_put_pixel, because it render
///		only when you put the image to the screen instead of doing 1 by 1
void	pixel_to_image(t_img_data *data, int x, int y, int color)
{
	char	*dst;
	int		offset;

	offset = y * data->line_length + x * (data->bits_per_pixel / 8);
	dst = data->addr + offset;
	*(unsigned int*)dst = color;
}
