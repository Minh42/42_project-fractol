/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpham <mpham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 12:48:07 by minh              #+#    #+#             */
/*   Updated: 2017/11/27 09:29:34 by mpham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	c2;
	unsigned char	*cdest;
	unsigned char	*csrc;

	i = 0;
	c2 = (unsigned char)c;
	cdest = (unsigned char *)dest;
	csrc = (unsigned char *)src;
	while (i < n)
	{
		cdest[i] = csrc[i];
		if (csrc[i] == c2)
		{
			return (dest + i + 1);
		}
		i++;
	}
	return (NULL);
}
