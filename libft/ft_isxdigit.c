/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isxdigit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minh <minh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 09:03:45 by minh              #+#    #+#             */
/*   Updated: 2018/02/13 09:05:42 by minh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int     ft_isxdigit(char *str)
 {
 	int		i;
 	char 	*hex;
 
 	i = 0;
 	if (ft_strlen(str) >= 10)
 	{
 		hex = ft_strsub(str, ft_strlen(str) - 6, 6);
 		if (ft_strspn(hex, "0123456789abcdefABCDEF") == 6 && ft_strstr(str, ",0x"))
 		return (1);
    }
    return (0);
 }