#include <math.h>
#include <stdlib.h>
#include "ft_mlx.h"
#include "../libft.h"

#include <stdio.h>

static int	check_max(float x, float y, t_img_data img)
{
	if (x < 0 || y < 0)
		return (1);
	if (x >= img.x_size || y >= img.y_size)
		return (1);
	return (0);
}

static void	move(t_vec2 *moving_pixel, t_line line, t_bool little, t_bool y_dist_greater)
{
	int		xm;
	int		ym;

	xm = 1;
	ym = 1;
	if (line.a.x > line.b.x)
		xm = -1;
	if (line.a.y > line.b.y)
		ym = -1;
	if (little)
		if (y_dist_greater)
			moving_pixel->x += xm;
		else
			moving_pixel->y += ym;
	else
		if (y_dist_greater)
			moving_pixel->y += ym;
		else
			moving_pixel->x += xm;
}

static void	loop(t_vec2 moving_pixel, t_line line, t_img_data *img)
{
	t_vec2	dist;
	float	speed;
	float	cursor;
	
	dist = new_vec2(ft_fabs(ft_fabs(line.a.x) - ft_fabs(line.b.x)), ft_fabs(ft_fabs(line.a.y) - ft_fabs(line.b.y)));
	speed = dist.y / dist.x;
	/// TODO ICI
	if (dist.x > dist.y)
		speed = dist.x / dist.y;
	printf("speeeed %.3f (%.1f)\n\n", speed, round(speed));
	cursor = 0;
	do
	{
		if (check_max(moving_pixel.x, moving_pixel.y, *img))
			break ;
		if (round(moving_pixel.x) == round(line.b.x) || round(moving_pixel.y) == round(line.b.y))
			break ;
		pixel_to_image(img, moving_pixel, line.color);
		move(&moving_pixel, line, FALSE, dist.y > dist.x);
		cursor += 1;
		if (cursor >= speed)
		{
			move(&moving_pixel, line, TRUE, dist.y > dist.x);
			cursor -= speed;
		}
	}
	while (!assert_rounded_vec2(moving_pixel, line.b));
}


static void	straight_loop(t_vec2 moving_pixel, t_line line, t_img_data *img)
{
	int		move_factor;
	
	move_factor = 1;
	if (round(line.a.y) == round(line.b.y) && (line.a.x > line.b.x))
		move_factor = -1;
	if (round(line.a.x) == round(line.b.x) && (line.a.y > line.b.y))
		move_factor = -1;
	while (1)
	{
		if (round(line.a.y) == round(line.b.y))
			moving_pixel.x += move_factor;
		else
			moving_pixel.y += move_factor;
		if (round(moving_pixel.x) == round(line.b.x) && round(moving_pixel.y) == round(line.b.y))
			break ;
		if (check_max(moving_pixel.x, moving_pixel.y, *img))
			break ;
		pixel_to_image(img, moving_pixel, line.color);
	}
}

void	draw_line(t_img_data *img, t_line line)
{
	t_vec2		moving_pixel;

	moving_pixel.x = line.a.x;
	moving_pixel.y = line.a.y;
	if (round(line.a.x) == round(line.b.x) || round(line.a.y) == round(line.b.y))
		straight_loop(moving_pixel, line, img);
	else
		loop(moving_pixel, line, img);
}
/*

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
		pixel.y = pixel.x * droite.m + droite.b;
		pixel.x = pixel.x + droite.move_factor;
		if (check_max(pixel.x, pixel.y, *img))
			break ;
		if (last_pixel.x == pixel.x && last_pixel.y == pixel.y)
			continue ;
		last_pixel.x = pixel.x;
		last_pixel.y = pixel.y;
		pixel_to_image(img, pixel, line.color);
	}
}

static void	straight_loop(t_vec2 moving_pixel, t_line line, t_img_data *img)
{
	int		move_factor;
	
	move_factor = 1;
	if (round(line.a.y) == round(line.b.y) && (line.a.x > line.b.x))
		move_factor = -1;
	if (round(line.a.x) == round(line.b.x) && (line.a.y > line.b.y))
		move_factor = -1;
	while (1)
	{
		if (round(line.a.y) == round(line.b.y))
			moving_pixel.x += move_factor;
		else
			moving_pixel.y += move_factor;
		if (round(moving_pixel.x) == round(line.b.x) && round(moving_pixel.y) == round(line.b.y))
			break ;
		if (check_max(moving_pixel.x, moving_pixel.y, *img))
			break ;
		pixel_to_image(img, moving_pixel, line.color);
	}
}

void	draw_line(t_img_data *img, t_line line)
{
	t_droite	droite;
	t_vec2		pixel;

	first_calculs(&line, &pixel, &droite);
	if (isinf(droite.m))
		straight_loop(pixel, line, img);
	else
		loop(pixel, line, droite, img);
}
*/
