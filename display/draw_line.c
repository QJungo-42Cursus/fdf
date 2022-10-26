/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjungo <qjungo@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 11:35:13 by qjungo            #+#    #+#             */
/*   Updated: 2022/10/26 16:40:13 by qjungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../display/display.h"
#include "../ft_math/ft_math.h"


#include <stdio.h>
void	draw_line(t_img_data *img, t_line_data line)
{
	float	m;	// pente
	float	b;  // Ordonnee a l'origin
	float	x;
	float	y;
	int		is_neg;
	int		xr;
	int		yr;
	
	m = slope(line.p_a, line.p_b);
	x = (float)line.p_a.x;
	y = (float)line.p_a.y;
	b = ordonnate_to_origin(x, y, m);
	// printf("slope : %f, oto : %f\n", m, b);

	is_neg = 1;
	if (line.p_a.x > line.p_b.x) // TODO ca marche mais j'aurais mis dans l'autre sens...
		is_neg = -1;
	
	do
	{
		xr = (int)round(x);
		yr = (int)round(y);
		if (xr == 1920 || xr == 1080 || yr == 1920 || yr == 1080)
			break;
		y = x * m + b;
		pixel_to_image(img, xr, yr, 0x00ff6550);
		x = x + 0.1f * is_neg;
		printf("start : [ {%i, %i},", line.p_b.x, line.p_b.y);
		printf("{%i, %i} ] -  ", line.p_b.x, line.p_b.y);
		printf("{%i, %i}\n", xr, yr);
	}
	while ((xr != line.p_b.x) || (yr != line.p_b.y));
}
