/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minh <minh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 20:30:34 by minh              #+#    #+#             */
/*   Updated: 2018/01/09 20:43:17 by minh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_create_elem(void *data)
{
	t_list *elem;

	elem = (t_list*)malloc(sizeof(t_list));
	if (elem)
	{
		elem->next = 0;
		elem->content = data;
	}
	return (elem);
}