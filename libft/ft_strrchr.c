/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpham <mpham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 17:02:54 by minh              #+#    #+#             */
/*   Updated: 2017/11/27 10:02:15 by mpham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strrchr(const char *s, int c)
{
	char	c2;
	char	*str;

	c2 = (char)c;
	str = (char *)s + ft_strlen(s);
	while (*str != c2)
	{
		if (str == s)
			return (NULL);
		str--;
	}
	return (str);
}
