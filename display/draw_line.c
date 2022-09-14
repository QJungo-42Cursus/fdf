/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjungo <qjungo@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 11:35:13 by qjungo            #+#    #+#             */
/*   Updated: 2022/10/27 13:01:17 by qjungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../display/display.h"
#include "../ft_math/ft_math.h"


#include <stdio.h>
static int	check_max(float x, float y, t_img_data img)
{
	return ((x >= img.x_size || y >= img.y_size) && (x < 0 || y < 0));
}

static void	first_calculs(t_line_data *line, t_vec2 *pixel, t_droite *droite)
{
	pixel->x = line->p_a.x;
	pixel->y = line->p_a.y;
	droite->m = slope(line->p_a, line->p_b);
	droite->b = ordonnate_to_origin(pixel->x, pixel->y, droite->m);
	droite->move_factor = 0.1f;
	if (line->p_a.x > line->p_b.x) // TODO ca marche mais j'aurais mis dans l'autre sens...
		droite->move_factor = -0.1f;
}

static void	loop(t_vec2 pixel, t_line_data line, t_droite droite, t_img_data *img)
{
	t_vec2	last_pixel;

	last_pixel = new_vec2(-1, -1);
	while (!assert_rounded_vec2(pixel, line.p_b))
	{
		// LOG
		printf("start : [ {%f, %f},", line.p_a.x, line.p_a.y);
		printf("{%f, %f} ] -  ", line.p_b.x, line.p_b.y);
		printf("{%f, %f}\n", pixel.x, pixel.y);

		// Do the calculation
		pixel.y = pixel.x * droite.m + droite.b;			// y pos
		pixel.x = pixel.x + droite.move_factor;	// x move by 0.1

		// Prevent from going further than the image // TODO rendre dynamic
		if (check_max(pixel.x, pixel.y, *img))
			break;
		if (last_pixel.x == pixel.x && last_pixel.y == pixel.y)
			continue;
		last_pixel.x = pixel.x;
		last_pixel.y = pixel.y;
		pixel_to_image(img, pixel, 0x00FF6550);
	}
}

void	draw_line(t_img_data *img, t_line_data line)
{
	t_droite	droite;
	t_vec2		pixel;
	
	first_calculs(&line, &pixel, &droite);

	// LOG
	printf("{%f; %f}\n", line.p_a.x, line.p_a.y);
	printf("{%f; %f}\n", line.p_b.x, line.p_b.y);
	printf("slope : %f, oto : %f\n", droite.m, droite.b);


	loop(pixel, line, droite, img);
}
