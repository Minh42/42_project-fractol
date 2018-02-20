/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minh <minh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 13:49:27 by minh              #+#    #+#             */
/*   Updated: 2017/11/27 10:02:31 by mpham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s)
{
	int	start;
	int	end;

	start = 0;
	if (!s)
		return (0);
	end = (ft_strlen((char *)s) - 1);
	while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
		start++;
	while (s[end] == ' ' || s[end] == '\n' || s[end] == '\t')
	{
		if (end == 0)
		{
			return ((char *)ft_memalloc(sizeof(char)));
		}
		end--;
	}
	return (ft_strsub(s, start, end - start + 1));
}
