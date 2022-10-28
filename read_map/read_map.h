#ifndef READ_MAP_H
# define READ_MAP_H

# include"../libft/libft.h"
# include"../fdf.h"

int		read_map(const char *path, t_map *map);
int		create_edges(t_map *map);

void	log_print_map(t_list *start_lines_list, t_map map);
void	log_final_map(t_map *map);
void	log_vertice(t_vertice vertice);
void	log_edges(t_map *map);
void	log_vec2(t_vec2 v);

#endif /* READ_MAP_H */
