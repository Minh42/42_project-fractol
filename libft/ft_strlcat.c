/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minh <minh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 14:14:27 by minh              #+#    #+#             */
/*   Updated: 2017/11/27 09:51:31 by mpham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	resultat;

	i = 0;
	j = 0;
	resultat = ft_strlen(dest) + ft_strlen(src);
	while (dest[i] != '\0' && i < size)
	{
		i++;
	}
	if (size == i)
	{
		return (size + ft_strlen(src));
	}
	while (i != (size - 1) && src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (resultat);
}
