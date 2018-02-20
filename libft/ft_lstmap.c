/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minh <minh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 22:47:08 by minh              #+#    #+#             */
/*   Updated: 2017/11/27 09:21:29 by mpham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newliste;

	newliste = ft_lstnew(lst->content, lst->content_size);
	if (!newliste)
		return (NULL);
	newliste = f(lst);
	if (lst->next)
	{
		newliste->next = ft_lstmap(lst->next, f);
		if (newliste->next == NULL)
		{
			free(newliste);
			return (NULL);
		}
	}
	return (newliste);
}
