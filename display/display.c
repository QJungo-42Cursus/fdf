/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjungo <qjungo@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 11:35:13 by qjungo            #+#    #+#             */
/*   Updated: 2022/11/01 12:17:52 by qjungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../fdf.h"
#include "../libft/libft.h"
#include "../read_map/read_map.h"
#include "../display/display.h"
#include "../minilibx_macos/mlx.h"
#include "../ft_math/ft_math.h"
#include "../projection/projection.h"

#define LOGd
void	disp_edge(t_map *map, t_img_data *img)
{
	int			i;
	t_line		line;
	t_vec2		a;
	t_vec2		b;
	t_vec3		*pro;
	t_vec2		*proj;

	pro = copy_vec3(map->vertices, map->size);

	map_rotation_z(pro, map->size, 45);
	map_rotation_x(pro, map->size, 45);

	proj = copy_vec3_to2(pro, map->size);
	map_scale(proj, map->size, 50);
	translation_2d(proj, map->size, new_vec2(500, 500));

	i = 0;
	while (i < map->n_edges)
	{
		a = proj[map->edges[i].a];
		b = proj[map->edges[i].b];
		line = new_line(a, b, 0x00FF6550, 2);
#ifdef LOGd
		log_vec2(a);
		log_vec2(b);
		printf("\n\n");
#endif
		draw_line(img, line);
		(void)line;
		i++;
	}
}

void	display(t_map *map)
{
	(void)map;
	t_mlx		mlx;

	t_img_data	img;

	// Init mlx
	mlx.self = mlx_init();
	// Init a mlx window
	mlx.win = mlx_new_window(mlx.self, 1920, 1080, "FDF");

	
	// Create a image
	img.x_size = 1920;
	img.y_size = 1080;
	img.img = mlx_new_image(mlx.self, img.x_size, img.y_size);
	// Get memory address of the image
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	// Draw line !!!
//	t_line_data	line;
//	line.p_a = new_vec2(1705, 500);
//	line.p_b = new_vec2(1000, 100);
//	line.color = 0x00FF6550;
//	line.thickness = 2;
//	draw_line(&img, line);
	
	disp_edge(map, &img);


	// Print the image on the screen !
	mlx_put_image_to_window(mlx.self, mlx.win, img.img, 0, 0);

	// Hook that call the close_exit function (TODO : wtf is the 1L<<0 filter ??)
	mlx_hook(mlx.win, ON_KEYDOWN, 1L<<0, close_on_esc, &mlx);

	
	// Start the loop
	mlx_loop(mlx.self);
}
