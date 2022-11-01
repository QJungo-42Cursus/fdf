/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjungo <qjungo@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 20:31:50 by qjungo            #+#    #+#             */
/*   Updated: 2022/11/01 10:44:10 by qjungo           ###   ########.fr       */
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

t_matrix	init_matrix(int x, int y)
{
	t_matrix	n;
	int			i;
	int			j;

	n.self = (float **)malloc(sizeof(float *) * y);
	i = 0;
	while (i < y)
	{
		n.self[i] = (float *)malloc(sizeof(float) * x);
		j = 0;
		while (j < x)
		{
			n.self[i][j] = 0;
			j++;
		}
		i++;
	}
	n.y = y;
	n.x = x;
	return (n);
}

t_matrix	vec2_to_matrix(t_vec2 vec)
{
	float		**matrix;
	t_matrix	n;

	matrix = (float **)malloc(sizeof(float *) * 2);
	matrix[0] = (float *)malloc(sizeof(float) * 1);
	matrix[1] = (float *)malloc(sizeof(float) * 1);
	matrix[0][0] = vec.x;
	matrix[1][0] = vec.y;
	n = new_matrix(matrix, 1, 2);
	return (n);
}

t_matrix	vec3_to_matrix(t_vec3 vec)
{
	float		**matrix;
	t_matrix	n;

	matrix = (float **)malloc(sizeof(float *) * 3);
	matrix[0] = (float *)malloc(sizeof(float) * 1);
	matrix[1] = (float *)malloc(sizeof(float) * 1);
	matrix[2] = (float *)malloc(sizeof(float) * 1);
	matrix[0][0] = vec.x;
	matrix[1][0] = vec.y;
	matrix[2][0] = vec.z;
	n = new_matrix(matrix, 1, 3);
	return (n);
}

t_vec3	matrix_to_vec3(t_matrix matrix)
{
	t_vec3		vec;

	vec.x = matrix.self[0][0];
	vec.y = matrix.self[1][0];
	vec.z = matrix.self[2][0];
	return (vec);
}

t_vec2	matrix_to_vec2(t_matrix matrix)
{
	t_vec2		vec;

	vec.x = matrix.self[0][0];
	vec.y = matrix.self[1][0];
	return (vec);
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


// produit de matrice
t_matrix	matrix_product(t_matrix a, t_matrix b)
{
	t_matrix	n;
	int			x;
	int			y;

	if (a.x != b.y)
		return (new_matrix(NULL, 0, 0));
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

// element wise matrix multiplication
t_matrix	element_wise_matrix_multiplication(t_matrix a, t_matrix b)
{
	t_matrix	n;
	int			x;
	int			y;

	if (a.x != b.x || a.y != b.y)
		return (new_matrix(NULL, 0, 0));
	n.x = a.x;
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
			n.self[y][x] = a.self[y][x] * b.self[y][x];
			x++;
		}
		y++;
	}
	return (n);
}


t_matrix	matrix_addition(t_matrix a, t_matrix b)
{
	t_matrix	n;
	int			i;
	int			j;

	if (a.x != b.x || a.y != b.y)
		return (new_matrix(NULL, 0, 0));
	n = new_matrix((float **)malloc(sizeof(float *) * a.y), a.x, a.y);
	i = 0;
	while (i < a.y)
	{
		n.self[i] = (float *)malloc(sizeof(float) * a.x);
		j = 0;
		while (j < a.x)
		{
			n.self[i][j] = a.self[i][j] + b.self[i][j];
			j++;
		}
		i++;
	}
	return (n);
}

void	free_matrix(t_matrix matrix)
{
	int i;

	i = 0;
	while (i < matrix.y)
	{
		free(matrix.self[i]);
		i++;
	}
	free(matrix.self);
}

// produit de matrice par un scalaire
t_matrix	matrix_product_scal(t_matrix a, float scal)
{
	t_matrix	n;
	int			x;
	int			y;

	n.x = a.x;
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
			n.self[y][x] = a.self[y][x] * scal;
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
