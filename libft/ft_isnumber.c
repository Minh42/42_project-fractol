/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minh <mpham@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 16:06:17 by minh              #+#    #+#             */
/*   Updated: 2018/02/06 16:06:18 by minh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isnumber(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        if (ft_iswhitespace(str[i]))
            return (0); 
        if (str[i] == '+' || str[i] == '-')
            i++;
        if (!ft_isdigit(str[i]))
            return (0);
        i++;
    }
    return (1);
}