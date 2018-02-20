/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minh <minh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 16:45:04 by minh              #+#    #+#             */
/*   Updated: 2018/02/06 16:48:13 by minh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isalpha_string(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        if (ft_iswhitespace(str[i]))
            i++;; 
        if (ft_isalpha(str[i]))
            return (1);
        i++;
    }
    return (0);
}
