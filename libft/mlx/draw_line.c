/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjungo <qjungo@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 11:35:13 by qjungo            #+#    #+#             */
/*   Updated: 2022/11/01 15:11:28 by qjungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include "ft_mlx.h"
#include "../libft.h"

//#define LOG

static int	check_max(float x, float y, t_img_data img)
{
	if (x < 0 || y < 0)
		return (1);
	if (x >= img.x_size || y >= img.y_size)
		return (1);
	return (0);
}

static void	first_calculs(t_line *line, t_vec2 *pixel, t_droite *droite)
{
	pixel->x = line->a.x;
	pixel->y = line->a.y;
	droite->m = slope(line->a, line->b);
	droite->b = ordonnate_to_origin(pixel->x, pixel->y, droite->m);
	// TODO meilleur algo pour le choix de l'incrément
	droite->move_factor = 0.001f;
	if (line->a.x > line->b.x) // TODO ca marche mais j'aurais mis dans l'autre sens...
		droite->move_factor = -0.001f;
}

static void	loop(t_vec2 pixel, t_line line, t_droite droite, t_img_data *img)
{
	t_vec2	last_pixel;

	last_pixel = new_vec2(-1, -1);
	while (!assert_rounded_vec2(pixel, line.b))
	{
#ifdef LOG
		printf("start : [ {%f, %f},", line.p_a.x, line.p_a.y);
		printf("{%f, %f} ] -  ", line.p_b.x, line.p_b.y);
		printf("{%f, %f}\n", pixel.x, pixel.y);
#endif
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
		pixel_to_image(img, pixel, line.color );
	}
}

static void	inf_loop(t_vec2 pixel, t_line line, t_img_data *img)
{
	while (pixel.y != line.b.y)
	{
		// Do the calculation
		pixel.y = pixel.y + 1;

		// Prevent from going further than the image // TODO rendre dynamic
		if (check_max(pixel.x, pixel.y, *img))
			break;
		pixel_to_image(img, pixel, line.color );
	}
}

void	draw_line(t_img_data *img, t_line line)
{
	t_droite	droite;
	t_vec2		pixel;
	
	first_calculs(&line, &pixel, &droite);
#ifdef LOG
	printf("{%f; %f}\n", line.p_a.x, line.p_a.y);
	printf("{%f; %f}\n", line.p_b.x, line.p_b.y);
	printf("slope : %f, oto : %f\n", droite.m, droite.b);
#endif
	if (isinf(droite.m))
		inf_loop(pixel, line, img);
	else
		loop(pixel, line, droite, img);
}
