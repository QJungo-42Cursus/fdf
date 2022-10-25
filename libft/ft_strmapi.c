/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjungo <qjungo@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 20:52:49 by qjungo            #+#    #+#             */
/*   Updated: 2022/07/11 20:52:49 by qjungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// TODO pk la fonction f prend un int ???

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*res;
	unsigned int	i;

	res = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		res[i] = f(i, s[i]);
		i++;
	}
	res[i] = 0;
	return (res);
}

/*
 *
 * #1.  The string on which to iterate.
 * #2.  The function to apply to each character.
 *
 * Return value : The string created from the successive applications
 * of ’f’.  Returns NULL if the allocation fails.
 *
 * Applies the function ’f’ to each character of the string ’s’ to create
 * a new string (with malloc(3)) resulting from successive applications of ’f
 *
 */