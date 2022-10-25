#include "fdf.h"
#include "libft/libft.h"

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
	int		errno;

	if (chec_args(argc, argv))
		return (0);
	errno = read_file(argv[1]);
	if(errno)
	{
		ft_printf("Erreur %i lors de la lecture de la map (%s)", errno, argv[1]); 
		return (0);
	}


	return (0);
}
