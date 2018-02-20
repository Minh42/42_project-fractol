/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minh <minh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 17:16:53 by minh              #+#    #+#             */
/*   Updated: 2017/11/27 09:18:18 by mpham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int nbr)
{
	int		len;

	len = (nbr <= 0) ? 1 : 0;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	int			len;
	int			negatif;
	char		*string;

	negatif = ft_isnegative(n);
	len = ft_len(n);
	string = (char *)malloc(sizeof(char) * len + 1);
	if (!string)
		return (NULL);
	string[len] = '\0';
	len--;
	while (len >= 0)
	{
		string[len] = '0' + ft_abs(n % 10);
		n = ft_abs(n / 10);
		len--;
	}
	if (negatif == -1)
		string[0] = '-';
	return (string);
}
