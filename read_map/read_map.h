#ifndef READ_MAP_H
# define READ_MAP_H

# include"../libft/libft.h"
# include"../fdf.h"

int		read_map(const char *path, t_map *map);
void	log_print_map(t_list *start_lines_list, t_map map);
void	log_final_map(t_map map);

#endif /* READ_MAP_H */
