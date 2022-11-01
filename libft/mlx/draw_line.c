/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjungo <qjungo@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 11:35:13 by qjungo            #+#    #+#             */
/*   Updated: 2022/11/01 19:37:23 by qjungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include "ft_mlx.h"
#include "../libft.h"


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
	droite->move_factor = 0.001f;
	if (line->a.x > line->b.x)
		droite->move_factor = -0.001f;
}

static void	loop(t_vec2 pixel, t_line line, t_droite droite, t_img_data *img)
{
	t_vec2	last_pixel;

	last_pixel = new_vec2(-1, -1);
	while (!assert_rounded_vec2(pixel, line.b))
	{
#ifdef LOG
		printf("start : [ {%f, %f},", line.a.x, line.a.y);
		printf("{%f, %f} ] -  ", line.b.x, line.b.y);
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


#define LOG
static void	inf_loop(t_vec2 pixel, t_line line, t_img_data *img, t_bool is_y)
{
	(void) is_y;
	printf("YEEE\n\n");
	while (1)
	{
		pixel.y++;
#ifdef LOG
		log_vec2(pixel); log_vec2(line.b);
		printf("{%f; %f} isame %d\n", pixel.x, line.b.x, pixel.x == line.b.x);
		//printf("slope : %f, oto : %f\n", droite.m, droite.b);
#endif
		if (round(pixel.x) != round(line.b.x))
			break ;
		if (check_max(pixel.x, pixel.y, *img))
			break ;
		pixel_to_image(img, pixel, line.color );
	}
	printf("\n..\n\n");
	return ;
}

void	draw_line(t_img_data *img, t_line line)
{
	t_droite	droite;
	t_vec2		pixel;
	
	first_calculs(&line, &pixel, &droite);
#ifdef LOG
	printf("{%f; %f}\n", line.a.x, line.a.y);
	printf("{%f; %f}\n", line.b.x, line.b.y);
	printf("slope : %f, oto : %f\n", droite.m, droite.b);
#endif
	//loop(pixel, line, droite, img);
//		return ;
	//if (isinf(droite.m) || droite.m == -0.0f || droite.m == 0.0f || isnan(droite.m))
	if (isinf(droite.m))
		inf_loop(pixel, line, img, TRUE);
	else
		loop(pixel, line, droite, img);
}
