/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minh <minh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 17:23:36 by minh              #+#    #+#             */
/*   Updated: 2018/02/06 17:25:19 by minh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strspn(const char *str1, const char *str2)
{
	const char *s1;
	const char *s2;

    s1 = str1;
	while (*s1)
	{
		s2 = str2;
		while (1)
		{
			if (*s1 == *s2)
				break ;
			else if (*s2++ == '\0')
				return (s1 - str1);
		}
		s1++;
	}
	return (s1 - str1);
}