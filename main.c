#include <math.h>
#include "fdf.h"
#include "libft/libft.h"
#include "read_map/read_map.h"
#include "display/display.h"
#include "ft_math/ft_math.h"
#include "minilibx_macos/mlx.h"
#include "projection/projection.h"



#define PI 3.141592654

static void	test(int run)
{
	if (!run)
		return ;
	printf("%f \n\n", asin(0.57735));
	float dg_rad = 30 * 2 * PI / 360;
	printf("%f \n\n", tan(dg_rad));
	t_matrix uu = iso_matrix(35.264, 45);
	log_matrix(uu);
	return ;

	float	**yo;
	// [y][x]
	yo = malloc(sizeof(float *) * 3);
	yo[0] = malloc(sizeof(float) * 2);
	yo[0][0] = 1;
	yo[0][1] = 2;
	yo[1] = malloc(sizeof(float) * 2);
	yo[1][0] = 0;
	yo[1][1] = 4;
	yo[2] = malloc(sizeof(float) * 2);
	yo[2][0] = 3;
	yo[2][1] = -1;

	t_matrix m = new_matrix(yo, 2, 3);
	log_matrix(m);

	float	**yg;
	// [y][x]
	yg = malloc(sizeof(float *) * 2);
	yg[0] = malloc(sizeof(float) * 2);
	yg[0][0] = 2;
	yg[0][1] = 0;
	yg[1] = malloc(sizeof(float) * 2);
	yg[1][0] = 1;
	yg[1][1] = -3;
	t_matrix n = new_matrix(yg, 2, 2);
	log_matrix(n);

	t_matrix o = matrix_product(m, n);
	log_matrix(o);
}

static int	chec_args(int argc, char **argv)
{
	int		len;

	if (argc != 2)
	{
		ft_printf("Mauvais nombre d'arguments ! (%i au lieu de %i)\n", argc - 1, 1); 
		return (1);
	}
	len = ft_strlen(argv[1]);
	if (len == 0)
	{
		ft_printf("La chaine de caracter entree est vide\n", argc - 1, 1); 
		return (1);
	}
	if (ft_strncmp(&(argv[1][len - 4]), ".fdf", 4))
	{
		ft_printf("Le programme n'accepte que les fichiers de type \'.fdf\'\n", &(argv[1][len - 4])); 
		return (1);
	}
	return (0);
}


int	main(int argc, char **argv)
{
	int		s_errno;
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (map == NULL)
	{}
	test(0);
		//return (0);
	if (chec_args(argc, argv))
		return (0);
	s_errno = read_map(argv[1], map);
	if(s_errno)
	{
		ft_printf("Erreur %i lors de la lecture de la map (%s)", s_errno, argv[1]); 
		return (0);
	}
	//	TODO -> separer (dans vertex) la position et la projection
	create_edges(map);




	display(map);
	return (0);
}
