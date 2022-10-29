/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjungo <qjungo@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 20:31:50 by qjungo            #+#    #+#             */
/*   Updated: 2022/10/29 00:30:35 by qjungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"
#include <stdlib.h>

#include <stdio.h>
t_matrix	new_matrix(float **matrix, int x, int y)
{
	t_matrix	n;

	n.self = matrix;
	n.y = y;
	n.x = x;
	return (n);
}



float	op(t_matrix a, t_matrix b, int x, int y)
{
	// 0 0
	int		i;
	float	res;
	
	i = 0;
	res = 0;
	while (i < a.x)
	{
		res += a.self[y][i] * b.self[i][x];
		i++;
	}
	return (res);
}

t_matrix	matrix_product(t_matrix a, t_matrix b)
{
	t_matrix	n;
	int			x;
	int			y;

	n.x = b.x;
	n.y = a.y;
	n.self = malloc(sizeof(float *) * n.y);
	if (n.self == NULL)
		return (n);
	y = 0;
	while (y < n.y)
	{
		n.self[y] = malloc(sizeof(float) * n.x);
		x = 0;
		while (x < n.x)
		{
			n.self[y][x] = op(a, b, x, y);
			x++;
		}
		y++;
	}
	return (n);
}

void	log_matrix(t_matrix m)
{
	int	x;
	int	y;

	printf("matrice (%i, %i) = {\n", m.x, m.y);
	y = 0;
	while (y < m.y)
	{
		printf("\t[");
		x = 0;
		while (x < m.x)
		{
			printf("% .2f ", m.self[y][x]); 
			x++;
		}
		printf("]\n");
		y++;
	}
	printf("}\n\n");
}
