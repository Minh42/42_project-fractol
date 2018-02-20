/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minh <minh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 14:31:59 by minh              #+#    #+#             */
/*   Updated: 2017/11/27 09:39:32 by mpham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t	i;
	char	*copie_dest;
	char	*copie_src;

	copie_dest = (char *)dest;
	copie_src = (char *)src;
	i = 0;
	if (copie_src < copie_dest)
	{
		while (len--)
			copie_dest[len] = copie_src[len];
	}
	else
		ft_memcpy(copie_dest, copie_src, len);
	return (dest);
}
