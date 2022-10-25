#ifndef FDF_H
# define FDF_H


int	read_file(const char *path);
typedef struct s_map {
	int		x_size;
	int		y_size;
	short	**points;
	// en 2d... la valeur represente la 3eme dimension
}	t_map;

#endif /* FDF_H */
