/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjungo <qjungo@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 20:52:01 by qjungo            #+#    #+#             */
/*   Updated: 2022/07/11 20:52:01 by qjungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #ifndef SIZE_MAX
// # ifdef __SIZE_MAX__
// #  define SIZE_MAX __SIZE_MAX__
// # endif
// #endif
#include <unistd.h>
#include <stdlib.h>

static void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*v;
	size_t			i;

	v = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		v[i++] = (unsigned char)c;
	}
	return ((void *)v);
}

void	*ft_calloc(size_t nmem, size_t size)
{
	unsigned char		*res;

	if (nmem == SIZE_MAX && size == SIZE_MAX)
		return (NULL);
	res = malloc(nmem * size);
	if (res == NULL)
		return (NULL);
	ft_memset(res, 0, (nmem * size));
	return (res);
}
