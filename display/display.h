/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjungo <qjungo@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 11:35:26 by qjungo            #+#    #+#             */
/*   Updated: 2022/10/27 12:02:08 by qjungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H

# include "../fdf.h"
//# include "../libft/libft.h"
//# include "../read_map/read_map.h"
//# include "../display/display.h"
//# include "../minilibx_macos/mlx.h"
#include "../ft_math/ft_math.h"

/// MLX
///
///

typedef struct	s_mlx {
	void	*self;
	void	*win;
}	t_mlx;

/// PIXELS
///
///

typedef struct	s_img_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian; // Pour l'instant seulement utile dans "mlx get adrr"
	
	//	Taille de l'image
	int		x_size;
	int		y_size;
}	t_img_data;

/// ?
///
///


typedef struct	s_line_data {
	t_vec2	p_a;
	t_vec2	p_b;
	int		color; // Plus mettre l'info de la couleur de chaque point ?
	int		thickness;
}	t_line_data;


/// EVENT HANDLING 
///
///

enum e_event_type {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_LEAVE = 8, // TODO what ?
	ON_EXPOSE = 12,
	ON_DESTROY = 17,
	ON_RESIZE = 25, // TODO request en vrai
};

enum e_key {
	ESC = 53,
};

/// PROTOTYPES
///
///

void	draw_line(t_img_data *img, t_line_data line);
void	display(t_map map);
void	pixel_to_image(t_img_data *img, t_vec2 point, int color);
int		close_on_esc(int key, t_mlx *mlx);
int		close_on_destroy(t_mlx *mlx);

#endif /* DISPLAY_H */


/*
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_F 3
# define KEY_H 4
# define KEY_G 5
# define KEY_Z 6
# define KEY_X 7
# define KEY_C 8
# define KEY_V 9
# define KEY_B 11
# define KEY_Q 12
# define KEY_W 13
# define KEY_E 14
# define KEY_R 15
# define KEY_Y 16
# define KEY_T 17
# define KEY_ONE 18
# define KEY_TWO 19
# define KEY_THREE 20
# define KEY_FOUR 21
# define KEY_SIX 22
# define KEY_FIVE 23
# define KEY_NINE 25
# define KEY_SEVEN 26
# define KEY_EIGHT 28
# define KEY_ZERO 29
# define KEY_BRACE_R 30
# define KEY_O 31
# define KEY_U 32
# define KEY_BRACE_L 33
# define KEY_I 34
# define KEY_P 35
# define KEY_L 37
# define KEY_J 38
# define KEY_K 40
# define KEY_SEMI 41
# define KEY_N 45
# define KEY_M 46
# define KEY_TAB 48
# define KEY_PLUS 69
# define KEY_MINUS 78
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126

*/
