/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpham <mpham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 09:39:01 by mpham             #+#    #+#             */
/*   Updated: 2017/12/01 12:55:35 by mpham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		j;
	char	swap;

	i = 0;
	j = 0;
	while (str[i] != '\0')
		i++;
	i--;
	while (i > j)
	{
		swap = str[i];
		str[i] = str[j];
		str[j] = swap;
		i--;
		j++;
	}
	return (str);
}
