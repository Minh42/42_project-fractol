/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpham <mpham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 19:08:18 by minh              #+#    #+#             */
/*   Updated: 2017/11/27 09:58:19 by mpham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(const char *s1, const char *s2, size_t n)
{
	int			i;
	const char	*str1;
	const char	*str2;

	i = 0;
	str1 = (char *)s1;
	str2 = (char *)s2;
	if (str1 == NULL || str2 == NULL)
		return (0);
	if (ft_strncmp(str1, str2, n) == 0)
		return (1);
	return (0);
}
