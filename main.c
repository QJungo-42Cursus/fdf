#include <math.h>
#include "fdf.h"
#include "libft/libft.h"
#include "read_map/read_map.h"
#include "minilibx_macos/mlx.h"
#include "projection/projection.h"

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
	t_map	*map;

	if (chec_args(argc, argv))
		return (0);
	map = malloc(sizeof(t_map));
	if (map == NULL)
	{
		ft_printf("Erreur lors de l'allocation de memoire de \"map\""); 
		return (0);
	}
	if (read_map(argv[1], map))
	{
		free(map);
		ft_printf("Erreur lors de la lecture de la map (%s)", argv[1]); 
		return (0);
	}
	create_edges(map);
	display(map);
	free(map->vertices);
	free(map->edges);
	free(map);
	return (0);
}
