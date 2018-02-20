/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpham <mpham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 18:38:55 by minh              #+#    #+#             */
/*   Updated: 2017/11/27 09:55:07 by mpham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;
	char			*string;

	i = 0;
	string = (char *)s;
	if (!s || !f)
		return (NULL);
	if (s == NULL && f == NULL)
		return (NULL);
	if (!(str = (char *)malloc(sizeof(*str) * (ft_strlen(s) + 1))))
		return (NULL);
	if (s && f)
	{
		while (string[i])
		{
			str[i] = f(i, string[i]);
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
