#include "fdf.h"
#include "libft/libft.h"
#include "read_map/read_map.h"
#include "display/display.h"
#include "minilibx_macos/mlx.h"



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
	t_map	map;

	if (chec_args(argc, argv))
		return (0);
	s_errno = read_map(argv[1], &map);
	if(s_errno)
	{
		ft_printf("Erreur %i lors de la lecture de la map (%s)", s_errno, argv[1]); 
		return (0);
	}
	display(map);
	return (0);
}
