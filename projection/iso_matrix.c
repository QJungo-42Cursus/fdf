/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso_matrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjungo <qjungo@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 23:21:13 by qjungo            #+#    #+#             */
/*   Updated: 2022/10/31 14:56:09 by qjungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../ft_math/ft_math.h"
#include <math.h>
#include <stdlib.h>

static t_matrix	iso_matrix_1(float alpha)
{
	float		**a;
	t_matrix	m;

	a = malloc(sizeof(float *) * 3);
	a[0] = malloc(sizeof(float) * 3);
	a[0][0] = 1;
	a[0][1] = 0;
	a[0][2] = 0;
	a[1] = malloc(sizeof(float) * 3);
	a[1][0] = 0;
	a[1][1] = cos(alpha);
	a[1][2] = sin(alpha);
	a[2] = malloc(sizeof(float) * 3);
	a[2][0] = 0;
	a[2][1] = -sin(alpha);
	a[2][2] = cos(alpha);
	m.x = 3;
	m.y = 3;
	m.self = a;
	return (m);
}

static t_matrix	iso_matrix_2(float beta)
{
	float		**a;
	t_matrix	m;

	a = malloc(sizeof(float *) * 3);
	a[0] = malloc(sizeof(float) * 3);
	a[0][0] = cos(beta);
	a[0][1] = 0;
	a[0][2] = -sin(beta);
	a[1] = malloc(sizeof(float) * 3);
	a[1][0] = 0;
	a[1][1] = 1;
	a[1][2] = 0;
	a[2] = malloc(sizeof(float) * 3);
	a[2][0] = sin(beta);
	a[2][1] = 0;
	a[2][2] = cos(beta);
	m.x = 3;
	m.y = 3;
	m.self = a;
	return (m);
}

t_matrix	iso_matrix(float alpha, float beta)
{
	t_matrix	res;

	//asin(30)
	//45
	res = matrix_product(iso_matrix_1(alpha), iso_matrix_2(beta));
	return (res);
}
